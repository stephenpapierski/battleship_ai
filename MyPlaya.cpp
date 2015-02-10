/*
 * @author Stephen Papierski, Andrew Krock 
 * @date Fall, 2013
 */

#include <iostream>
#include <cmath>

using namespace std;

#include "MyPlaya.h"

MyPlaya::MyPlaya( int boardSize ):
    PlayerV1(boardSize)
{
    //this->boardSize = boardSize;
    //lastRow = -1;         //probalility kill doesn't care where last shot was
    //lastCol = -1;

	
}

/**
 * Gets the computer's shot choice. This is then returned to the caller.
 * @return Message The most important parts of the returned message are 
 * the row and column values. 
 * Position 0 of the int array should hold the row, position 1 the column.
 */
Message MyPlaya::getMove() {
	bool move=false;
	while(move==false){
        probKill();
		//if( board[lastRow][lastCol]==HIT){
		//	carl(lastRow, lastCol, shotRow, shotCol);
		//	if( board[shotRow][shotCol]==KILL){
		//		lastRow=shotRow;
		//		lastCol=shotCol;
		//	}
		//}
		//else{
        //    probKill();
		//	//if( lastCol % boardSize > (lastCol+3) % boardSize ) {
		//	//	lastRow++;
		//	//}
		//	//lastCol=(lastCol+3) % boardSize;
		//	//if( lastRow >= boardSize ) {
		//	//	lastCol = 0;
		//	//	lastRow = 0;
		//	//}
		//	//shotRow=lastRow;
		//	//shotCol=lastCol;
        //    //cout<<"Trying row: "<<shotRow<<"  col: "<<shotCol<<endl;
		//}
		if(board[shotRow][shotCol]==WATER){
			move=true;
		}
	}
	Message result( SHOT, shotRow, shotCol, "Bang" );
	return result;
}

void MyPlaya:: probKill(){
    int probBoard[boardSize][boardSize];
    //Initialize probalility board with 0's
    for (int r=0 ; r<boardSize ; ++r){
        for (int c=0 ; c<boardSize ; ++c){
            probBoard[r][c]=0;
        }
    }
    //Compiles probablility of ships inluding hit locations (but no sunk)
    for (int length=3 ; length<=5 ; ++length){
        for (int horizInt=0 ; horizInt<=1 ; ++horizInt){
            for (int r=0 ; r<boardSize ; ++r){
                for (int c=0 ; c<boardSize ; ++c){
                    bool horiz=horizInt;
                    if (board[r][c]==HIT){
                        if(horiz){
                            for (int markC=c-(length-1) ; markC<(c+length) ; ++markC){
                                if (markC>=0 && markC<boardSize && board[r][markC]==WATER){
                                    probBoard[r][markC]+=10*(length-(abs(c-markC)));
                                }
                            }
                        }else{
                            for (int markR=r-(length-1) ; markR<(r+length) ; ++markR){
                                if (markR>=0 && markR<boardSize && board[markR][c]==WATER){
                                    probBoard[markR][c]+=10*(length-(abs(r-markR)));
                                }
                            }
                        }
                    }
                    if (positionOk(r,c,length,horiz)){//checks if a ship can fit
                        int weight;
                        if(length==3){
                            weight=4;
                        }else if(length==4){
                            weight=0;
                        }else{
                            weight=0;
                        }
                        if(horiz){
                            for (int markC=c ; markC<(c+length) ; ++markC){
                                probBoard[r][markC]+=weight;
                            }
                        }else{
                            for (int markR=r ; markR<(r+length) ; ++markR){
                                probBoard[markR][c]+=weight;
                            }
                        }
                    }
                }
            }
        }
    }

/** not needed...left over from earlier implementation...I think...?*/
//    //strips sunk locations from probablity list
//    for (int r=0 ; r<boardSize ; ++r){
//        for (int c=0 ; c<boardSize ; ++c){
//            if (board[r][c]==KILL){
//                probBoard[r][c]=0;
//            }
//        }
//    }

/** prints probality board between each play*/
//    //prints probability board
//    for (int r=0 ; r<boardSize ; ++r){
//        for (int c=0 ; c<boardSize ; ++c){
//            if (probBoard[r][c]>9){
//                cout<<probBoard[r][c]<<" ";
//            }else{
//                cout<<probBoard[r][c]<<"  ";
//            }
//        }
//        cout<<endl;
//    }
//    cin.get();

    //finds highest number on probBoard
    int highest=0;
    int highRow=-1;
    int highCol=-1;
    for (int r=0 ; r<boardSize ; ++r){
        for (int c=0 ; c<boardSize ; ++c){
            if (probBoard[r][c]>highest){
                highest=probBoard[r][c];
                highRow=r;
                highCol=c;
            }
        }
    }
    shotRow=highRow;
    shotCol=highCol;
    
}

//void MyPlaya::carl(int hitRow,int hitCol,int &shotRow,int &shotCol){
//	if(huntNorth(hitRow,hitCol,shotRow,shotCol)){
//		return;
//	}else if (huntEast(hitRow,hitCol,shotRow,shotCol)){
//		return;
//	}else if (huntSouth(hitRow,hitCol,shotRow,shotCol)){
//		return;
//	}else{
//		huntWest(hitRow,hitCol,shotRow,shotCol);
//	}
//}

//bool MyPlaya::huntNorth(int hitRow,int hitCol,int &shotRow,int &shotCol){
//	for(int r=hitRow-1; r>=0; r--){
//		switch(board[r][hitCol]){
//			case WATER: shotRow=r; shotCol=hitCol; return true;
//			case KILL:;	
//			case MISS: return false;
//		}
//	}
//	return false;
//}
//
//bool MyPlaya::huntSouth(int hitRow,int hitCol,int &shotRow,int &shotCol){
//	for(int r=hitRow+1; r<boardSize; r++){
//		switch(board[r][hitCol]){
//			case WATER: shotRow=r; shotCol=hitCol; return true;
//			case KILL:;
//			case MISS: return false;
//		}
//	}
//	return false;
//}
//
//bool MyPlaya::huntEast(int hitRow,int hitCol,int &shotRow,int &shotCol){
//	for(int c=hitCol+1; c<boardSize; c++){
//		switch(board[hitRow][c]){
//			case WATER: shotCol=c; shotRow=hitRow; return true;
//			case KILL:;
//			case MISS: return false;
//		}
//	}
//	return false;
//}
//
//bool MyPlaya::huntWest(int hitRow,int hitCol,int &shotRow,int &shotCol){
//	for(int c=hitCol-1; c>=0; c--){
//		switch(board[hitRow][c]){
//			case WATER: shotCol=c; shotRow=hitRow; return true;
//			case KILL:;
//			case MISS: return false;
//		}
//	}
//	return false;
//}

bool MyPlaya:: positionOk(int row, int col, int length, bool horiz){
    if (horiz){
        for (int i=col ; i<col+length ; ++i){
            if (row>=boardSize || row<0 || i>=boardSize || i<0 || (board[row][i]!=WATER && board[row][i]!=HIT)) return false;
        }
    }else{
        for (int i=row ; i<row+length ; ++i){
            if (i>=boardSize || i<0 || col>=boardSize || col<0 || (board[i][col]!=WATER && board[i][col]!=HIT)) return false;
        }
    }
    return true;
}
