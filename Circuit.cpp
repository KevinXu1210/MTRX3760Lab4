#include "Circuit.h"

void Circuit::AddGate(std::unique_ptr<Gate> gate) {
    gates.push_back(std::move(gate));
}

void Circuit::AddWire(std::unique_ptr<Wire> wire) {
    wires.push_back(std::move(wire));
}

void Circuit::Evaluate() {
    for (const auto& gate : gates) {
        gate->Compute();
    }
}

std::vector<std::unique_ptr<Gate>>& Circuit::Gates() {
    return gates;
}

std::vector<std::unique_ptr<Wire>>& Circuit::Wires() {
    return wires;
}
