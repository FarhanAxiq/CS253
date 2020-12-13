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
    long m_capture;
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
        if (sizeof...(a) != 0){  m_capture = {a...}; }

        for (size_t i = 0; i < m_lex.m_tokens.size(); i++){
            if (m_lex.m_tokens[i].second == "variable"){
                if (m_lex.m_tokens[i + 1].first == "="){
                    if (m_lex.m_tokens[i+2].second == "digit"){
                        m_lex.m_tokens[i] = m_lex.m_tokens[i+2];
                        m_capture = std::stol(m_lex.m_tokens[i].first);
                    }

                    if (m_lex.m_tokens[i+2].second == "variable"){
                        m_lex.m_tokens[i] = m_lex.m_tokens[i+2];
                    }
                }

                if (m_lex.m_tokens[i + 1].first == "*="){
                    if (m_lex.m_tokens[i+2].second == "digit"){
                        m_capture /= std::stol(m_lex.m_tokens[i + 2].first);
                    }
                    if (m_lex.m_tokens[i+2].second == "variable"){
                        m_lex.m_tokens[i] = m_lex.m_tokens[i+2];
                    }
                }

                if (m_lex.m_tokens[i + 1].first == "/="){
                      if (m_lex.m_tokens[i+2].second == "digit"){
                        m_capture /= std::stol(m_lex.m_tokens[i + 2].first);
                    }

                    if (m_lex.m_tokens[i+2].second == "variable"){
                        m_lex.m_tokens[i] = m_lex.m_tokens[i+2];
                    }
                }

                if (m_lex.m_tokens[i + 1].first == "+="){
                      if (m_lex.m_tokens[i+2].second == "digit"){
                         m_capture /= std::stol(m_lex.m_tokens[i + 2].first);
                    }
                    if (m_lex.m_tokens[i+2].second == "variable"){
                        m_lex.m_tokens[i] = m_lex.m_tokens[i+2];
                    }
                }

                if (m_lex.m_tokens[i + 1].first == "-="){
                    if (m_lex.m_tokens[i+2].second == "digit"){
                         m_capture /= std::stol(m_lex.m_tokens[i + 2].first);
                    }
        
                    if (m_lex.m_tokens[i+2].second == "variable"){
                        m_lex.m_tokens[i] = m_lex.m_tokens[i+2];
                    }
                }
            }

            if (m_lex.m_tokens[i].first == "print"){
                std::cout << m_capture << "\n";       
            }

            if (m_lex.m_tokens[i].first == "return"){
                return m_capture;        
            }
        }
        return 0;
    }
};


#endif