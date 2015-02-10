/**
 * @author Stephen Papierski, Andrew Krock
 * @date Fall, 2013
 */

#ifndef MYPLAYA_H		// Double inclusion protection
#define MYPLAYA_H

using namespace std;

#include "PlayerV1.h"

// DumbPlayer inherits from/extends PlayerV1

class MyPlaya: public PlayerV1 {
    public:
	MyPlaya( int boardSize );
	Message getMove();

    private:
        //int lastRow;
        //int lastCol;
		int shotRow;
		int shotCol;
		//functions
		//void carl(int hitRow, int hitCol, int &shotRow, int &shotCol);
		//bool huntNorth(int hitRow,int hitCol,int &shotRow,int &shotCol);
		//bool huntSouth(int hitRow,int hitCol,int &shotRow,int &shotCol);
		//bool huntEast(int hitRow,int hitCol,int &shotRow,int &shotCol);
		//bool huntWest(int hitRow,int hitCol,int &shotRow,int &shotCol);
        bool positionOk(int row, int col, int length, bool horiz);
        void probKill();
};

#endif
