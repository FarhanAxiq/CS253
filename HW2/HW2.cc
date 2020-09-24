//
//  HW2.cc
//  Farhan Haziq
//  fargah1@cs.colostate.edu
//  TBD
//



// TODO: fix game logic
// TODO: comply with the input/output requirement

// A tribute to Mr John Conway 1937-2020 - Victim of COVID-19
// and the inventor of the game

#include <iostream>  // std::cin, std::cout
#include <fstream>   // std::ifstream
#include <string>    // std::getline
#include <vector>    // std::vector
// alias for our 2D vector
using _2D_Vect = std::vector<std::vector<char> >; 

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



//
//  Check if the board is valid
//  Where:
//  the input is not at least 2×2
//  the input contains a bad character
//  the input has inconsistent line lengths.
//
bool is_valid(_2D_Vect &board)
{
    for (std::vector<char> &row : board){
        // check if board is at least 2x2 or inconsistent length
        if  (row.size() < 2 || board.size() < 2 || row.size() != board.at(0).size()){ return false; } 
        // check if the input is a valid char
        for (char &c : row) { 
            if (c != '.' && c != 'O' && c != isspace(c)) { return false; } 
        } 
    }
    return true;
}

//
//
//  check and count living neighbor
//
//
int get_count(_2D_Vect &board, int &x, int &y, int &row, int &col)
{
    int count = 0;
    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++){
            int n_row = (x + i + row) % row;
            int n_col = (y + j + col) % col;
            // if ourself continue
            // if neighbor alive, count++
            if (i == x && j == x) { continue; }
            else if (board.at(n_row).at(n_col) == 'O') { count++; }
        }
    }
    return count;
}

//
// Game Rules: 
// 1) Any live cell with 0 or 1 live neighbors becomes dead, because of underpopulation
// 2) Any live cell with 2 or 3 live neighbors stays alive, because its neighborhood is just right
// 3) Any live cell with more than 3 live neighbors becomes dead, because of overpopulation
// 4) Any dead cell with exactly 3 live neighbors becomes alive, by reproduction
//
void game(_2D_Vect &board)
{
    const char dead  = '.';
    const char alive = 'O';
    int row = board.size();
    int col = board.at(0).size(); // why at 0? Because is_valid has confirmed that there's no inconsistent length line
    // initialize next board
    _2D_Vect next_board{(size_t)row, std::vector<char>(col, dead)}; 
    // traverse the vector
    // gonna be a long code here 
    // TODO: investigate why wrong output
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            int life_count = get_count(board, i, j, row, col);
            char state = board.at(i).at(j);
            if      (state == dead && life_count == 3) { next_board.at(i).at(j) = alive; }
            else if (state == alive && (life_count < 2 || life_count > 3)) { next_board.at(i).at(j) = dead; }
            else    { next_board.at(i).at(j) = state; }
        }
    }
    std::cout << next_board;
}


//
//
//  Create a vector for the game
//  from the file
//  thus creating the initial state
//  of the board.
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
    // if the board generated isn't valid
    // exit
    // non-valid board is definind in is_valid() function
    if (!is_valid(board)){
        std::cerr << "The board generated from " << filename << " is not a valid board.\n";
        exit(1);
    }
    
    in.close();
    return board;
}


int main(int argc, char *argv[])
{
    if (argc < 2){
        std::cerr << "No argument is passed!\n";
        exit(1);
    }
    
    // make a 2D vector, see using for full type definition
    _2D_Vect board = create_board(argv[1]);
    game(board);
    return 0;
}