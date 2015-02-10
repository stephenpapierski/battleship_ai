/**
 * @author Stefan Brandle, Jonathan Geisler
 * @date September, 2004
 *
 * Please type in your name[s] here:
 *
 */

#ifndef DUMBPLAYER_H		// Double inclusion protection
#define DUMBPLAYER_H

using namespace std;

#include "PlayerV1.h"

// DumbPlayer inherits from/extends PlayerV1

class DumbPlayer: public PlayerV1 {
    public:
	DumbPlayer( int boardSize );
	Message getMove();

    private:
        int lastRow;
        int lastCol;
};

#endif
