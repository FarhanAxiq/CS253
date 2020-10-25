//
//  HW3
//  lexan.h
//  Farhan Haziq
//  fargah1@cs.colostate.edu
//  2020 October 10
//

#ifndef LEXAN_H
#define LEXAN_H
#include <iostream>  // std::cout std::ostream
#include <sstream> 	 // std::stringstream
#include <algorithm> // std::find_if std::remove_if
#include <vector>    // std::vector
#include <string>	 // std::string std::getline
#include <stdexcept> // std::runtime_error

class Lexan
{
private:
	std::string m_src;
	std::string m_cur;
	std::string m_buf;
	std::vector<std::string> m_tokens;
	const std::vector<std::string> m_keywords{"if", "fi", "print", "return"};
	const std::vector<std::string> m_oper {"+=", "-=", "*=", "/=", "=", "<", ">"};   
	const std::vector<std::string> m_uni{"≠", "≤", "≥"};
public:
	Lexan(std::string);
	Lexan(const Lexan&);
	Lexan &operator=(Lexan&);
	void read();
	void lexing();
	bool match_key();
	bool match_oper();
	bool weird_oper();
	[[nodiscard]] size_t size() const;
	[[nodiscard]] bool empty();
	void clear();
	std::string operator[](size_t) const;
	std::string rm_ws_cm_tolow(std::string &);
	friend std::ostream &operator<<(std::ostream &, const Lexan &);
	~Lexan();
};


#endif