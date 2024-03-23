# At LEAST 3.9 but newer is better
cmake_minimum_required(VERSION 3.9)

# Assign a name to the global project
project(dsp)

# Set the version of C/C++ (here C++17)
set(CMAKE_CXX_STANDARD 17)

# Include external dependencies, located in the folder lib (imported as a git submodule)
#add_subdirectory(lib)

# Indicate that the library math uses the header files within the folder include.
add_subdirectory(math)
add_subdirectory(app)
