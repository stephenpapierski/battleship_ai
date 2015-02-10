/**
 * @author Stefan Brandle, Jonathan Geisler
 * @date September, 2004
 *
 * Please type in your name[s] here:
 */

#include <iostream>

using namespace std;

#include "DumbPlayer.h"

DumbPlayer::DumbPlayer( int boardSize ):
    PlayerV1(boardSize)
{
    //this->boardSize = boardSize;
    lastRow = 0;
    lastCol = -1;
}

/**
 * Gets the computer's shot choice. This is then returned to the caller.
 * @return Message The most important parts of the returned message are 
 * the row and column values. 
 * Position 0 of the int array should hold the row, position 1 the column.
 */
Message DumbPlayer::getMove() {
    lastCol++;
    if( lastCol >= boardSize ) {
	lastCol = 0;
	lastRow++;
    }
    if( lastRow >= boardSize ) {
	lastCol = 0;
	lastRow = 0;
    }

    Message result( SHOT, lastRow, lastCol, "Bang" );
    return result;
}

