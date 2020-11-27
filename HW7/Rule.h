//
//  HW6
//  Rule.h
//  Farhan Haziq
//

#ifndef RULE_H
#define RULE_H
#include <iostream>  // std::ostream 
#include <fstream>   // std::ifstream
#include <string>    // std::getline
#include <vector>    // std::vector
#include <stdexcept> // std::except
#include <algorithm> // std::is_sorted std::unique

class Rule
{
private:
    std::string m_rule;
public:
    int m_lifecount;
    std::vector<int> m_birth, m_survive;
    Rule();
    ~Rule();
    void conway();
    void golly(std::string);
    std::string golly();
    bool is_valid();
    bool eval(bool nw, bool n, bool ne, bool w, bool me, bool e, bool sw, bool s, bool se);
};

#endif