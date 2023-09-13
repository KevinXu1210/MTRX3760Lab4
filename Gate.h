#pragma once
#include <string>

class Gate {
protected:
    std::string name;
    bool output;

public:
    Gate(std::string n) : name(n), output(false) {}
    virtual ~Gate() = default;
    virtual bool getOutput() = 0;
    void setName(const std::string& n) { name = n; }
    std::string getName() const { return name; }
};
