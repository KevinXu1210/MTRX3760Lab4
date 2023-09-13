#include "Wire.h"

Wire::Wire() : currentSignal(false) {}  // By default, the wire signal is initialized to 0 (false)

bool Wire::getSignal() const {
    return currentSignal;
}

void Wire::setSignal(bool signal) {
    currentSignal = signal;
}
