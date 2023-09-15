#ifndef _GATE_H_
#define _GATE_H_

#include "Wire.h"
#include <memory>
#include <vector>

class Gate {
public:
    Gate(std::string name);
    virtual ~Gate() = default;
    virtual void Compute() = 0;

    void OutputWire(Wire* wire);
    void InputWire(Wire* wire, int index);

    std::string Name() const;
    bool Output() const;

    static std::unique_ptr<Gate> Create(const std::string& type, const std::string& name);

protected:
    std::string name;
    bool output;
    std::vector<Wire*> inputWires;
    Wire* outputWire;
};

class ANDGate : public Gate {
public:
    ANDGate(std::string name);
    void Compute() override;
};

class ORGate : public Gate {
public:
    ORGate(std::string name);
    void Compute() override;
};

class XORGate : public Gate {
public:
    XORGate(std::string name);
    void Compute() override;
};

class NOTGate : public Gate {
public:
    NOTGate(std::string name);
    void Compute() override;
};

#endif // _GATE_H_
