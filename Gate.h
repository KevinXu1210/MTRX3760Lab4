// Purpose: header file for Gate.cpp
// 

#ifndef _GATE_H_
#define _GATE_H_

// Abstract base class for all logic gates
class LogicGate {
public:
    virtual ~LogicGate() = default;  // Virtual destructor to allow derived classes to be deleted properly
    virtual bool compute(bool input1, bool input2) = 0; // Compute method to be overridden by derived classes
};

class ANDGate : public LogicGate {
public:
    bool compute(bool input1, bool input2) override;
};

class ORGate : public LogicGate {
public:
    bool compute(bool input1, bool input2) override;
};

class XORGate : public LogicGate {
public:
    bool compute(bool input1, bool input2) override;
};

class NORGate : public LogicGate {
public:
    bool compute(bool input1, bool input2) override;
};

#endif // _GATE_H_
