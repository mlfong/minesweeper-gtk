#include "minesweeper.h"
#include "tile.h"

#include <iostream>
#include <cassert>
#include <random>
#include <string>
#include <sstream>

void usage()
{
	std::cout << "usage: ./main -l {EASY=1, NORMAL=2, HARD=3}" << std::endl;
	exit(1);
}

using std::cout; using std::endl;

void playGame(MinesweeperGame& game)
{
	
	std::string s ;
		int r = 0, c = 0;
	while(game.isLive())
	{
		game.printGameBoard();
		std::cout << "Enter command: ";
		getline(std::cin, s);
		if(s == "exit")
			break;
		size_t space_pos = s.find(" ");
		size_t space_pos2 = 0;
		if(space_pos == (std::string::npos))
		{
			std::cout << s << " is a bad input." << std::endl;
			continue;
		}
		space_pos2 = s.find(" ", space_pos+1);
		if(space_pos2 == (std::string::npos))
		{
			std::cout << s << " is a bad input." << std::endl;
			continue;
		}
		std::stringstream(s.substr(space_pos+1, space_pos2-space_pos-1)) >> r;
		std::stringstream(s.substr(space_pos2+1)) >> c;
		printf("row: %d, col: %d\n", r, c);
		if(s.at(0) == 'c')
		{
			cout << "clicking..." << endl;
			int ok = game.click(r, c);
			if(!ok)
				printf("(%d, %d) is not a valid point.\n", r, c);		
		}
		else if(s.at(0) == 'm')
		{
			cout << "marking..." << endl;
			game.mark(r, c);
		}
		else
		{
			cout << "bad input?" << endl;
		}
	}
	if(s != "exit")
	{
		game.printGameBoard();
		if(game.getNumOpen() != 0)
			std::cout << "You lose :(" << std::endl;
		else
			std::cout << "You win! :)" << std::endl;	
	}
	std::cout << "Thanks for playing!" << std::endl;
	game.exit();
}

int main(int argc, char* argv[])
{
	if(argc != 3)
		usage();
	int diff = 0;
	if(std::string(argv[1]) == "-l")
		diff = atoi(argv[2]);		
	else
		usage();
	std::cout << "Welcome to Minesweeper!" << std::endl;
	std::cout << "Commands:" << std::endl;
	std::cout << "\tClick (row, col): c # #" << std::endl;
	std::cout << "\tMark (row, col): m # #" << std::endl;
	std::cout << "\tExit: exit" << std::endl;
	MinesweeperGame game = MinesweeperGame::init(diff);
	playGame(game);
	// std::string asd = "abcdef";
	// std::cout << (asd.find("4")==std::string::npos) << endl;
	return 1;
}



