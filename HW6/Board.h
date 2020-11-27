//
//  HW6
//  Board.h
//  Farhan Haziq
//

#ifndef BOARD_H
#define BOARD_H
#include "Rule.h" // most of the include are in here
using _2D_Vect = std::vector<std::vector<char> >; 

class Board
{
private:
    Rule m_rule;
    int m_life;
    int m_row, m_col;
    char m_live, m_dead;
    _2D_Vect m_board, m_next_board;
    bool nw, n, ne, w, me, e, sw, s, se;
public:
    Board(std::string filename, Rule rule, char live, char dead);
    Board(std::string filename, char live, char dead, Rule rule);
    Board(std::string filename, char live, char dead);
    Board(std::string filename, Rule rule);
    Board(std::string filename);
    void game();
    int get_count(int &, int &);
    Board &operator++();
    bool is_valid();
    friend std::ostream &operator<<(std::ostream&, Board&);
};

#endif

