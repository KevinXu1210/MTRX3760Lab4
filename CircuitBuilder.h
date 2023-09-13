#ifndef _CIRCUITBUILDER_H_
#define _CIRCUITBUILDER_H_

#include <iostream>
#include <string>
#include <map>
#include "Circuit.h"
#include "Gate.h"
#include "Wire.h"

class CircuitBuilder {
public:
    CircuitBuilder();
    
    // Parse the input stream and build the circuit
    std::unique_ptr<Circuit> buildFromStream(std::istream& input);

private:
    std::map<std::string, Gate*> gateLookup;
    std::map<std::string, Wire*> wireLookup;

    // Helper functions to process different parts of the input
    void processComponent(std::istream& input, Circuit& circuit);
    void processWire(std::istream& input, Circuit& circuit);
    void processConnect(std::istream& input);
};

#endif // _CIRCUITBUILDER_H_
