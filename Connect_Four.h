#ifndef CONNECT_FOUR
#define CONNECT_FOUR

class ConnectFour {
private:
	enum {
		NOT_WON     =  0,
		DRAW        =  1,
		PLAYER_ONE  =  1,
		PLAYER_TWO  =  2,
		WIN         =  2,
		WIN_NUMBER  =  4,
		MAX_ROWS    =  6, 
		MAX_COLUMNS =  7,
		MAX_MOVES   = 42
	};
	int moveCount;
	int board[MAX_ROWS][MAX_COLUMNS];

	bool checkVertical();
	bool checkHorizontal();
	bool checkDiagonal();

public:
	ConnectFour();
	bool makeMove(int player, int column);
	int gameComplete();
	void printBoard();
};

#endif