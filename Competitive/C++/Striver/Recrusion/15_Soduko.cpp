#include<bits/stdc++.h>

using namespace std;

bool isSafe (vector<vector<char>> &board,int row,int col, int num) {
        for (int i=0;i<9;i++) {
            if (board[row][i] - '0' == num) return false;

            if (board[i][col] - '0' == num) return false;

            if (board[3 * (row/3) + i/3][3 * (col/3) + i%3] - '0' == num) return false;
        } 
        return true;
        
    }
    bool sudoku (vector<vector<char>> &board,int row, int col) {
        if (col == 9) return sudoku(board,row+1,0);
        if (row == 9) return true;
        if (board[row][col] == '.') {
            for (int num =1;num<=9;num++) {
                if (isSafe(board,row,col,num)) {
                    board[row][col] = '0' + num;
                    bool res = sudoku (board,row,col+1);
                    if (res) return true;
                    board[row][col] = '.';
                }
                
            }
            return false;
        }
        else return sudoku(board,row,col+1);
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board,0,0);
    }


int main() {

}