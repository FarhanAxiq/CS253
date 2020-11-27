//
//  HW5
//  test.cc
//  Farhan Haziq
//  fargah1@cs.colostate.edu
//  2020 October 10
//

#include "Jail.h"
#include "Jail.h"
#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
 
int main() {
    ifstream in("test");
    if (!in) {
        cerr << "can't open ctof for reading\n";
        return 1;
    }
    string prog;
    getline(in, prog, '\0');
 
    try {
        Jail j(prog);
        // 100 is the boiling point of water
        // 30 is hot
        // 20 is nice
        // 10 is cool
        // and 0 is ice
        for (int celsius : {100, 30, 20, 10, 0})
            cout << celsius << "°C = " << j.run(celsius) << "°F\n";
 
        cout << "π ≈ ";
        Jail("n=999999999999999n/=31830989printn").run();
        Jail bad("🐟");
    }
    catch (const exception &e) {
        cerr << "Caught error: " << e.what() << '\n';
    }
    return 0;
}