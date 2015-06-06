#include <iostream>
#include <string>
#include "Connect_Four.h"

ConnectFour::ConnectFour(): moveCount(0) {
	//Initialize the array
	for (int row = 0; row < MAX_ROWS; ++row)
		for (int column = 0; column < MAX_COLUMNS; ++column)
			board[row][column] = 0;
}

bool ConnectFour::makeMove(int player, int column) {
	//Find the first empty space and put a checker in it
	for (int row = MAX_ROWS - 1; row >= 0; --row) {
		if (board[row][column] == 0) {
			board[row][column] = player;
			moveCount += 1;
			return true;
		}
	}

	return false;
}

int ConnectFour::gameComplete() {
	if (checkVertical() || checkHorizontal() || checkDiagonal())
		return WIN;
	else if (moveCount == MAX_MOVES)
		return DRAW;
	else
		return NOT_WON;
}

bool ConnectFour::checkVertical() {
	for (int column = 0; column < MAX_COLUMNS; ++column) {
		int playerOnePoints = 0;
		int playerTwoPoints = 0;

		for (int row = 0; row < MAX_ROWS; ++row) {
			int player = board[row][column];
			if (player == PLAYER_ONE) {
				playerOnePoints += 1;
				playerTwoPoints = 0;
			} else if (player == PLAYER_TWO) {
				playerTwoPoints += 1;
				playerOnePoints = 0;
			} else {
				playerOnePoints = 0;
				playerTwoPoints = 0;
			}

			if (playerOnePoints == WIN_NUMBER || playerTwoPoints == WIN_NUMBER)
				return true;
		}
	}

	return false;
}

bool ConnectFour::checkHorizontal() {
	for (int row = 0; row < MAX_ROWS; ++row) {
		int playerOnePoints = 0;
		int playerTwoPoints = 0;

		for (int column = 0; column < MAX_COLUMNS; ++column) {
			int player = board[row][column];
			if (player == PLAYER_ONE) {
				playerOnePoints += 1;
				playerTwoPoints = 0;
			} else if (player == PLAYER_TWO) {
				playerTwoPoints += 1;
				playerOnePoints = 0;
			} else {
				playerOnePoints = 0;
				playerTwoPoints = 0;
			}
			
			if (playerOnePoints == WIN_NUMBER || playerTwoPoints == WIN_NUMBER)
				return true;
		}
	}

	return false;
}

bool ConnectFour::checkDiagonal() {
	for (int row = MAX_ROWS - 4; row >= 0; --row) {
		for (int column = MAX_COLUMNS - 4; column >= 0; --column) {
		int playerOnePoints = 0;
		int playerTwoPoints = 0;

			for (int horiz = 3; horiz >= 0; --horiz) {
				int player = board[row + horiz][column + horiz];
				if (player == PLAYER_ONE) {
					playerOnePoints += 1;
					playerTwoPoints = 0;
				} else if (player == PLAYER_TWO) {
					playerTwoPoints += 1;
					playerOnePoints = 0;
				} else {
					playerOnePoints = 0;
					playerTwoPoints = 0;
				}

				if (playerOnePoints == WIN_NUMBER || 
					playerTwoPoints == WIN_NUMBER)
					return true;
			}
		}
	}

	for (int row = MAX_ROWS - 4; row >= 0; --row) {
		for (int column = MAX_COLUMNS - 4; column >= 0; --column) {
			int playerOnePoints = 0;
			int playerTwoPoints = 0;

			for (int horiz = 3; horiz >= 0; --horiz) {
				int player = board[row + horiz][column - horiz + 3];
				if (player == PLAYER_ONE) {
					playerOnePoints += 1;
					playerTwoPoints = 0;
				} else if (player == PLAYER_TWO) {
					playerTwoPoints += 1;
					playerOnePoints = 0;
				} else {
					playerOnePoints = 0;
					playerTwoPoints = 0;
				}

				if (playerOnePoints == WIN_NUMBER || 
					playerTwoPoints == WIN_NUMBER)
					return true;
			}
		}
	}
	
	return false;
}

void ConnectFour::printBoard() {
	const std::string endsNums = "  1 2 3 4 5 6 7  ";
	const std::string ends = "  - - - - - - -  "; //Top and bottom borders
	std::cout<<endsNums<<std::endl;
	std::cout<<ends<<std::endl;

	for (int row = 0; row < MAX_ROWS; ++row) {
		std::string rowString = std::to_string(row + 1) + "|"; //Left border
		for (int column = 0; column < MAX_COLUMNS; ++column) {
				rowString += (column > 0 && column < MAX_COLUMNS) ? " " : "";
				rowString += std::to_string(board[row][column]); //Space state
		}
		rowString += "|" + std::to_string(row + 1); //Right border
		std::cout<<rowString<<std::endl;
	}

	std::cout<<ends<<std::endl;
	std::cout<<endsNums<<std::endl;
	std::cout<<"Moves: " <<moveCount<<std::endl;
}