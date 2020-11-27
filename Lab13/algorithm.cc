//
//  algorithm.cc
//  Lab 13
//  Farhan Haziq
//


#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    vector<short> pi = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4};
    string alpha="abcdefghijklmnopqrstuvwxyz", digits="0123456789";
    char cbuf[100] = {'\0'};	// contains 100 zero chars
    list<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    short powers[] = {1,2,4,8,16,32,64};
    int ibuf[100];
    // Ex 0
    cout << "Exercise 0\n";
    copy(alpha.begin(), alpha.end(), cbuf);
    cout << cbuf << '\n';
    // Ex 1
    cout << "Exercise 1\n";
    reverse(cbuf, &cbuf[strlen(cbuf)]);
    cout << cbuf << '\n';
    // Ex 2
    cout << "Exercise 2\n";
    transform(primes.begin(), primes.end(), ibuf,
             [](int n){ return ++n; });
    for (int i = 0; i < 10; i++){ cout << ibuf[i] << " "; } cout << '\n';
    // Ex 3
    cout << "Exercise 3\n";
    if(any_of(primes.begin(), primes.end(), 
        [](int n){ 
            if (n % 2 == 0){
                cout << "div 2\n";
                return n % 2 == 0;
            }
            if (n % 3 == 0 && n % 7 == 0){
                cout << "div 42\n";
                return n % 2 == 0 && n % 21 == 0;
            }
            else
                return false;
        })){
    }
    // Ex 4
    cout << "Exercise 4\n";
    auto found = find(begin(primes), end(primes), 13);
    found++;
    while (found != primes.end()){
        cout << *found << ' ';
        ++found;
    }
    cout << '\n';
    // Ex 5 
    cout << "Exercise 5\n";
    cout << "The number 3 appears " << count(pi.begin(), pi.end(), 3) << " times in pi" << '\n';
    // Ex 6
    cout << "Exercise 6\n";
    cout << "There is " << count_if(pi.begin(), pi.end(), [](int i){ return i < 5; }) << " numbers that is less than 5." << '\n';
    // Ex 7
    cout << "Exercise 7\n";
    auto result = max_element(pi.begin(), pi.end());
    auto cont = distance(pi.begin(), result);
    cout << "Max value in pi is at " << cont << " which is : " << pi[cont] << '\n';
    // Ex 8
    cout << "Exercise 8\n";
    sort(pi.begin(), pi.end());
    for (auto &i : pi){ cout << i << " "; } cout << '\n';
    // Ex 9
    cout << "Exercise 9\n";
    auto low = lower_bound(pi.begin(), pi.end(), 7);
    auto elem = low - pi.begin();
    cout << "lower bound in pi is at : " << elem << " which is " << pi[elem] << '\n';
    // Ex 10
    cout << "Exercise 10\n";
    cout << "intersecting number are:\n";
    vector<int> intersect;
    set_intersection(pi.begin(), pi.end(), powers, powers + (sizeof(powers) / sizeof(powers[0])), back_inserter(intersect));
    for (auto &k : intersect){ cout << k << ' '; } cout << '\n';
    return 0;
}