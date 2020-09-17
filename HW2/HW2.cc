//
//  HW2.cc
//  Farhan Haziq
//  fargah1@cs.colostate.edu
//  TBD
//

// A tribute to Mr John Conway 1937-2020 - Victim of COVID-19
// and the inventor of the game

#include <iostream>  // std::cin, std::cout
#include <fstream>   // std::ifstream
#include <string>    // std::getline
#include <vector>    // std::vector
using _2D_Vect = std::vector<std::vector<char>>; // simplified the convoluted 2D vect name

//
//
//  Overload << operator to print the board
//
//
std::ostream &operator<<(std::ostream& out, _2D_Vect &board)
{
     for (std::vector<char> &row : board) {
        for (char &c : row) { out << c; }
        out << '\n';
    }
    return out;
}

void game(_2D_Vect &board)
{
    bool state;
    char cells;
    // traverse the vector
    for (std::vector<char> &row : board) {
        for (char &c : row) {
            std::cout << c;
        }

        std::cout << '\n';
    }
}

//
//
//  Create a vector for the game
//  from the file
//
//
_2D_Vect create_board(std::string filename)
{
    std::ifstream in(filename);
    if (!in.is_open()){
        std::cerr << filename << " cannot be open!\n";
        exit(1);
    }

    std::string line;
    _2D_Vect board;
    while (std::getline(in, line)){
        std::vector<char> rows;
        for (char &c : line){ rows.emplace_back(c); }
        board.emplace_back(rows);
    }
    in.close();
    return board;
}

int main(int argc, char *argv[])
{
    if (argc < 1){
        std::cerr << "No argument is passed!\n";
        exit(1);
    }
    
    // make a 2D vector, see typedef for full type definition
    _2D_Vect board = create_board(argv[1]);
    game(board);
    return 0;
}