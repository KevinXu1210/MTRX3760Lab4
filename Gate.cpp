// Purpose: Source file for Gate class
// 

#include "Gate.h"

bool ANDGate::compute(bool input1, bool input2) {
    return input1 && input2;
}

bool ORGate::compute(bool input1, bool input2) {
    return input1 || input2;
}

bool XORGate::compute(bool input1, bool input2) {
    return input1 ^ input2;
}

bool NORGate::compute(bool input1, bool input2) {
    return !(input1 || input2);
}