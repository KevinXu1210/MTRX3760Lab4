// 


#include "CircuitBuilder.h"
#include "Circuit.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <circuit_description_file>" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << argv[1] << std::endl;
        return 1;
    }

    try {
        CircuitBuilder builder;
        auto circuit = builder.BuildFromStream(inputFile);

        circuit->Evaluate();

        for (const auto& gate : circuit->Gates()) {
            std::cout << "Gate " << gate->Name() << " output: " << gate->Output() << std::endl;
        }

        for (const auto& wire : circuit->Wires()) {
            std::cout << "Wire " << wire->Name() << " value: " << wire->Value() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
