#include <iostream>
#include "Connect_Four.h"

int main () {
	while (true) {
		int player = 1;
		bool won = false;
		bool draw = false;
		ConnectFour game;

		do {
			game.printBoard();

			std::cout<<"Player "<<player;
			std::cout<<": please input the column you want to drop a checker"
			" in. (1-7 inclusive)"<<std::endl;
			int column = 0;
			std::cin>>column;

			if (std::cin.fail() || column > 7 || column < 1) {
				std::cin.clear();
				std::cin.ignore(1000,'\n');
				std::cout<<"Your input was not valid."
				" Please input a number 1 through 7 (inclusive)."<<std::endl;				
				continue;
			} else if (!game.makeMove(player, column - 1)) {
				std::cout<<"The column is filled. Please try again."<<std::endl;
				continue;
			}

			
			int gameState = game.gameComplete();
			switch(gameState) {
				case 0:
					player = (player == 1) ? 2 : 1;
					break;
				case 1:
					draw = true;
				case 2:
					won = true;
					break;
			}

		} while (!won);

		game.printBoard();
		if (draw)
			std::cout<<"The game was a draw!"<<std::endl;
		else
			std::cout<<"Player "<<player 
			<<" won the game!"<<std::endl;

		bool replay = false;
		while (true) {
			std::cout<<"Would you like to play again? (Input Y/N.)"<<std::endl;
			char input = '\0';
			std::cin>>input;
			if (std::toupper(input) == 'Y') {
				replay = true;
				break;
			} else if (std::toupper(input) == 'N') {
				break;
			} else {
				std::cin.clear();
				std::cin.ignore(1000,'\n');
				std::cout<<"Your input was invalid." 
				" Please input Y/N."<<std::endl;
			}
		}

		if (!replay)
			break;
	}
}