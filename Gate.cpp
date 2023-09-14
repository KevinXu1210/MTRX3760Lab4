#include "Gate.h"

Gate::Gate(std::string name) : name(name), output(false), outputWire(nullptr) {}

void Gate::OutputWire(Wire* wire) {
    outputWire = wire;
}

void Gate::InputWire(Wire* wire, int index) {
    inputWires[index] = wire;
}

std::string Gate::Name() const {
    return name;
}

bool Gate::Output() const {
    return output;
}

std::unique_ptr<Gate> Gate::Create(const std::string& type, const std::string& name) {
    if (type == "AND") {
        return std::make_unique<ANDGate>(name);
    } else if (type == "OR") {
        return std::make_unique<ORGate>(name);
    } else if (type == "XOR") {
        return std::make_unique<XORGate>(name);
    } else if (type == "NOT") {
        return std::make_unique<NOTGate>(name);
    }
    throw std::invalid_argument("Unknown gate type");
}

ANDGate::ANDGate(std::string name) : Gate(name) {}

void ANDGate::Compute() {
    output = inputWires[0]->Value() && inputWires[1]->Value();
    outputWire->Assign(output);
}

ORGate::ORGate(std::string name) : Gate(name) {}

void ORGate::Compute() {
    output = inputWires[0]->Value() || inputWires[1]->Value();
    outputWire->Assign(output);
}

XORGate::XORGate(std::string name) : Gate(name) {}

void XORGate::Compute() {
    output = inputWires[0]->Value() ^ inputWires[1]->Value();
    outputWire->Assign(output);
}

NOTGate::NOTGate(std::string name) : Gate(name) {}

void NOTGate::Compute() {
    output = !inputWires[0]->Value();
    outputWire->Assign(output);
}
