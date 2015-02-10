Message SmartPlayer:: getMove(){
    if (board[lastRow][lastCol])==HIT{
        destroyer(lastRow,lastCoo,shotRow,shotCol);
    }else{
        scanner(lastRow,lastCol,shotRow,shotCol);
    }
    Message result (SHOT,lastRow,lastCol,"bang");
    return result;
}

void SmartPlayer:: destroyer(hitRow, hitCol, &shotRow, &shotCol){
    if(huntNorth(hitRow, hitCol, shotRow, shotCol)){
        return;
    }else if (huntEast...){
        //
    }else if (huntSouth...){
        //
    }else{
        //huntWest
    }
}

bool SmartPlayer:: huntNorth(hitRow, hitCol, &shotRow, &shotCol){
    for (int r=hitRow-1 ; r>=1 ; r--){
        switch(board[r][hitCol]){
            case WATER; shotRow=r; shotCol=hitCol; return true;
            case KILL;
            case MISS;
        }
    }
    return false;
}
