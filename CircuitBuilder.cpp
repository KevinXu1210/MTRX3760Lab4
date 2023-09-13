#include "CircuitBuilder.h"

CircuitBuilder::CircuitBuilder() {}

std::unique_ptr<Circuit> CircuitBuilder::buildFromStream(std::istream& input) {
    auto circuit = std::make_unique<Circuit>();

    std::string token;
    while (input >> token) {
        if (token == "component") {
            processComponent(input, *circuit);
        } else if (token == "wire") {
            processWire(input, *circuit);
        } else if (token == "connect") {
            processConnect(input);
        } else if (token == "end") {
            break;
        } else {
            // Skip unrecognized tokens
            std::string dummyVar;
            std::getline(input, dummyVar);
        }
    }

    return circuit;
}

void CircuitBuilder::processComponent(std::istream& input, Circuit& circuit) {
    std::string type, name;
    input >> type >> name;

    std::unique_ptr<Gate> gate = Gate::create(type, name);
    gateLookup[name] = gate.get();
    circuit.addGate(std::move(gate));
}

void CircuitBuilder::processWire(std::istream& input, Circuit& circuit) {
    std::string wireName;
    input >> wireName;

    auto wire = std::make_unique<Wire>(wireName);
    wireLookup[wireName] = wire.get();
    circuit.addWire(std::move(wire));
}

void CircuitBuilder::processConnect(std::istream& input) {
    std::string fromName, toName;
    int inputIndex;
    input >> fromName >> toName >> inputIndex;

    Gate* fromGate = gateLookup[fromName];
    Wire* toWire = wireLookup[toName];
    fromGate->setOutputWire(toWire);
    toWire->setInputGate(fromGate, inputIndex);
}
