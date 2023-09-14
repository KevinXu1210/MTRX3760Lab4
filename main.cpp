#include "CircuitBuilder.h"
#include "Circuit.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    // Check for correct command line arguments
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <circuit_description_file>" << std::endl;
        return 1;
    }

    // Open the circuit description file
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << argv[1] << std::endl;
        return 1;
    }

    try {
        // Use CircuitBuilder to construct the Circuit from the file
        CircuitBuilder builder;
        Circuit* circuit = builder.buildCircuit(inputFile);

        // Simulate the circuit (for this example, we'll just call a simulate function)
        // You can expand this to allow user-defined inputs or other functionality
        circuit->simulate();

        // Display the results (or do any other post-simulation tasks)
        circuit->displayResults();

        // Clean up
        delete circuit;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
