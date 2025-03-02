// A simple program that computes the inverse square root of a number
// Adapted from: https://cmake.org

// Standard library headers
#include <cmath>
#include <iostream>
#include <string>
// Header to our small math library
#include "MathFunctions.h"

// argc = the number of arguments, including the name of the executable
// argv = arguments as an array of c-strings, e.g. ["invsqrt", "9"]
int main(int argc, const char* argv[])
{
    if (argc < 2)
    {
        std::cout << "No number to take the inverse square root of!" << std::endl;
        return 1;
    }
    
    // Convert input to float
    const float input = std::stof(argv[1]);
    // Compute inverse square root
    const float invsqrt = Q_rsqrt(input);
    
    // Print results
    std::cout << "The inverse square root of " << input;
    std::cout << " is " << invsqrt << std::endl;
    
    return 0;
}
