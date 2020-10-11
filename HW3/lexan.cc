//
//  HW3
//  lexan.cc
//  Farhan Haziq
//  fargah1@cs.colostate.edu
//  2020 October 10
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
Lexan &Lexan::operator=(Lexan &other)
{
    std::swap(m_src, other.m_src);
    std::swap(m_cur, other.m_cur);
    std::swap(m_buf, other.m_buf);
    m_tokens = other.m_tokens;
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
    while(tok.get(c)){
        if (isdigit(c)){
            m_buf += c;
            while (isdigit(tok.peek()) && m_buf.length() < 15){
                c = tok.get();
                m_buf += c;
            }
            m_tokens.emplace_back(m_buf);
            m_buf.clear();
        }

        if (isalpha(c)){
            m_buf += c;
            while (isalpha(tok.peek())){
                c = tok.get();
                m_buf += c;
                if (match_key()){ 
                    m_tokens.emplace_back(m_buf); 
                    break;
                }
            }
            if (!match_key()) { 
                m_tokens.emplace_back(std::string{1, m_buf.at(0)});
                if (m_buf[1] != '\0'){ m_tokens.emplace_back(std::string{1, m_buf.at(1)}); }
            }
            m_buf.clear();
            
        }

        if (ispunct(c)){
            m_buf += c;
            if (tok.peek() == '='){
                c = tok.get();
                m_buf += c;
            }
            if (match_oper()){ m_tokens.emplace_back(m_buf); }
            m_buf.clear();
        }
        
        if (c > 128 || tok.peek() > 128){
            m_buf += c;
            while (c > 128 || tok.peek() > 128){
                c = tok.get(); m_buf += c;
                c = tok.get(); m_buf += c;
                c = tok.get(); m_buf += c;
                m_buf = m_buf.substr(1,4);
                if (weird_oper()){ m_tokens.emplace_back(m_buf); }	
            }
            m_buf.clear();
        }

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
    for (auto &k : m_keywords){
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
    for (auto &o : m_oper){
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
    for (auto &w : m_uni){
        if (m_buf == w){
            return true;
            break;
        }
    }
    return false;
}

size_t Lexan::size() const
{
    return m_tokens.size();
}

//
//
//	std::vector.at will throw an out_of_range exception
//  return: element at i in vector that hold tokens
//
//
std::string Lexan::operator[](size_t i) const
{
    return m_tokens.at(i);
}

void Lexan::clear()
{
    m_tokens.clear();
}

bool Lexan::empty()
{
    return m_tokens.empty();
}

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
    auto com = line.find("#");
    if (com != std::string::npos) { line.erase(com); } 
    line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
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
    bool f = true;
    for (auto &s : other.m_tokens){
        if (!f) { out << ","; }
        f = false;
        out << s;
    }
    return out;
}

//
//
//	Cleanup
//
//
Lexan::~Lexan()
{
    m_tokens.clear();
}