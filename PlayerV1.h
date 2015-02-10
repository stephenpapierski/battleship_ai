/**
 * @author Stefan Brandle
 * @author Jonathan Geisler
 * @date September, 2004
 *
 */

#ifndef PLAYERV1_H
#define PLAYERV1_H		// Double inclusion protection

#include "Message.h"

class PlayerV1 {
    public:
	/**
	 * Gets the player's move choice. This is then returned to the caller.
	 * @return Message move
	 * This is a pure virtual function. The Player class declares, but does
	 * not define it. That allows a class to force all derived classes
	 * to implement the functionality.
	 */
	virtual Message getMove() = 0;

	/**
	 * Informs the player of the result of a previous move. 
	 * The player updates its internal representation of the
	 * opponent's board to reflect the result.
	 * @param msg The message will have the shot coordinates
	 * (row, col) and the shot result available via the messageType.
	 */
	virtual void moveResult( Message msg );

    protected:
	// Functions
        PlayerV1( int boardSize );

	// Data
        int boardSize;
	const static int MaxBoardSize = 10;
        char board[MaxBoardSize][MaxBoardSize];
};

#endif

