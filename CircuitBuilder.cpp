// This .cpp file contains the implementation of the CircuitBuilder class.


#include "CircuitBuilder.h"


// The BuildFromStream method takes a file stream as input and
// returns a unique pointer to a Circuit object.
std::unique_ptr<Circuit> CircuitBuilder::BuildFromStream(std::istream& input) 
{
	
	// Create a unique pointer to a Circuit object
	auto circuit = std::make_unique<Circuit>();

	// Read the file stream line by line
	std::string token;

	while (input >> token) 
	{
		
		if (token == "component") 						// If the token is "component",
		{

			ProcessComponent(input, *circuit);  // call the ProcessComponent method

		}
		else if (token == "wire") 						// If the token is "wire",
		{

			ProcessWire(input, *circuit);				// call the ProcessWire method

		} 
		else if (token == "connect") 					// If the token is "connect",
		{

			ProcessConnect(input);							// call the ProcessConnect method

		} 
		else if (token == "end") 
		{

				break;

		} 
		else {																// If the token is not one of the above,

			std::string dummyVar;								// read the rest of the line and ignore it

			std::getline(input, dummyVar);

		}

	}

	return circuit;

}


// It reads the type and name of the gate and creates a new
// gate using the Gate::Create method.
void CircuitBuilder::ProcessComponent(std::istream& input, Circuit& circuit) 
{

	// Read the type and name of the gate
	std::string type, name;

	// Create a new gate using the Gate::Create method
	input >> type >> name;

	// Create a unique pointer to a Gate object
	auto gate = Gate::Create(type, name);

	// Store the gate in the gateLookup map
	gateLookup[name] = gate.get();

	// Add the gate to the circuit
	circuit.AddGate(std::move(gate));

}


// It reads the name of the wire and creates a new wire.
void CircuitBuilder::ProcessWire(std::istream& input, Circuit& circuit) 
{

	// Read the name of the wire
	std::string wireName;

	// Create a new wire
	input >> wireName;

	// Create a unique pointer to a Wire object
	auto wire = std::make_unique<Wire>(wireName);

	// Store the wire in the wireLookup map
	wireLookup[wireName] = wire.get(); 

	// Add the wire to the circuit
	circuit.AddWire(std::move(wire));
	
}


// It reads the name of the gate and wire and the index of the
// input wire and connects them.
void CircuitBuilder::ProcessConnect(std::istream& input) 
{
	
	// Read the name of the gate and wire and the index of the
	// input wire
	std::string fromName, toName;

	int inputIndex;

	// Connect the gate and wire
	input >> fromName >> toName >> inputIndex;

	// Get the gate and wire from the gateLookup and wireLookup maps
	Gate* fromGate = gateLookup[fromName];
	Wire* toWire   = wireLookup[toName];

	// Connect the gate and wire
	fromGate->OutputWire(toWire);

	// Check if the inputIndex is greater than or equal to 0
	if (inputIndex >= 0) 
	{

		// Connect the gate and wire
		fromGate->InputWire(toWire, inputIndex);

	}

}
