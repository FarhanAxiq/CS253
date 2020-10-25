//
//  GameOfLife.cc
//  Farhan Haziq
//  fargah1@cs.colostate.edu
//  October 24th, 2020
//
//	"Why on earth using the getopt is sooooooo hard????
//	too tired to actually debug
//	some stuff is maaaybe broken, but so is my life.	
//
#include "GameOfLife.h"

// constructor
GameOfLife::GameOfLife(char alive, char dead, std::string golly, std::istream &in)
	:m_alive(alive), m_dead(dead), m_golly(golly)
	{
		set_board(in);
		set_gol();
		game();
	}


//
//  Check if the board is valid
//  Where:
//  the input is not at least 2×2
//  the input contains a bad character
//  the input has inconsistent line lengths.
//
void GameOfLife::set_board(std::istream &in)
{
	std::string line;
	while (std::getline(in, line)){
		std::vector<char> rows;
		for (char &c : line){ rows.emplace_back(c); }
		m_board.emplace_back(rows);
	}
	// if the board generated isn't valid
	// exit
	// non-valid board is definind in is_valid() function
	if (!is_valid()){
		std::cerr << "The board generated is not a valid board.\n";
		exit(1);
	}

	m_row = m_board.size();
	m_col = m_board.at(0).size();    
}

//
//
//	set golly rules
//	as defined
//	by the argument
//	of the input
//	we put them in
//	the vector m_s for s
//	and m_b for b
//
//
void GameOfLife::set_gol()
{
	auto pos = m_golly.find("/");
	std::string b;
	std::string s;
	if (pos != std::string::npos){
		b = m_golly.substr(1, pos - 1);
		s = m_golly.substr(pos + 2, m_golly.length());
	}

	if (b.empty() || s.empty() || m_golly[0] != 'B' || m_golly[pos + 1] != 'S'){
		std::cerr << "Invalid born or survive value\n";
		exit(1);
	}

	for (auto &c : b){
		int p = c - '0';
		m_b.emplace_back(p);
	}

	for (auto &c : s){
		int p = c - '0';
		m_s.emplace_back(p);
	}
}

//
//	count how many
//	neighbours is
//	alive
//
int GameOfLife::get_count(int &x, int &y)
{
	int count = 0;
	for (int i = x - 1; i <= x + 1; i++){
		for (int j = y - 1; j <= y + 1; j++){
			int n_row = (i + m_row) % m_row;
			int n_col = (j + m_col) % m_col;
			// if ourself continue
			// if neighbor alive, count++
			if ((m_board.at(n_row).at(n_col) == m_alive) && (i != x || j != y)) { count++; }
		}
	}
	return count;
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
//	define in m_s and m_b vector
//
//
void GameOfLife::game()
{
	// initialize next board
	m_next_board = m_board;
	for (int i = 0; i < m_row; i++){
		for (int j = 0; j < m_col; j++){
			m_life = 0;
			char curr_state = m_board.at(i).at(j);
			m_life = get_count(i, j);
			m_next_board.at(i).at(j) = m_dead;
			for (int &k : m_s){
			   if (curr_state == m_alive && m_life == k) { m_next_board.at(i).at(j) = m_alive; } 
			}

			 for (int &l : m_b){ 
				 if (curr_state == m_dead && m_life == l) { m_next_board.at(i).at(j) = m_alive; }
			}
			
		}
	}
	m_board = m_next_board;
}



bool GameOfLife::is_valid()
{
	for (std::vector<char> &row : m_board){
		// check if board is at least 2x2 or inconsistent length
		if  (row.size() < 2 || m_board.size() < 2 || row.size() != m_board.at(0).size()){ return false; } 
		// check if the input is a valid char
		for (char &c : row) { 
			if (c != m_alive && c != m_dead) { return false; } 
		} 
	}
	return true;
}

//
//
//  Overloaded << operator to print the board
//
//
std::ostream &operator<<(std::ostream& out, GameOfLife &board)
{
	 for (std::vector<char> &row : board.m_board) {
		for (char &c : row) { out << c; }
		out << '\n';
	}
	return out;
}


int main(int argc, char *argv[])
{
	int opt;
	// set default
	bool state = false;
	std::string golly = "B3/S23";
	char alive = 'O', dead = '.'; 

	while ((opt = getopt(argc, argv, "g:d:l:i")) != -1){
		switch (opt){
			case 'g':
				if (optarg[0] != 'B'){ 
					std::cerr << argv[0] << " : invalid character has been found\n";
					exit(1);
				}
				golly = optarg;
				break;
		
			case 'd':
				dead = optarg[0];
				break;

			case 'l':
				alive = optarg[0];
				break;
			

			// case i
			// we have a flag 
			// that is set as false
			// but once we enter, it's now true
			// and will stop when the board cannot
			// do anything anymore
			// flag turn false and will quit the loop
			case 'i':
			{
				state = true;
				std::ifstream file;
				if (optind < argc) { file.open(argv[optind]); }

				// if that said file cannot be open
				// exit
				if (!file) { 
					std::cerr << argv[optind] << " cannot be open\n"; 
					exit(1);
				}

				// otherwise, read from stdin, here, if it's a file
				// we use the file as the stream
				// otherwise. stdin
				std::istream &in = (optind >= argc) ? std::cin : file;
				GameOfLife g(alive, dead, golly, in);
				while (state){
					std::cout << g << '\n';
					g.game();
					if (g.m_board == g.m_next_board){ state = false; }
					std::cout << g << '\n';
					g.game();
					if (g.m_board == g.m_next_board){ state = false; }
					std::cout << g << '\n';
				}
				break;
			}
			
			default:
				std::cerr << "Usage: " << argv[0] << " [-g golly] [-d] dead [-l] alive [-i] loop [-file]\n";
				exit(1);
		}
	}
	// as getopt permutate non-option at the end
	// file will end up being at the back of
	// the argument
	// so we compared the size of the argc with optin
	// and if it match the criteria
	// we'll attempt to open the file
	// attempt to open the file
	// if it can open the file
	// read from file
	std::ifstream file;
	if (optind < argc) { file.open(argv[optind]); }

	// if that said file cannot be open
	// exit
	if (!file) { 
		std::cerr << argv[optind] << " cannot be open\n"; 
		exit(1);
	}

	// otherwise, read from stdin, here, if it's a file
	// we use the file as the stream
	// otherwise. stdin
	std::istream &in = (optind >= argc) ? std::cin : file;
	GameOfLife g(alive, dead, golly, in);
	std::cout << g;
	
	return 0;
}