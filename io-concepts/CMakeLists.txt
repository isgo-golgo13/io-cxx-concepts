# Create a library target called io-concepts
add_library(io-concepts INTERFACE)

# Specify the include directory for this library
target_include_directories(io-concepts
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# # Add the source files for the shared library
# target_sources(io-concepts
#     PRIVATE
#     include/io-concepts.hpp
# )
