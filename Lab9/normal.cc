#include <iostream>
#include <chrono> 

using namespace std;
using namespace std::chrono; 

class Foo {
  public:
    double datum;
};

int main() {
    auto start = high_resolution_clock::now(); 
    cout << "sizeof(double) = " << sizeof(double) << '\n' << "sizeof(Foo) = " << sizeof(Foo) << '\n';
    Foo *p = new Foo;
    Foo *q = new Foo;
    cout << "p=" << p << '\n'
	 << "q=" << q << '\n';
    delete p;
    delete q;
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
    return 0;
}
