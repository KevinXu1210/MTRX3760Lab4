#pragma once
#include <vector>
#include "Gate.h"
#include "Wire.h"

class Circuit {
    std::vector<Gate*> gates;
    std::vector<Wire*> wires;

public:
    void addGate(Gate* gate);
    void addWire(Wire* wire);
    void evaluateCircuit();
};
