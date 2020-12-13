//
//  HW5
//  Jail.cc
//  Farhan Haziq
//  fargah1@cs.colostate.edu
//  2020 December 10
//

#include "Jail.h" 

Jail::Jail(std::string token)
    :m_lex(token){}

Jail::Jail(const Jail& other)
	:m_lex(other.m_lex), m_answer(other.m_answer), m_args(other.m_args){}


Jail &Jail::operator=(const Jail &other)
{
	if (this != &other){
		
	}
	return *this;
}


std::ostream &operator<<(std::ostream &out, const Jail &other)
{
    return out;
}

Jail::~Jail() { }
