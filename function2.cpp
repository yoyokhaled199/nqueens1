#include<bits/stdc++.h>
using namespace std;
#define N 4
/* ld is an array where its indices indicate row-col+N-1
 (N-1) is for shifting the difference to store negative
 indices */
int ld[30] = { 0 };
/* rd is an array where its indices indicate row+col
   and used to check whether a queen can be placed on
   right diagonal or not*/
int rd[30] = { 0 };
/*column array where its indices indicates column and
  used to check whether a queen can be placed in that
    row or not*/
int cl[30] = { 0 };
/* A utility function to print solution */

bool solveNQUtil(int board[N][N], int col)
{
    /* base case: If all queens are placed
      then return true */
    if (col >= N)
        return true;
 
    /* Consider this column and try placing
       this queen in all rows one by one */
    for (int i = 0; i < N; i++) {
        /* Check if the queen can be placed on
          board[i][col] */
        /* A check if a queen can be placed on
           board[row][col].We just need to check
           ld[row-col+n-1] and rd[row+coln] where
           ld and rd are for left and right
           diagonal respectively*/
        if ((ld[i - col + N - 1] != 1 && rd[i + col] != 1) && cl[i] != 1) {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;
 
            /* recur to place rest of the queens */
            if (solveNQUtil(board, col + 1))
                return true;
 
            /* If placing queen in board[i][col]
               doesn't lead to a solution, then
               remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;
        }
    }
 
    /* If the queen cannot be placed in any row in
        this column col  then return false */
    return false;
}
