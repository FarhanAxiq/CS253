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

int main(int argc, char *argv[])
{
	 const auto prog = R"(
        n  = a n += b C/=123 # z=zz
 
        ifn≤3returN1FI)";
    const Lexan lex(prog);
    for (size_t i = 0; i < lex.size(); i++){
         std::cout << lex[i] << '\n';
    }
    std::cout << lex << '\n';
    return 0;
}