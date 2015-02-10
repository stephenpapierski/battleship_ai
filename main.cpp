/**
 * @author Stefan Brandle and Jonathan Geisler
 * @date August, 2004
 * Main driver for BattleShipsV1 implementations.
 * Please type in your name[s] below:
 *
 *
 */

#include <iostream>
#include <iomanip>
#include <cctype>
#include <assert.h>

// Next 2 to access and setup the random number generator.
#include <stdlib.h>
#include <time.h>

// BattleShips project specific includes.
#include "BoardV2.h"
#include "AITester.h"
#include "PlayerV1.h"

// Include your player here
#include "MyPlaya.h"

// Provided players
//#include "DumbPlayer.h"
#include "CleanPlayer.h"
#include "OrigGamblerPlayer.h"
#include "HumanPlayer.h"


using namespace std;

int main() {
    PlayerV1 *player=NULL;
    BoardV2 *board;
    string playerName;
    int boardSize;	// BoardSize
    bool silent = false;
    int milliSecondsPerMove = 1;
    int gameMoves = 0;
    double totalMoves = 0.0;
    int totalGames = 0;
    char displayChoice = 'y';

    // Seed (setup) the random number generator.
    // This only should to happen once per program run!
    srand(time(NULL));

    // Now to get the board size.
    cout << "What size board would you like? [Anything other than numbers 3-10 exits.] ";
    cin >> boardSize;
    // If have invalid board size input (non-number, or 0-2, or > 10).
    if ( !cin || boardSize < 3 || boardSize > 10 ) {
	cout << "Exiting" << endl;
	return 1;
    }
    // Choose an AI to test.
    // TODO: change the dumb player things out for your player.
    cout << endl << "Which player would you like to face? " << endl
         << "0\tMyPlaya" << endl
         << "1\tClean Player" << endl
         << "2\tOriginal Gambler Player" << endl
	 << "3\tHuman Player" << endl
	 << endl << "Your choice: ";
    int choice;
    cin >> choice;
    while( choice < 0 || choice > 3 ) {
	cout << endl << "Invalid choice." << endl;
	cout << "Which AI would you like to test? " << endl
	     << "0\tMyPlaya" << endl
	     << "1\tClean Player" << endl
	     << "2\tOriginal Gambler Player" << endl
	     << "3\tHuman Player" << endl
	     << endl << "Your choice: ";
	cin >> choice;
    }

    // Find out how many times to test the AI.
    cout << "How many times should I test the game AI? ";
    cin >> totalGames;
    // Determine display options.
    cout << "Would you like to see each game displayed? [Y/n] ";
    cin >> displayChoice;
    if( tolower(displayChoice) == 'n') {
        silent = true;
    }
    if( ! silent ) {
        cout << "How many milliseconds per move? [0 means as fast as possible] ";
        cin >> milliSecondsPerMove;
    } else {
        milliSecondsPerMove = 0;
    }

    // And now it's show time!
    for( int count=0; count<totalGames; count++ ) {
	switch( choice ) {
	    case 0:
		// TODO: change the dumb player things out for your player.
		// Make a new player AI and board. To do this with a different
		// AI (other than DumbPlayer), change two things:
		// (1) Change "DumbPlayer" on the next line to the name of your AI class.
		//player = new DumbPlayer(boardSize);
		player = new MyPlaya(boardSize);

		// (2) Change what the playerName string is set to, from "Dumb Player"
		//     to whatever you want your AI to call itself.
		//playerName = "Dumb Player";
		playerName = "MyPlaya";
		break;

	    case 1:
		player = new CleanPlayer(boardSize);
		playerName = "Clean Player";
		break;

	    case 2:
		player = new OrigGamblerPlayer(boardSize);
		playerName = "Original Gambler Player";
		break;

	    case 3:
    		player = new HumanPlayer(boardSize);
    		playerName = "Human Player";
    		break;

	    default:
	        cout << "Invalid player choice (" << choice << ")! Exiting ..." << endl;
		exit(1);
	}
	assert(player!=NULL);
	board = new BoardV2(boardSize);

	AITester tester(player, board, playerName, boardSize, silent);
	tester.play(milliSecondsPerMove, gameMoves);

	totalMoves += gameMoves;	// Update the total moves

	// Get rid of the used player AI and board
	delete player;
	delete board;
    }

    // Print out the stats.
    cout << "Done testing \"" << playerName << "\" AI." << endl
         << "Total games = " << totalGames << endl
         << "Average shots per game was " << showpoint << setprecision(3)
	 << totalMoves/totalGames << endl
	 << "Percentage of board shot at = " <<
	     float(100*totalMoves/totalGames)/(boardSize*boardSize) << endl;

    return 0;
}
