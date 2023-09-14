#ifndef _CIRCUIT_H_
#define _CIRCUIT_H_

#include "Gate.h"
#include "Wire.h"
#include <vector>
#include <memory>

class Circuit {
public:
    void AddGate(std::unique_ptr<Gate> gate);
    void AddWire(std::unique_ptr<Wire> wire);
    void Evaluate();
    std::vector<std::unique_ptr<Gate>>& Gates();
    std::vector<std::unique_ptr<Wire>>& Wires();

private:
    std::vector<std::unique_ptr<Gate>> gates;
    std::vector<std::unique_ptr<Wire>> wires;
};

#endif // _CIRCUIT_H_
