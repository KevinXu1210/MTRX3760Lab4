#ifndef _CIRCUITBUILDER_H_
#define _CIRCUITBUILDER_H_

#include "Circuit.h"
#include "Gate.h"
#include "Wire.h"
#include <istream>
#include <unordered_map>

class CircuitBuilder {
public:
    std::unique_ptr<Circuit> BuildFromStream(std::istream& input);

private:
    void ProcessComponent(std::istream& input, Circuit& circuit);
    void ProcessWire(std::istream& input, Circuit& circuit);
    void ProcessConnect(std::istream& input);

    std::unordered_map<std::string, Gate*> gateLookup;
    std::unordered_map<std::string, Wire*> wireLookup;
};

#endif // _CIRCUITBUILDER_H_
