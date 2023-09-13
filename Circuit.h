#ifndef _CIRCUIT_H_
#define _CIRCUIT_H_

#include <vector>
#include <memory>
#include "Gate.h"
#include "Wire.h"

class Circuit {
public:
    Circuit();

    // Methods to add components
    void addGate(std::unique_ptr<Gate> gate);
    void addWire(std::unique_ptr<Wire> wire);

    // Connect a gate's output to a wire
    void connectGateToWire(Gate* gate, Wire* wire);

    // Connect a wire to a gate's input
    void connectWireToGate(Wire* wire, Gate* gate, int inputIndex);

    // Evaluate the circuit
    void evaluate();

private:
    std::vector<std::unique_ptr<Gate>> gates;
    std::vector<std::unique_ptr<Wire>> wires;
};

#endif // _CIRCUIT_H_
