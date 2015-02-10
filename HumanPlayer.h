/**
 * @author Stefan Brandle, Jonathan Geisler
 * @date September, 2004
 *
 * Please type in your name[s] here:
 *
 */

#ifndef HUMANPLAYER_H		// Double inclusion protection
#define HUMANPLAYER_H

using namespace std;

#include "PlayerV1.h"

// HumanPlayer inherits from/extends PlayerV1

class HumanPlayer: public PlayerV1 {
    public:
	HumanPlayer( int boardSize );
	Message getMove();
	//void moveResult( Message msg );

    private:
	void showBoard();
        int lastRow;
        int lastCol;
};

#endif
