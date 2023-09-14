#include "CircuitBuilder.h"

std::unique_ptr<Circuit> CircuitBuilder::BuildFromStream(std::istream& input) {
    auto circuit = std::make_unique<Circuit>();
    std::string token;
    while (input >> token) {
        if (token == "component") {
            ProcessComponent(input, *circuit);
        } else if (token == "wire") {
            ProcessWire(input, *circuit);
        } else if (token == "connect") {
            ProcessConnect(input);
        } else if (token == "end") {
            break;
        } else {
            std::string dummyVar;
            std::getline(input, dummyVar);
        }
    }
    return circuit;
}

void CircuitBuilder::ProcessComponent(std::istream& input, Circuit& circuit) {
    std::string type, name;
    input >> type >> name;

    auto gate = Gate::Create(type, name);
    gateLookup[name] = gate.get();
    circuit.AddGate(std::move(gate));
}

void CircuitBuilder::ProcessWire(std::istream& input, Circuit& circuit) {
    std::string wireName;
    input >> wireName;

    auto wire = std::make_unique<Wire>(wireName);
    wireLookup[wireName] = wire.get();
    circuit.AddWire(std::move(wire));
}

void CircuitBuilder::ProcessConnect(std::istream& input) {
    std::string fromName, toName;
    int inputIndex;
    input >> fromName >> toName >> inputIndex;

    Gate* fromGate = gateLookup[fromName];
    Wire* toWire = wireLookup[toName];
    fromGate->OutputWire(toWire);
    if (inputIndex >= 0) {
        fromGate->InputWire(toWire, inputIndex);
    }
}
