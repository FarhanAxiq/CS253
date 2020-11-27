//
//  HW6
//  test.cc
//  Farhan Haziq
//

#include "Board.h"
#include "Rule.h"
#include "Board.h"
#include "Rule.h"
#include <iostream>
#include <cassert>
 
using namespace std;
 
int main() {
     Rule r;
    assert(r.golly() == "B3/S23");
    r.golly("B1357/S2468");
    assert(r.golly() == "B1357/S2468");
    Board g1("test", r, '@', '`');
 
    cout << g1 << '\n';
    cout << ++g1 << '\n';
    cout << ++g1 << "\n\n";
 
    r.conway();
    assert(r.golly() == "B3/S23");
    Board g2("test2", r);
    cout << g2 << '\n';
    cout << ++g2 << '\n';
    cout << ++g2 << "\n\n";

    Board g3("test3"); 
    for (int i=0; i<500; i++)
        ++g3;
    cout << g3;
}