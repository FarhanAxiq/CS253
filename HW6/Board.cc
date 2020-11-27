//
//  HW6
//  Board.cc
//  Farhan Haziq
//

#include "Board.h"

// main constructor
Board::Board(std::string filename, Rule rule, char live, char dead)
    : m_rule(rule), m_live(live), m_dead(dead)
{
    std::ifstream in(filename);
    std::string line;
    while (std::getline(in, line)){
        std::vector<char> rows;
        for (char &c : line){ rows.emplace_back(c); }
		m_board.emplace_back(rows);
    }

    // change to exception
    if (!is_valid()){
        // some hacky way to get the message to the throw message
        // ugly but work
		throw std::runtime_error(std::string("Invalid board generated from the file ") + filename); 
	}
	nw = false, n = false, ne = false, w = false, me = false, e = false, sw = false, s = false, se = false;
    m_row = m_board.size();
	m_col = m_board[0].size(); 
}

// all delegated to the top function - making it DRY
// could be reduce even further with function parameter
// but might confused the compiler
Board::Board(std::string filename, char live, char dead, Rule rule)
    : Board(filename, rule, live, dead) {}

Board::Board(std::string filename, char live, char dead)
    : Board(filename, Rule(), live, dead){}

Board::Board(std::string filename, Rule rule)
    : Board(filename, rule, 'O', '.'){}

Board::Board(std::string filename)
    : Board(filename, Rule(), 'O', '.') {}


//
//
//  check if the board
//  provided have valid
//  content, size, length.
//  true if match the rule, false otherwise.
//
//
bool Board::is_valid()
{
	for (std::vector<char> &row : m_board){
		// check if board is at least 2x0 or inconsistent length
		if  (row.size() < 2 || m_board.size() < 2 || row.size() != m_board.at(0).size()){ return false; } 
		// check if the input is a valid char
		for (char &c : row) { 
			if (c != m_live && c != m_dead) { return false; } 
		} 
	}
	return true;
}


//
//
//	Here's where the game is
//	we loop through the board
//	and then while doing so, we
//	called get_count to check on
//	how many of our neighbour
//	are alive
//	and then once that done
//	we'll figure out what to do
//	with the neighbour, whether they
//	survive or not
//	the value of that is
//	define in m_survive and m_birth vector
//  in Rule class
//
//
void Board::game()
{
	// initialize next board
	m_next_board = m_board;
	for (int i = 0; i < m_row; i++){
		for (int j = 0; j < m_col; j++){
			m_life = 0;
			char curr_state = m_board.at(i).at(j);
			m_life = get_count(i, j);
			m_next_board.at(i).at(j) = m_dead;
			for (int &k : m_rule.m_survive){
			   if (curr_state == m_live && m_life == k) { m_next_board.at(i).at(j) = m_live; } 
			}

			 for (int &l : m_rule.m_birth){ 
				 if (curr_state == m_dead && m_life == l) { m_next_board.at(i).at(j) = m_live; }
			}
			
		}
	}
	m_board = m_next_board;
}



//
//	count how many
//	neighbours is
// 	alive
//  idk how to get eval to work
//
int Board::get_count(int &x, int &y)
{
	int count = 0;

	// offset to avoid running into out-of-bound
	int x0 = x - 1;
	int x2 = x + 1;
	int y0 = y - 1;
	int y2 = y + 1;

	if (x0 == -1) { x0 = m_row - 1; } 
	if (x2 == m_row) { x2 = 0; }
	if (y0 == -1) { y0 = m_col - 1; }
	if (y2 == m_col) { y2 = 0; }
		
	if (m_board[x0][y0] == m_live){
		nw = true;
		count++;
	}

	if (m_board[x0][y] == m_live){
		n = true;
		count++;
	}

	if (m_board[x0][y2] == m_live){
		ne = true;
		count++;
	}

	if (m_board[x][y0] == m_live){
		w = true;
		count++;
	}

	// don't count ourselves
	if (m_board[x][y] == m_live){
		me = true;
	}

	if (m_board[x][y2] == m_live){
		e = true;
		count++;
	}

	if (m_board[x2][y0] == m_live){
		sw = true;
		count++;
	}

	if (m_board[x2][y] == m_live){
		s = true;
		count++;
	}

	if (m_board[x2][y2] == m_live){
		se = true;
		count++;
	}
	
	return count;
}


//
//
//  operator overload for
//  the preincrement
//
//
Board &Board::operator++()
{
    game();
    return *this;
}


//
//
//  overloaded for std::cout <<
//
//
std::ostream &operator<<(std::ostream& out, Board &board)
{
     for (std::vector<char> &row : board.m_board) {
        for (char &c : row) { out << c; }
        out << '\n';
    }
    return out;
}
