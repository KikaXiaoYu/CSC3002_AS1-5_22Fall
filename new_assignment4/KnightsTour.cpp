/* Q1
 * File: KnightsTour.cpp
 * ---------------------
 * This program find a knight's tour on an N x M chessboard.
 */

#include "csc300222fall/assignment4/KnightsTour.h"  //For OJ
/*
 * Function: solveKnightsTour
 * Usage: solveKnightsTour(n, m);
 * ------------------------------
 * Solves the knight's tour problem for a n x m chessboard.
 */



void solveKnightsTour(int n, int m) {
   Grid<int> board(n, vector<int>(m, 0));
   if (findKnightsTour(board, 0, 0, 1)) {
      displayBoard(board);
   } else {
      displayBoard(board);
      cout << "No tour exists for this board." << endl;
   }
}

/*
 * Function: displayBoard
 * Usage: displayBoard(board);
 * ---------------------------
 * Displays each of the squares in the board along with its sequence
 * number in the tour.
 */

void displayBoard(Grid<int> & board) {
   for (int i = board.size() - 1; i >= 0; i--) {
      for (int j = 0; j < board[0].size(); j++) {
         cout << " " << setw(2) << board[i][j];
      }
      cout << endl;
   }
}

/*
 * Function: findKnightsTour
 * Usage: flag = findKnightsTour(board, row, col, seq);
 * ----------------------------------------------------
 * This function looks for a tour on the board, starting at
 * the position indicated by row and col. The seq parameter is
 * the sequence number of this move and is needed to keep
 * track of the steps on the tour. The function returns true
 * if a tour is found and false otherwise.
 *
 * This function begins by checking for three simple cases:
 *
 * 1. The position is off the board.
 * 2. The position has been previously visited.
 * 3. The tour is complete.
 *
 * In the first two cases, there can be no tour that begins
 * from that position on the board. In the last case, the
 * function can immediately return true.
 *
 * If the simple cases do not apply, the function marks the
 * current square and then tries all possible moves. If it
 * finds a tour from the resulting position, the function
 * returns true to the next highest level. If no moves lead
 * to a tour, the function must back out of this move and try
 * again at a higher level of the recursion.
 *
 * The for loops in this implementation are a little tricky.
 * They compute the row and column offsets for the next position by
 * noting that the row and column offsets add to 3 (either +1 and +2
 * or +2 and +1) and you need all four possible sign combinations.
 */

// int* getValidNextIdx(int row, int col, int row_dir[], int col_dir[]) {
//     int array[5];
//     int new_row;
//     int new_col;
    


// }
int row_dir [8]= {2, 1, 2, -1, 1, -2, -2, -1};
int col_dir [8]= {1, -2, -1, -2, 2, -1, 1, 2};
// int row_dir [8]= {-2, -1, -2, -1, 2, 1, 1, 2};
// int col_dir [8]= {-1, -2, 1, 2, 1, 2, 2, 1};

bool findKnightsTour(Grid<int> & board, int row, int col, int seq) {
    // TODO
    int n = board.size();
    int m = board[0].size();
    if (seq == 1) {board[0][0] = 1;}
    if (seq == int(n*m)) { return true; }
    int new_row;
    int new_col;
    for (int i = 0; i <= 7; i++) {
        new_row = row + row_dir[i];
        new_col = col + col_dir[i];
        if ( (0 <= new_row && new_row <= n-1)
          && (0 <= new_col && new_col <= m-1) ) {
              if (board[new_row][new_col] == 0)  {
                  board[new_row][new_col] = seq+1;
                  if (findKnightsTour(board, new_row, new_col, seq+1)) {
                     return true;
                  } else {
                     board[new_row][new_col] = 0;
                  }  
             }
        }
    }
    if (seq == 1) {board[0][0] = 0;}
    return false;
}


/* DO NOT modify the main() part */
int main() {
   int n, m;
   cin>>n>>m;
   solveKnightsTour(n, m);
   return 0;
}
