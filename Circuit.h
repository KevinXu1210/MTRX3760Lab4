// This .h file contains the implementation of the Circuit class.
// The class takes a unique pointer to a Gate or Wire object
// as input and adds it to the gates or wires vector.
// The Circuit class has two public methods:
// AddGate and AddWire.
// These methods take a unique pointer to a Gate or Wire object
// as input and add it to the gates or wires vector.
// The Circuit class also has two private member variables:
// gates and wires.
// These member variables are used to store the gates and wires
// that are added to the circuit.


#ifndef _CIRCUIT_H_
#define _CIRCUIT_H_


#include "Gate.h"
#include "Wire.h"
#include <vector>
#include <memory>


// The Circuit class takes a unique pointer to a Gate or Wire object
// as input and adds it to the gates or wires vector.
class Circuit 
{

	public:

		// Takes a unique pointer to a Gate or Wire object
		void AddGate(std::unique_ptr<Gate> gate);
		void AddWire(std::unique_ptr<Wire> wire);

		// Evaluates the circuit
		void Evaluate();

		// Returns the gates and wires vectors
		std::vector<std::unique_ptr<Gate>>& Gates();
		std::vector<std::unique_ptr<Wire>>& Wires();

	private:

		// The gates and wires vectors are used to store the gates and wires
		// that are added to the circuit.
		std::vector<std::unique_ptr<Gate>> gates;
		std::vector<std::unique_ptr<Wire>> wires;

};


#endif // _CIRCUIT_H_
