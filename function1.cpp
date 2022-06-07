
/* C++ program to solve N Queen Problem using
   backtracking */
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
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout<<" "<< board[i][j]<<" ";
        cout<<endl;
    }
}
 
