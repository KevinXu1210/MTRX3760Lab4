// This .cpp file contains the implementation of the Gate class.
// It takes a string as input and stores it in the name member variable.
// It also initializes the output member variable to false.


#include "Gate.h"


// Constructor that takes a string as input and stores it in the name member variable,
// and initializes the output member variable to false,
// and initializes the outputWire member variable to nullptr
Gate::Gate(std::string name) : name(name), output(false), outputWire(nullptr) {} 


// Takes a pointer to a Wire object
void Gate::OutputWire(Wire* wire) 
{

	// Adds it to the outputWire member variable
	outputWire = wire;

}


// Takes a pointer to a Wire object and an integer
void Gate::InputWire(Wire* wire, int index) 
{

	// Adds it to the inputWires member variable
	inputWires[index] = wire;

}


// Returns the name and output member variables
std::string Gate::Name() const 
{

	// Returns the name member variable
	return name;

}


// Returns the name and output member variables
bool Gate::Output() const 
{

	// Returns the output member variable
	return output;

}


// Takes a string as input and returns a unique pointer
std::unique_ptr<Gate> Gate::Create(const std::string& type, const std::string& name) 
{

	// Creates a new gate object
	if (type == "AND") 
	{

		// Returns a unique pointer to the gate object
		return std::make_unique<ANDGate>(name);

	} 
	else if (type == "OR") 
	{

		// Returns a unique pointer to the gate object
		return std::make_unique<ORGate>(name);

	} 
	else if (type == "XOR") 
	{

		// Returns a unique pointer to the gate object
		return std::make_unique<XORGate>(name);

	} 
	else if (type == "NOT") 
	{

		// Returns a unique pointer to the gate object
		return std::make_unique<NOTGate>(name);

	}

	// If the type is not one of the above, throw an exception
	throw std::invalid_argument("Unknown gate type");

}


// The ANDGate class represents an AND gate.
ANDGate::ANDGate(std::string name) : Gate(name) {}


// Computes the output of the gate
void ANDGate::Compute() 
{

	// Computes the output of the gate
	output = inputWires[0]->Value() && inputWires[1]->Value();

	// Assigns the output to the outputWire
	outputWire->Assign(output);

}


// The ORGate class represents an OR gate.
ORGate::ORGate(std::string name) : Gate(name) {}


// Computes the output of the gate
void ORGate::Compute() 
{

	// Computes the output of the gate
	output = inputWires[0]->Value() || inputWires[1]->Value();

	// Assigns the output to the outputWire
	outputWire->Assign(output);

}


// The XORGate class represents an XOR gate.
XORGate::XORGate(std::string name) : Gate(name) {}


// Computes the output of the gate
void XORGate::Compute() 
{

	// Computes the output of the gate
	output = inputWires[0]->Value() ^ inputWires[1]->Value();

	// Assigns the output to the outputWire
	outputWire->Assign(output);

}


// The NOTGate class represents a NOT gate.
NOTGate::NOTGate(std::string name) : Gate(name) {}


// Computes the output of the gate
void NOTGate::Compute() 
{

	// Computes the output of the gate
	output = !inputWires[0]->Value();

	// Assigns the output to the outputWire
	outputWire->Assign(output);

}
