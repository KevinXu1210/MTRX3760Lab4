// This .h file contains the CircuitBuilder class, which is used 
// to build a circuit from a stream.
// It takes a file stream as input and returns 
// a unique pointer to a Circuit object.
// The CircuitBuilder class has three private member variables
// that are used to store the gates and wires that are created
// while building the circuit.


#ifndef _CIRCUITBUILDER_H_
#define _CIRCUITBUILDER_H_


#include "Circuit.h"
#include "Gate.h"
#include "Wire.h"
#include <istream>
#include <unordered_map>


class CircuitBuilder 
{

	public:

		// The BuildFromStream method takes a file stream as input and
		// returns a unique pointer to a Circuit object.
		std::unique_ptr<Circuit> BuildFromStream(std::istream& input);

	private:

		// It reads the type and name of the gate and creates a new
		// gate using the Gate::Create method.
		void ProcessComponent(std::istream& input, Circuit& circuit);

		// It reads the name of the wire and creates a new wire.
		void ProcessWire(std::istream& input, Circuit& circuit);

		// It reads the name of the gate and wire and the index of the
		// input wire and connects them.
		void ProcessConnect(std::istream& input);

		// The gateLookup and wireLookup member variables are used to store
		// the gates and wires that are created while building the circuit.
		std::unordered_map<std::string, Gate*> gateLookup;
		std::unordered_map<std::string, Wire*> wireLookup;

};


#endif // _CIRCUITBUILDER_H_
