// This .h file contains the implementation of the Wire class.
// It takes a string as input and stores it in the name member variable.
// It also initializes the value member variable to false.


#ifndef _WIRE_H_
#define _WIRE_H_


#include <string>


// The Wire class represents a wire.
class Wire 
{

	public:

		// Constructor
		explicit Wire(const std::string& wire_name);

		// Returns the name and value member variables
		bool Value() const;

		// Takes a bool as input and assigns it to the value member variable
		void Assign(bool val);

		// Returns the name member variable
		std::string Name() const;

	private:

		// The name and value member variables are used to store the name and value
		std::string name;

		// The value member variable is used to store the value of the wire
		bool value = false;

};

#endif // _WIRE_H_
