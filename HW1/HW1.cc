//
//  CS253
//  HW1.cc
//  Farhan Haziq
//  fargah1@cs.colostate.edu
//  2020/09/20
//

#include <iostream>
#include <sstream>  // std::istringstream
#include <vector>   // std::vector
#include <string>
#include <algorithm> // std::all_of
#include <cctype>
#include <limits>

bool is_dig(const std::string &str)
{ 
    return std::any_of(str.begin(), str.end(), ::isdigit);
}

bool is_alpha(const std::string &str)
{
    for (char c : str) 
        if (std::isalpha(c)) { return true; } 
    return false;
}

bool is_keyword(const std::string &str)
{
  const std::vector<std::string> keywords{"if", "fi", "print", "return"};
  for (const auto& keyword : keywords)
        if (keyword == str) { return true; } 
  return false;
}

bool is_oper(const std::string &str)
{
    const std::vector<std::string> oper_symb{"+=", "-=", "*=", "/=", "=", "!=", "<", ">", ">=", "<="};   
    for (const auto& symbol : oper_symb){
        if (symbol == str){ return true; }
    }
    return false;
}

//
//
//  if blank line or new line, skip
//
//
bool is_empty(const std::string &str)
{
    for (const auto &c : str)
        if (!std::isspace((c))) { return false; }
    return true;
}

//
//
//  strip comment from string that has been read
//
//
std::string remove_comm(std::string &line)
{
    std::string::size_type com = line.find("#");
    if (com != std::string::npos) { line.erase(com); }    
    return line;
}

void analyze(std::istringstream &in, std::string &buff, char &c)
{
    if (is_alpha(std::string{1, c})){
        c = tolower(c);
        while (is_alpha(std::string{1, c})){
            buff += c;
            c = in.get();
            c = tolower(c);   
        }

        in.seekg(-1, std::ios::cur);
        if (is_keyword(buff)){
            std::cout << buff;
            buff.clear();
        }
        std::cout << buff << '\n' ;
        buff.clear();
    }

    else if (is_dig(std::string{1, c})){
        c = tolower(c);
         while (is_dig(std::string{1, c})){
            buff += c;
            c = in.get();
        }
        in.seekg(-1, std::ios::cur);
        if (is_dig(buff)){
            std::cout << buff;
            buff.clear();
        }
        std::cout << buff << '\n';
        buff.clear();
    }

    else if (is_oper(buff)){
        buff += c;
        std::cout << buff;
        buff.clear();
    }

    // else { std::cerr << buff <<  " is an invalid token\n"; }

}


//
//
//  get the stream
//
//
void read()
{
    char c;
    std::string buff{};
    std::string line{};
    while (std::getline(std::cin, line)){
        //strip the comment and blank line
        std::istringstream in{remove_comm(line)};
        if (is_empty(line)) { continue; }
        while (in >> c){
            analyze(in, buff,  c);
        }
    }
}


int main(int argc, char *argv[])
{ 
    if (argc < 1){
        std::cerr << "No argument passed!\n";
        exit(1);
    }

    read();
    return 0;
} 