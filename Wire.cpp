#include "Wire.h"

Wire::Wire(const std::string& wire_name) : name(wire_name) {}

bool Wire::Value() const {
    return value;
}

void Wire::Assign(bool val) {
    value = val;
}

std::string Wire::Name() const {
    return name;
}
