/**
 * defines.h: lists globally defined values.
 * @author Stefan Brandle, May 2004
 */

#ifndef DEFINES_H		// Double inclusion protection
#define DEFINES_H


using namespace std;

    // Shot related
    const char SHOT = '@';
    const char MISS = '*';
    const char DUPLICATE_SHOT  = '!';
    const char HIT  = 'X';
    const char KILL = 'K';
    const char SHIP = 'S';
    const char WATER = '~';
    const char INVALID_SHOT = (char) 0;

    // Meta information -- win/lose/quit
    const char WIN  = 'W';
    const char LOSE = 'L';
    const char TIE  = 'T';
    const char QUIT = 'Q';
    const char PEEK = 'P';

    const int MAX_SHIPSIZE = 5;

#endif

