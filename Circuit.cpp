#include "Circuit.h"

Circuit::Circuit() {}

void Circuit::addGate(std::unique_ptr<Gate> gate) {
    gates.push_back(std::move(gate));
}

void Circuit::addWire(std::unique_ptr<Wire> wire) {
    wires.push_back(std::move(wire));
}

void Circuit::connectGateToWire(Gate* gate, Wire* wire) {
    gate->setOutputWire(wire);
}

void Circuit::connectWireToGate(Wire* wire, Gate* gate, int inputIndex) {
    gate->setInputWire(wire, inputIndex);
}

void Circuit::evaluate() {
    // In this simple example, we assume a topological order of gates.
    // In a more advanced scenario, you'd need a mechanism to determine the correct evaluation order.
    for (const auto& gate : gates) {
        gate->compute();
    }
}
