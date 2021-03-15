#include "common/include_header.h"

bool isSafe(vectInts& output, intVecSize row, int col, int queenSize){
	int i = 0, j =0;
	for(i = 0; i < col; ++i){
	 	if(output[row][i]) return false;
	 }

 	for(i = row, j = col; i >= 0 && j >= 0; i--, j--){
 		if(output[i][j]) return false;
 	}

	for(i = row, j = col; j >= 0 && i < queenSize; i++, j--){
		if(output[i][j]) return false;
	}

	return true;
}

bool placeQueens(vectInts& output, int col, int queenSize){
	if(col >= queenSize) return true;
	for(intVecSize row = 0; row < output.size(); ++row ){
		if(isSafe(output, row, col, queenSize)){
			output[row][col] = 1;
			if(placeQueens(output, col+1, queenSize)) return true;
			output[row][col] = 0;
		}
	}
	return false;
}

int main(){
	int boardSize = 8;
	vectInts board(boardSize, ints(boardSize, 0));
	placeQueens(board, 0, boardSize);
	print(board);
}