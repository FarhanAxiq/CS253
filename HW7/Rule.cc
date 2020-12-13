//
//  HW7
//  Rule.cc
//  Farhan Haziq
//  2020 December 10
//

#include "Rule.h"

//
// call conway to set default
//
Rule::Rule()
{
    conway();
}


//
//
//  set to conway rule
//  by delegating it to
//  golly which then set
//  the rule
//
//
void Rule::conway()
{
    golly("B3/S23");
}


//
//
//	set golly rules
//	as defined
//	by the argument
//	of the input
//	we put them in
//	the vector m_survive
//	and m_birth
//
//
void Rule::golly(std::string rule)
{
    m_rule = rule;
    m_birth.clear();
    m_survive.clear();
    std::string birth, survive;
    auto pos = m_rule.find("/");
    if (pos != std::string::npos){
        birth   = m_rule.substr(1, pos - 1);
        survive = m_rule.substr(pos + 2, m_rule.length());
    }

    // check if we can process the string
    if (birth.empty() || survive.empty() || m_rule[0] != 'B' || m_rule[pos + 1] != 'S' || m_rule[0] == 'S' || m_rule[pos + 1] == 'B'){
		throw std::runtime_error(m_rule + std::string(" is an invalid value.")); 
	}


    // these is to convert char digit to int digit
    // '0' is the offset for the char digit
    for (const auto &c : birth){
        int p = c - '0';
        m_birth.emplace_back(p);
    }

    for (const auto &c : survive){
        int p = c - '0';
        m_survive.emplace_back(p);
    }
 

    if (!is_valid()){
        throw std::runtime_error(m_rule + std::string(" is an invalid value.")); 
    }
    
}

//
//
//  return current golly rule
//
//
std::string Rule::golly()  { return m_rule; }

//
//  check if contains similar digit
//  or if its not in ascending order
//  using C++ STL stuff in algorithm
//  not fast but easier to read.
//
bool Rule::is_valid()
{
    auto it = std::unique(m_birth.begin(), m_birth.end());
    auto it2 = std::unique(m_survive.begin(), m_survive.end());
    if (!std::is_sorted(m_birth.begin(), m_birth.end()) || !std::is_sorted(m_survive.begin(), m_survive.end()) || it != m_birth.end() || it2 != m_survive.end()){
        return false;
    }
    return true;
}

//
//  Evaluate the current rule, Conway or Golly, 
//  for the given arguments. Return true if a cell should be here next time 
//  (via birth or survival), and false if no cell should be here next time.
//  The nine bool arguments represent the immediate neighborhood of the cell in question, 
//  including the cell itself (true for alive, false for dead):
//
bool Rule::eval(bool nw, bool n, bool ne, bool w, bool me, bool e, bool sw, bool s, bool se)
{
    for (int &k : m_survive){
		 if (me && m_lifecount == k) { 
             return true;
          } 
	}

	for (int &l : m_birth){ 
		if (!me && m_lifecount == l) { 
            return true; 
        }
	}
    return false;
}

void Rule::jail(std::string program)
{
    Jail j(program);
    j.run();
}

Rule::~Rule()
{
    m_birth.clear();
    m_survive.clear();
}



