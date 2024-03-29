//
//  HW3
//  hw3.cc
//  Farhan Haziq
//  fargah1@cs.colostate.edu
//  for testing
//

#include <iostream> 
#include <string>
#include "Lexan.h"
#include "Lexan.h" 

int main()
{
     // const auto prog = R"(
     //     a\n≠\nb\nb\n≤\nc\nd\n≥\nz\na,≠,b,b,≤,c,d,≥,z\\n )";
        const auto prog = R"(
# Celsius to Fahrenheit converter
#
# Input: First argument, A, contains Celsius temperature
# Output: return Fahrenheit temperature
#
# °F = °C × 9/5 + 32
# 100°C = 212°F
#  30°C = 86°F
#  20°C = 68°F
#  10°C = 50°F
#   0°C = 32°F
 
A *= 9 A /= 5   # °C × 9/5
 a+=0032        # °C × 9/5 + 32
F = A           # Put it in F for Fahrenheit
 
Z = 0           # Constants have no sign, so compute a negative number.
Z -= 459        # absolute zero (should really be −459.67°)
 
if F ≤ Z        # If temperature is too low:
    F=Z         #  Make it absolute zero.
fi
        )";
    const Lexan lex(prog);
    for (size_t i = 0; i < lex.size(); i++){
         std::cout << lex[i] << '\n';
    }
    std::cout << lex << '\n';
    return 0;
}