#include <iostream>
#include <string>
#include <cctype>

bool start(const std::string &target, const std::string &prefix)
{
    for (size_t i = 0; i < prefix.size(); i++){
        if (tolower(target[i]) != tolower(prefix[i]))
            return false;
    }
    return true;
}

void skip(std::string &input)
{
    while (!input.empty()){
        if (isspace(input[0]))
            input.erase(0, 1);
        else if (input[0] == '#')
            input.clear();
            break;
    }
}

bool get_token(std::string &input, std::string &sym)
{
    static const std::string token[] = {
        "+=", "-=", "*=", "/=", "=", "!=", "<=", ">=", "<", ">", 
        "if", "fi", "print", "return",
        "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l"
        "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
    };

    skip(input);
    if (input.empty())
        return false;

    size_t len = 0;
    while (isdigit(input[len]))
        len++;

    if (!len){
        for (std::string tok : token)
            if (start(input, tok)){
                len = tok.size();
                break;
            }
    }
    if (!len)
        exit(1);
    

    sym.assign(input, 0, len);
    input.erase(0, len);
    for (char &c : sym)
        c = tolower(c);
    return true;
}

void analyze(std::string in){
    for (std::string token; get_token(in, token); ){
        std::cout << token << '\n';
    }
}

void analyze(std::istream &in)
{
    for (std::string line; std::getline(in, line);){
        analyze(line);
    }
}

int main(int argc, char *argv[])
{
    std::string prog_name = argv[0];
    analyze(std::cin);
    return 0;
}