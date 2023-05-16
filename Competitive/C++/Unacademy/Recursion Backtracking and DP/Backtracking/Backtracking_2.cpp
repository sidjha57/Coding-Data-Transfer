#include <bits/stdc++.h>

using namespace std;

/* given an n*n chessboard, find the number of ways to place 
   n queens in such a way that no queen attacks each other */ 
int cnt = 0;
void QueensonBoard (vector<vector<bool>> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j]) cout << "Q ";
            else cout << ". ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}
bool isSafe (int cur_row, int cur_col, int n,vector<vector<bool>>& board) {

    // upper column
    for (int i= cur_row-1; i >= 0; i--) 
        if (board[i][cur_col]) return false; 
    
    // upper left diagonal
    for (int i=cur_row-1, j=cur_col-1; i>=0 && j>=0; i--,j--) 
        if (board[i][j]) return false;
    
    // upper right diagonal
    for (int i=cur_row-1, j=cur_col+1; i>=0 && j<n; i--,j++)
        if (board[i][j]) return false;
    
    return true;
}

void NQueens (int cur_row, int n,vector<vector<bool>>& board) {
    //base case
    if (cur_row == n) {
        // we found one way
        cnt++;
        QueensonBoard (board);
        return;
    }
    
    for (int j = 0; j < n; j++) {
        // j will go to each column
        if (isSafe(cur_row,j,n,board)) {
            board[cur_row][j] = true;
            NQueens (cur_row+1,n,board);
            board[cur_row][j] = false; // reinitialisation
        }
    }
}

/* given a n*n board with a knight at (0,0).Check if the knight can cover all the 
   cells of the board and print the steps, using it's usual chess moves without using any cell twice */
void display (vector<vector<int>>& board, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}
bool IsitSafe (int i, int j,int n, vector<vector<bool>>& visited) {
    return i>=0 and j>=0 and i < n and j < n and visited[i][j] == 0;
}
void Knighthstour (int count,int i,int j,int n, vector<vector<int>>& board,vector<vector<bool>>& visited) {
    // base case
    if (count == n*n - 1) {
        board[i][j] = count;
        display(board,n);
        cout << "\n\n";
        return;
    }
    if (count >= n*n) return;
    int xdir[8] = {2, 2,-2,-2,1,-1, 1,-1};
    int ydir[8] = {1,-1, 1,-1,2, 2,-2,-2};

    visited[i][j] = true;
    board[i][j] = count;
    for (int k =0; k<8; k++) {
        if (IsitSafe(i+xdir[k],j+ydir[k],n,visited)) {
            Knighthstour (count+1,i+xdir[k],j+ydir[k],n,board,visited);
        }
    }
    visited[i][j] = false;
    board[i][j] = -1;
}


int main () {
    int n; cin >> n;
    // vector<vector<bool>> board (n,vector<bool>(n,false));
    // NQueens (0,n,board);
    // cout << cnt;
    vector<vector<bool>> visited (n,vector<bool>(n,false));
    vector<vector<int>> board (n,vector<int>(n,-1));
    Knighthstour(0,0,0,n,board,visited);
}