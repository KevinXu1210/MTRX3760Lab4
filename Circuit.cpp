// This .cpp file contains the implementation of the Circuit class.
// The class takes a unique pointer to a Gate or Wire object
// as input and adds it to the gates or wires vector.


#include "Circuit.h"


// Takes a unique pointer to a Gate object
void Circuit::AddGate(std::unique_ptr<Gate> gate) 
{

	// Adds it to the gates vector
	gates.push_back(std::move(gate));

}


// Takes a unique pointer to a Wire object
void Circuit::AddWire(std::unique_ptr<Wire> wire) 
{
	
	// Adds it to the wires vector
	wires.push_back(std::move(wire));

}


// Evaluates the circuit
void Circuit::Evaluate()
{

	// Calls the Compute method of each gate
	for (const auto& gate : gates) 
	{

		// Calls the Compute method of each gate
		gate->Compute();

	}

}


// Returns the gates vectors
std::vector<std::unique_ptr<Gate>>& Circuit::Gates() 
{

	return gates;

}


// Returns the wires vectors
std::vector<std::unique_ptr<Wire>>& Circuit::Wires() 
{

	return wires;

}
