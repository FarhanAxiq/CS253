//
//  HW3
//  lexan.h
//  Farhan Haziq
//  fargah1@cs.colostate.edu
//  TBD
//

#ifndef LEXAN_H
#define LEXAN_H
#include <iostream>

class Lexan
{
private:
	std::string m_token;
	size_t m_size;
public:
	Lexan(std::string token);
	Lexan(const Lexan &other);
	Lexan operator=(const Lexan& other);
	size_t size();
	bool empty();
	void clear();
	std::string const &operator[](int i);
	friend std::ostream& operator<<(std::ostream& out, const Lexan& val);
	~Lexan();
};

#endif LEXAN_H