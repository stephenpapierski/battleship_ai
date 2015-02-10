/**
 * Message.h: Defines a primitive message class.
 * Authors:   Stefan Brandle and Jonathan Geisler
 * Date:      December 2004
 */

#include <string>
#include "defines.h"

using namespace std;

#ifndef MESSAGE_H		// Double inclusion protection
#define MESSAGE_H

class Message {
    public:
	Message( char messageType );              // Constructors
	Message( char messageType, int row, int col, string str );

	// General set function
	void setMessage( char messageType, int row, int col, string str );

	void setMessageType( char messageType );  // set/get message type functions
	char getMessageType( );

	void setRow( int row );                   // set/get row functions
	int getRow( );

	void setCol( int col );                   // set/get column functions
	int getCol( );

	void setString( string str );             // set/get string functions
	string getString( );

    private:
        char messageType;                         // Fields
        int row;
        int col;
        string str;
};

#endif

