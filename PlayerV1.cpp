/**
 * @author Stefan Brandle
 * @author Jonathan Geisler
 * @date September, 2004
 *
 */

#ifndef PLAYERV1_CPP		// Double inclusion protection
#define PLAYERV1_CPP

#include <iostream>

#include "PlayerV1.h"

PlayerV1::PlayerV1( int boardSize ) {
    // Set boardsize
    this->boardSize = boardSize;
    // Initialize the board to WATER.
    for(int row=0; row<boardSize; row++) {
	for(int col=0; col<boardSize; col++) {
	    board[row][col] = WATER;
	}
    }
}

/**
 * Gets the player's move choice. This is then returned to the caller.
 * @return Message move
 */
// Changed getMove() to pure virtual, so shouldn't have a function
// declaration, not even an empty one.
/*
Message PlayerV1::getMove() {
	// This is just a place holder. Actual work
	// is done in classes derived from this one.
}*/

/**
 * Informs the player of the result of a previous move. 
 * The player updates its internal representation of the
 * opponent's board to reflect the result.
 * @param msg The message will have the shot coordinates
 * (row, col) and the shot result available via the messageType.
 */
void PlayerV1::moveResult( Message msg ) {
    board[msg.getRow()][msg.getCol()] = msg.getMessageType();    
}

#endif

