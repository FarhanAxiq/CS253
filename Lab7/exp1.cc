#include <iostream>
#include <cstdlib>			// C-strings: for strcpy()
using namespace std;


int main() {
    long double *a = new long double [10];
    delete[] a;
    return 0;
}