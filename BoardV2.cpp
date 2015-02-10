/**
 * Authors Stefan Brandle and Jonathan Geisler
 * Date    November, 2004
 * Declaration source file for BoardV2.
 * Please type in your name[s] below:
 * Stephen Papierski
 * Andy Krock
 */
#ifndef BOARDV2_CPP
#define BOARDV2_CPP 


#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <stdlib.h>
#include "BoardV2.h"
#include "defines.h"

using namespace std;


// Constructors and such
BoardV2:: BoardV2( int width){
    boardSize=width;
    shipMark='a';
    initialize(shotBoard);
    initialize(shipBoard);
}

BoardV2:: BoardV2(const BoardV2& other){
    operator= (other);
}

void BoardV2:: operator=(const BoardV2& other){
    this->boardSize=other.boardSize;
    this->shipMark=other.shipMark;
    for (int r=0 ; r<boardSize ; ++r){
        for (int c=0 ; c<boardSize ; ++c){
            this->shipBoard[r][c]=other.shipBoard[r][c];
            this->shotBoard[r][c]=other.shotBoard[r][c];
        }
    }
}

// General public access functions.
bool BoardV2:: placeShip(int length){
    for (int i=0 ; i<=20 ; ++i){
        bool horiz=bool(rand()%2);
        int row;
        int col;
        if(horiz){
            row=rand()%boardSize;
            col=rand()%(boardSize-length+1);
            if(positionOk(row,col,length,horiz)){
                markShip(row,col,length,horiz);
//cout<<"placed horizontal ship of length "<<length<<"col: "<<col<<"row: "<<row<<endl;
//int junk;
//cin.get();
                return true;
            }
        }else{
            row=rand()%(boardSize-length+1);
            col=rand()%boardSize;
            if(positionOk(row,col,length,horiz)){
                markShip(row,col,length,horiz);
//cout<<"placed vertical ship of length"<<length<<"col: "<<col<<"row: "<<row<<endl;
//int junk;
//cin.get();
                return true;
            }
        }
    }
    return false;
}

char BoardV2:: getOpponentView(int row, int col){
    return shotBoard[row][col];
}

char BoardV2:: getOwnerView(int row, int col){
    char ownerBoard[boardSize][boardSize];
    for (int r=0 ; r<boardSize ; ++r){
        for (int c=0 ; c<boardSize ; ++c){
            if(shotBoard[r][c]==WATER){
                if (shipBoard[r][c]==WATER){
                    ownerBoard[r][c]=WATER;
                }else{
                    ownerBoard[r][c]=shipBoard[r][c];
                }
            }else{
                ownerBoard[r][c]=shotBoard[r][c];
            }
        }
    }
    return ownerBoard[row][col];
}

char BoardV2:: processShot(int row, int col){
    if (shotBoard[row][col]==HIT || shotBoard[row][col]==KILL){
        return DUPLICATE_SHOT;
    }else if (shipBoard[row][col]==WATER){
        shotBoard[row][col]=MISS;
        return MISS;
    }else{
        shotBoard[row][col]=HIT;
        char tmp=shipBoard[row][col];
        for (int r=0 ; r<boardSize ; ++r){
            for (int c=0 ; c<boardSize ; ++c){
                if (shipBoard[r][c]==tmp && shotBoard[r][c]!=HIT){
                    return HIT;
                }
            }
        }
        for (int r=0 ; r<boardSize ; ++r){
            for (int c=0 ; c<boardSize ; ++c){
                if (shipBoard[r][c]==tmp){
                    shotBoard[r][c]=KILL;
                }
            }
        }
        return KILL;
    }
}

bool BoardV2:: hasWon(){
    for (int r=0 ; r<boardSize ; ++r){
        for (int c=0 ; c<boardSize ; ++c){
            if (shipBoard[r][c]!=WATER && shotBoard[r][c]!=KILL){
                return false;
            }
        }
    }
    return true;
}

void BoardV2:: initialize(char board[MaxBoardSize][MaxBoardSize]){
    for (int r=0 ; r<MaxBoardSize ; ++r){
        for (int c=0 ; c<MaxBoardSize ; ++c){
            board[r][c]=WATER;
        }
    }
}

void BoardV2:: chooseValues(int& row, int& col, int& length, bool& horiz){
    //does nothing
}

bool BoardV2:: positionOk(int row, int col, int length, bool horiz){
    if (horiz){
        for (int i=col ; i<col+length ; ++i){
            if (shipBoard[row][i]!=WATER) return false;
        }
    }else{
        for (int i=row ; i<row+length ; ++i){
            if (shipBoard[i][col]!=WATER) return false;
        }
    }
    return true;
}

void BoardV2:: markShip(int row, int col, int length, bool horiz){
    if (horiz){
        for (int i=col ; i<col+length ; ++i){
            shipBoard[row][i]=shipMark;
        }
    }else{
        for (int i=row ; i<row+length ; ++i){
            shipBoard[i][col]=shipMark;
        }
    }
    shipMark++;
}
bool BoardV2:: isSunk(int row, int col){
    return false;
}
void BoardV2:: markSunk(int row, int col){
    //does nothing
}

#endif
