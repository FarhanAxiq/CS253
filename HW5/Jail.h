//
//  HW5
//  Jail.h
//  Farhan Haziq
//  fargah1@cs.colostate.edu
//  2020 Novembre 10
//


#ifndef JAIL_H
#define JAIL_H
#include <iostream>  // std::cout std::ostream
#include <sstream> 	 // std::stringstream
#include <algorithm> // std::find_if std::remove_if
#include <vector>    // std::vector
#include <string>	 // std::string std::getline
#include <stdexcept> // std::runtime_error
#include <utility>   // std::pair 
#include "Lexan.h"

class Jail
{
private:
    Lexan m_lex;
    long m_answer;
    std::vector<long> m_args;
public:
    Jail(std::string);
    Jail(const Jail&);
    Jail &operator=(const Jail&);
    ~Jail();
    friend std::ostream &operator<<(std::ostream &, const Jail &);

    //  welp, had to put it here as it is a template
    //  what that does is basically allowing
    //  us to do vararg, therefore making the code DRY
    template<typename... Param>
    long run(Param... a)
    {
        m_args = {a ...};
        if (m_args.empty()){
            for (auto &x: m_lex.m_tokens){
                if (x.second == "digit"){ m_args.emplace_back(std::stol(x.first)); }
                
            }
        }

        if (m_args.size() > 0 || m_args.size() < 26){
        }


        return m_answer;
    }
};


#endif