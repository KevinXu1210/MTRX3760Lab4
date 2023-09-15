// This .h file contains the implementation of the Gate class.
// It takes a string as input and stores it in the name member variable.
// It also initializes the output member variable to false.


#ifndef _GATE_H_
#define _GATE_H_


#include "Wire.h"
#include <memory>
#include <vector>


// The Gate class is an abstract class that represents a gate.
// It has two public methods:
// OutputWire and InputWire.
// These methods take a pointer to a Wire object as input and
// add it to the inputWires or outputWire member variables.
// The Gate class also has two protected member variables:
// inputWires and outputWire.
// These member variables are used to store the input and output wires
// of the gate.
// The Gate class also has two protected member variables:
// name and output.
// The name member variable is used to store the name of the gate.
// The output member variable is used to store the output of the gate.
// The Gate class also has a static Create method.
// This method takes a string as input and returns a unique pointer
// to a Gate object.
// The Create method is used to create a new gate object.
class Gate 
{

	public:

		// Constructor
    Gate(std::string name);

		// Destructor
    virtual ~Gate() = default;

		// Initializes the output member variable to false
    virtual void Compute() = 0;

		// Takes a pointer to a Wire object
    void OutputWire(Wire* wire);

		// Takes a pointer to a Wire object and an integer
    void InputWire(Wire* wire, int index);

		// Returns the name and output member variables
    std::string Name() const;

    bool Output() const;

		// Takes a string as input and returns a unique pointer
    static std::unique_ptr<Gate> Create(const std::string& type, const std::string& name);

	protected:

		// Name
    std::string name;

		// Output 
    bool output;

		// Input wires
    std::vector<Wire*> inputWires;

		// Output wire
    Wire* outputWire;
};


// The ANDGate class represents an AND gate.
class ANDGate : public Gate 
{

	public:

		// Constructor
    ANDGate(std::string name);

		// Computes the output of the gate
    void Compute() override;

};


// The ORGate class represents an OR gate.
class ORGate : public Gate 
{

	public:

		// Constructor
    ORGate(std::string name);

		// Computes the output of the gate
    void Compute() override;

};


// The XORGate class represents an XOR gate.
class XORGate : public Gate 
{

	public:

		// Constructor
    XORGate(std::string name);

		// Computes the output of the gate
    void Compute() override;

};


// The NOTGate class represents a NOT gate.
class NOTGate : public Gate 
{

	public:

		// Constructor
    NOTGate(std::string name);

		// Computes the output of the gate
    void Compute() override;

};


#endif // _GATE_H_
