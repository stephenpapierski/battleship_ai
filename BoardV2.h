/**
 * Authors Stefan Brandle and Jonathan Geisler
 * Date    November, 2004
 * Declaration source file for BoardV2.
 * Please type in your name[s] below:
 *
 *
 */

#ifndef BOARDV2_H
#define BOARDV2_H

using namespace std;

class BoardV2 {
    public:
	// Constructors and such
	BoardV2( int width);		
	BoardV2(const BoardV2& other);
	void operator=(const BoardV2& other);
	// General public access functions.
	bool placeShip(int length);
    	char getOpponentView(int row, int col);
    	char getOwnerView(int row, int col);
    	char processShot(int row, int col);
    	bool hasWon();

        const static int MaxBoardSize = 10;     // Maximum board size.

    private:
	// Put prototypes for your private helper functions here.
	void initialize(char board[MaxBoardSize][MaxBoardSize]);
        void chooseValues(int& row, int& col, int& length, bool& horiz);
	bool positionOk(int row, int col, int length, bool horiz);
	void markShip(int row, int col, int length, bool horiz);
        bool isSunk(int row, int col);
        void markSunk(int row, int col);

	// Suggested data variables. Although you can ignore these, it
	// is suggested that you use them. If you change the array definitions,
	// you may have to change some of the prototypes or code that 
	// you are given as part of your starter kit.
	char shipBoard[MaxBoardSize][MaxBoardSize];    // Tracks the placed ships and shots
	char shotBoard[MaxBoardSize][MaxBoardSize];    // Tracks where ships are through whole game
	int boardSize;		    // Tracks how many rows/cols are actually being used.

	// Put your private data variables here.
	char shipMark;		    // Used to mark the ships on shipBoard
    int ship3;
    int ship4;
    int ship5;
};

#endif	// End of multiple inclusion control.

