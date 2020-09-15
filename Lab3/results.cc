//
//  results.cc
//  Farhan Haziq
//  Lab 3
//  2020/09/09
//  fargah1@cs.colostate.edu
//


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>

std::set<char> copy(std::multiset<char> &c)
{
    std::set<char> copy(c.cbegin(), c.cend());
    return copy;
}

std::multiset<char> mult(std::string &read)
{
    std::multiset<char> t;
    for (char &x : read){
        t.emplace(x);
    }
    return t;
}

std::string stringing(std::string &filename)
{
    char c;
    std::string buff;
    std::ifstream infile(filename);
    if (!(infile.is_open())){
        std::cerr << "File not found\n";
        exit(1);
    }
    while (infile.get(c)){
        buff += c;
    }

    return buff;
}

void vect()
{
    int input;
    std::vector<int> in;
    std::cout << "Enter a number, enter 0 to stop\n";
    while (std::cin >> input && input != 0){
        in.push_back(input);  
    }

    for (auto &i : in){
        std::cout << "Printing: " << i << std::endl;
    }
}

void print(std::string &x, std::set<char> &y, std::multiset<char> &z)
{
    std::cout << "The size of string: " << x.size() << '\n';
    std::cout << "The size of set: " << y.size() << '\n';
    std::cout << "The size of multichar: " << z.size() << '\n';
    // Q7: THe reason the size are different is because in multiset and string, it keep the character around
    // while in set, it remove duplicate and keep unique elements
    // hence reduction in number of length in set
}

int main(int argc, char *argv[])
{
    vect();
    std::string filename = "/etc/resolv.conf";
    std::string read = stringing(filename);
    std::multiset<char> a = mult(read);
    std::set<char> s = copy(a);
    print(read, s, a);
    return 0;
}

