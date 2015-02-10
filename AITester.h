/**
 * @author Stefan Brandle and Jonathan Geisler
 * @date August, 2004
 * Main driver for BattleShipsV1 implementations.
 * Please type in your name[s] below:
 *
 *
 */

#ifndef AITESTER_H
#define AITESTER_H

// BattleShips project specific includes.
#include "Message.h"
#include "BoardV2.h"
#include "PlayerV1.h"

using namespace std;

class AITester {
  public:
    AITester(PlayerV1* player, BoardV2* playerBoard, string playerName,
	      int boardSize, bool silent);
    void play(int delay, int& totalMoves);

  private:
    void placeShips(BoardV2* board);
    void showBoard(BoardV2* board, bool ownerView, string playerName);
    void clearScreen();
    void updateAI(PlayerV1 *player, BoardV2 *board);
    void snooze(int seconds);
    bool processShot(string playerName, PlayerV1 *player, BoardV2 *board, 
                     int row, int col);

    // Data
    PlayerV1 *player;
    BoardV2 *playerBoard;
    string playerName;
    int boardSize;
    bool silent;
    bool playerWon;
};

#endif
