cmake_minimum_required(VERSION 3.14)
project(ConceptsIO)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the subdirectory that will create the shared library
add_subdirectory(io-concepts)

# Add the main executable and link it to the shared library
add_executable(main main.cpp)

# Link the io-concepts shared library to the main executable
target_link_libraries(main PUBLIC io-concepts)
