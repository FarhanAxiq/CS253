//
//  HW3
//  lexan.cc
//  Farhan Haziq
//  fargah1@cs.colostate.edu
//  TBD
//

#include "lexan.h"

Lexan::Lexan(std::string token)
	:m_token(token) {}

Lexan::Lexan(const Lexan& other)
	:m_token(other.m_token){}

Lexan Lexan::operator=(const Lexan& other)
{

}

size_t Lexan::size()
{
	return m_token.size();
}

bool Lexan::empty()
{
	return size() == 0;
}

void Lexan::clear()
{
}

std::string const &Lexan::operator[](int i)
{
	if (i > 0 && i < m_token.size()) {
		try { return m_token[i]; }
		catch (std::out_of_range &e) { throw e("Out of range\n"); }
	}
}

std::ostream& operator<<(std::ostream& out, const Lexan& val)
{
	return out;
}

Lexan::~Lexan()
{
	while (!(empty())) {
		clear();
	}
}
