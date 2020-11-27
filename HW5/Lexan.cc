//
//  HW5
//  lexan.cc
//  Farhan Haziq
//  fargah1@cs.colostate.edu
//  2020 Novembre 10
//

#include "Lexan.h" 


Lexan::Lexan(std::string src)
	: m_src(src)
{
	try { read(); }
	catch(const std::runtime_error& e){}   
	
}

//
//
//	Copy Constructor
//
//
Lexan::Lexan(const Lexan& other)
	:m_src(other.m_src), m_cur(other.m_cur), m_buf(other.m_buf), m_tokens(other.m_tokens)
{
}

//
//
//
//	= operator overload
//
//
//
Lexan &Lexan::operator=(const Lexan &other)
{
	if (this != &other){	
	}
	return *this;
}

//
//
//
//	get token to be read 
//
//
//
void Lexan::read()
{
	std::stringstream in(m_src);
	std::string line;
	while (std::getline(in, line)){
		m_cur = rm_ws_cm_tolow(line);
		lexing();
	}
}

void Lexan::lexing()
{
	std::stringstream tok(m_cur);
	char c;
	while(tok >> c){
		if (isdigit(c)){
			m_buf += c;
			while (isdigit(tok.peek()) && m_buf.length() < 15){
				tok >> c;
				m_buf += c;
			}
			if (m_buf.length() > 15){
				// throw exception or something
			}
			m_tokens.emplace_back(m_buf, "digit");
			m_buf.clear();
		}

		if (isalpha(c)){
			m_buf += c;
			while (isalpha(tok.peek())){
				tok >> c;
				m_buf += c;
				// if found the keyword stop
				if (match_key()){ 
					m_tokens.emplace_back(m_buf, "keyword");
					break;
				}
			}
			// TODO: fixed this, kinda broken
			if (!match_key()) { 
				m_tokens.emplace_back(std::string{1, m_buf.at(0)}, "variable");
				if (m_buf[1] != '\0'){ 
					m_tokens.emplace_back(std::string{1, m_buf.at(1)}, "variable");
				}
			}
			m_buf.clear();
			
		}

		if (ispunct(c)){
			m_buf += c;
			// check for the 2nd equal 
			if (tok.peek() == '='){
				tok >> c;
				m_buf += c;
			}
			// if found put in the vector
			if (match_oper()){ 
				m_tokens.emplace_back(m_buf, "operator");
			}
			m_buf.clear();
		}
		
		// some hacky way to get the unicode
		// may not work with some OS
		// but whatever
		// it work
		// since we know all three unicode character
		// begin with 0xe2 so we check character we read 
		// from the stream with 0xe2, had to cast it for
		// it to actually detect
		if (c == (char)0xe2){
			m_buf += c;
			// same goes with the second byte which is equal to
			// 0x89, had to cast .peek() to char 
			// as it return int.
			// if it is, we advanced the character read 
			// in the stream
			if ((char)tok.peek() == (char)0x89){
				tok >> c;
				m_buf += c;
				// check for the third byte
				// same principle as above.
				// but since the end byte determine
				// what string it is, so we check if it equal or
				// to the ending byte
				if ((char)tok.peek() == (char)0xa0 || (char)tok.peek() == (char)0xa4 || (char)tok.peek() == (char)0xa5){
					tok >> c;
					m_buf += c;
					// if found put in the vector
					if (weird_oper()){
						m_tokens.emplace_back(m_buf, "operator");
					}
				}
			}
			m_buf.clear();
		}

		if (iscntrl(c) || isspace(c)){
			std::cout << c <<  ": test\n";
		}


		//  m_buf.clear();
	}

}

//
//
//	Check for the keyword
//	true if match
//
//
bool Lexan::match_key()
{
	for (const auto &k : m_keywords){
		if (m_buf == k){ 
			return true; 
			break;
		}
	}
	return false;
}


//
//
//	Check for the operator
//	true if match
//
//
bool Lexan::match_oper()
{
	for (const auto &o : m_oper){
		if (m_buf == o){ 
			return true; 
			break;
		}
	}
	return false;
}


//
//	
//	check for the unicode operator
//	true if match
//
//
bool Lexan::weird_oper()
{
	for (const auto &w : m_uni){
		if (m_buf == w){
			return true;
			break;
		}
	}
	return false;
}

size_t Lexan::size() const { return m_tokens.size(); }

//
//
//	std::vector.at will throw an out_of_range exception
//  return: element at i in vector that hold tokens
//
//
std::string Lexan::operator[](size_t i) const { return m_tokens.at(i).first; }

void Lexan::clear() { m_tokens.clear(); }


//
//
//	check if there's any token to 
//	be process, if empty return true
//	otherwise untrue, I mean false
//
//
bool Lexan::empty() { return m_tokens.empty(); }

//
//
//	This cryptic function
//	is basically removing 
//	whitespace, comment
//  and also make all string go to lowercase
//  it take a string and return the aforementioned
//	result using C++11 > features
//
//
std::string Lexan::rm_ws_cm_tolow(std::string &line)
{
	auto com = line.find_first_of("#");
	auto newl = line.find(R"(\n)");
	if (com != std::string::npos){ (newl != std::string::npos) ? line.erase(com, (newl - com) + 2) : line.erase(com); }
    line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
	line.erase(remove_if(line.begin(), line.end(), ::iscntrl), line.end());
	for (auto &c : line) { c = tolower(c); }
	return line;
}
//
//
//	operator overload to print the token
//	return the stream to be printed out
//
//
std::ostream &operator<<(std::ostream &out, const Lexan &other)
{
	// the bool is to make sure
	// if it the end or no
	// if not the end, append ,
	// otherwise don't 
	bool f = true;
	for (auto &s : other.m_tokens){
		if (!f) { out << ","; }
		f = false;
		out << s.first;
	}
	return out;
}

//
//
//	Cleanup
//
//
Lexan::~Lexan() { clear(); }