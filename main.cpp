// MTRX3760 Lab 4
// Main program for testing the circuit builder.

// This program takes a circuit description file 
// as a command line argument and prints the 
// output of each gate and the value of each wire
// to the console.

// The program includes the necessary header files. 
// The first two are custom classes, 
// while the last two are standard C++ libraries 
// for input/output and file handling.
#include "CircuitBuilder.h"
#include "Circuit.h"
#include <iostream>
#include <fstream>


// The main function takes a single command line argument,
// which is the name of the circuit description file.
// The function opens the file and passes it to the
// CircuitBuilder class to build the circuit.
// The function then prints the output of each gate
// and the value of each wire to the console.
int main(int argc, char* argv[]) {

	// Check if the correct number of command line arguments was given
	if (argc != 2) 
	{

		// Print error message
		std::cerr << "Usage: " << argv[0] 
		<< " <circuit_description_file>" << std::endl;

		return 1;

	}

	// Open the file
	std::ifstream inputFile(argv[1]);

	// Check if the file was opened successfully
	if (!inputFile.is_open()) 
	{

		// Print error message
		std::cerr << "Error opening file: " << argv[1] 
		<< std::endl;

		return 1;

	}

	// Build the circuit
	try {

		// Create a CircuitBuilder object
		CircuitBuilder builder;

		// Calls the BuildFromStream method 
		// of the CircuitBuilder to construct a circuit 
		// based on the description in the input file.
		auto circuit = builder.BuildFromStream(inputFile); 
		
		// Calls the Evaluate method of the constructed circuit 
		// to simulate it.
		circuit->Evaluate();

		// Print the output of each gate
		for (const auto& gate : circuit->Gates()) 
		{

			std::cout << "Gate " << gate->Name() << " output: " 
			<< gate->Output() << std::endl;

		}

		// Print the value of each wire
		for (const auto& wire : circuit->Wires()) 
		{

			std::cout << "Wire " << wire->Name() << " value: " 
			<< wire->Value() << std::endl;

		}

	} 
	
	// Catch any exceptions thrown by the CircuitBuilder
	catch (const std::exception& e) 
	{

    // Print error message
		std::cerr << "Error: " << e.what() << std::endl;

		return 1;

	}

	return 0;

}
