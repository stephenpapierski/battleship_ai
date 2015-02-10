/**
 * @author Stefan Brandle, Jonathan Geisler
 * @date September, 2004
 *
 * Please type in your name[s] here:
 */

#ifndef HUMANPLAYER_CPP
#define HUMANPLAYER_CPP

#include <iostream>
#include <cctype>

#include "HumanPlayer.h"

using namespace std;


HumanPlayer::HumanPlayer( int boardSize ):
    PlayerV1(boardSize)
{
    //this->boardSize = boardSize;
    lastRow = -1;
    lastCol = -1;
}

/**
 * Gets the computer's shot choice. This is then returned to the caller.
 * @return Message The most important parts of the returned message are 
 * the row and column values. 
 * Position 0 of the int array should hold the row, position 1 the column.
 */
Message HumanPlayer::getMove() {
    Message move(SHOT, -1, -1, "I'm going to win!");

    cout << "Here's your board." << endl;
    if( lastRow != -1 ) {
	cout << "Your last shot resulted in a ";
	switch( board[lastRow][lastCol] ) {
	    case MISS: cout << "miss"; break;
	    case HIT: cout << "hit"; break;
	    case KILL: cout << "kill"; break;
	    default:   cout << "strange result message. Help! ";
	}
	cout << endl;
    }
    showBoard();
    cout << "Enter a shot (ex. A3, 'P' to peek, or 'Q' to quit): " << endl;
    char rowCh;
    char colCh;
    cin >> rowCh;
    rowCh = toupper(rowCh);

    if( !cin ) {
	cerr << "Input stream error. You're hosed." << endl
             << " I'm quitting on your behalf." << endl;
	move.setMessageType(QUIT);
	return move;
    }

    int row, col;
    if(rowCh >= 'A' && rowCh < char('A'+boardSize)) {
	row=int(rowCh-'A');
	cin >> colCh;
	cin.ignore(100, '\n');  // Clean out input buffer
	col=int(colCh-'0');
	cout << endl<<endl << "Column == " << col << endl<<endl;
	if(col<0 || col>=boardSize) {
	    cout << "Valid column values are 0-" << (boardSize-1) << endl;
	    return getMove();
	} else {
	    lastRow = row;
	    lastCol = col;
	    move.setRow(row);
	    move.setCol(col);
	}
    } else if (rowCh == 'P') {
	//cout << "Sorry. This game is for real; no peeking allowed." << endl;
	cin.ignore(100, '\n');  // Clean out input buffer
	return getMove();
    } else if (rowCh == 'Q') {
	move.setMessageType(QUIT);
	cin.ignore(100, '\n');  // Clean out input buffer
    } else {
	cout << "Invalid choice ('" << rowCh << "'). Please try again." << endl;
	cin.ignore(100, '\n');  // Clean out input buffer
	return getMove();
    }

    cout << endl;

    return move;
}

/*
void HumanPlayer::moveResult( Message msg ) {
    board[msg.getRow()][msg.getCol()] = msg.getMessageType();
}
*/

void HumanPlayer::showBoard() {
    cout << " |";
    for(int count=0; count<boardSize; count++) {
        cout << count;
    }
    cout << endl;

    // Put out horizontal header line
    for(int row=0; row<boardSize+2; row++) {
        cout << '-';
    }
    cout << endl;

    for(int row=0; row<boardSize; row++) {
        cout << char(('A'+row)) << '|';
        for(int col=0; col<boardSize; col++) {
                cout << board[row][col];
        }
        cout << endl;
    }
    cout << endl;
}

#endif
