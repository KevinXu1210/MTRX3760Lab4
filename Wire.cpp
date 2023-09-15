// This .cpp file contains the implementation of the Wire class.
// It takes a string as input and stores it in the name member variable.
// It also initializes the value member variable to false.


#include "Wire.h"


// Constructor that takes a string as input and stores it in the name member variable,
Wire::Wire(const std::string& wire_name) : name(wire_name) {}


// Returns the name and value member variables
bool Wire::Value() const 
{

	return value;

}


// Takes a bool as input and assigns it to the value member variable
void Wire::Assign(bool val) 
{

	value = val;

}


// Returns the name member variable
std::string Wire::Name() const 
{

	return name;

}
