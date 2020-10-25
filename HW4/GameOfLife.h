//
//  GameOfLife.h
//  Farhan Haziq
//  fargah1@cs.colostate.edu
//  TBD
//

#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include <iostream>  // std::cin, std::cout. std::istream
#include <fstream>   // std::ifstream
#include <string>    // std::getline
#include <vector>    // std::vector
#include <algorithm> // std::find
#include <cstring>
#include <unistd.h>  // getopt()
// alias for our 2D vector
using _2D_Vect = std::vector<std::vector<char> >; 


class GameOfLife
{
private:
    int m_life;
    int m_row, m_col;
    char m_alive, m_dead;
    std::string m_golly;
    std::vector<int> m_b;
    std::vector<int> m_s;
public:
    _2D_Vect m_board;
    _2D_Vect m_next_board;
    GameOfLife(char, char, std::string, std::istream&);
    void set_board(std::istream&);
    void set_gol();
    bool is_valid();
    void game();
    int get_count(int&, int&);
    friend std::ostream &operator<<(std::ostream&, GameOfLife&);
};


#endif