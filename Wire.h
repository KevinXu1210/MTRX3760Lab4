#pragma once
#include "Gate.h"

class Wire {
    Gate* source;
    Gate* target;

public:
    Wire(Gate* s, Gate* t) : source(s), target(t) {}
    void transmitSignal();
};
