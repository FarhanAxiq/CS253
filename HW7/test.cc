#include "Board.h"
#include "Rule.h"
#include <iostream>
 
using namespace std;
 
int main() {
    Rule r;
    r.jail(R"(# Conway’s rule in JAIL
              # A B C
              # D E F
              # G H I
              # Accumulate count in C:
              c += a c += b c += d c += f
              c += g c += h c += i
              if C = 2 return E fi  # Two neighbors means survive
              if C = 3 return 1 fi  # Three neighbors mean born or survive
              return 0              # Death otherwise
              )");
    Board b("blinker", r);
    cout << b << '\n';
    for (int i=0; i<3; i++)
        cout << ++b << '\n';
 
    r.jail("return a # move down to the right");                    
    Board b3("block3", '*', '\'', r);
    cout << b3 << '\n';
    for (int i=0; i<3; i++)
        cout << ++b3 << '\n';
}