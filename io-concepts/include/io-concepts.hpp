#ifndef IO_CONCEPTS_HPP
#define IO_CONCEPTS_HPP

#include <concepts>
#include <cstddef>
#include <fstream>
#include <string>
#include <iostream>

// Define the Writer concept
template<typename T>
concept Writer = requires(T writer, const char* data, std::size_t size) {
    { writer.write(data, size) } -> std::same_as<void>;
};

// Define the Reader concept
template<typename T>
concept Reader = requires(T reader, char* buffer, std::size_t size) {
    { reader.read(buffer, size) } -> std::convertible_to<std::size_t>;
};

// Define the processData function
template<Writer W, Reader R>
void processData(W& writer, R& reader) {
    char buffer[1024];
    std::size_t bytesRead = reader.read(buffer, sizeof(buffer));
    writer.write(buffer, bytesRead);
}

// FileWriter implementation for Writer
class FileWriter {
public:
    explicit FileWriter(const std::string& filename) {
        file.open(filename, std::ios::out);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file for writing");
        }
    }

    ~FileWriter() {
        if (file.is_open()) {
            file.close();
        }
    }

    void write(const char* data, std::size_t size) {
        file.write(data, size);
        file.flush();  // Ensure the data is written to disk immediately
    }

private:
    std::ofstream file;
};

// FileReader implementation for Reader
class FileReader {
public:
    explicit FileReader(const std::string& filename) {
        file.open(filename, std::ios::in);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file for reading");
        }
    }

    ~FileReader() {
        if (file.is_open()) {
            file.close();
        }
    }

    std::size_t read(char* buffer, std::size_t size) {
        if (!file.good()) return 0;  // Return 0 if the file is in a bad state
        file.read(buffer, size);
        return file.gcount();  // Return the number of bytes read
    }

private:
    std::ifstream file;
};

#endif // IO_CONCEPTS_HPP
