#include <iostream>
#include "io-concepts.hpp"

int main() {
    try {
        // File to read from and write to
        FileReader reader("../file-data.txt");
        FileWriter writer("../output.txt");

        // Process the file data and write to the output file
        processData(writer, reader);

        std::cout << "Data processing complete. Check 'output.txt' for results." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
