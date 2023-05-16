#include <bits/stdc++.h>
using namespace std;

int ans = 0;

bool isSafe (int row, int col, int n, vector<vector<bool>>& board) {
    if (row-1 >= 0 and col >= 0 and board[row-1][col]) return false;
    if (row >= 0 and col-1 >= 0 and board[row][col-1]) return false;
    if (row-1 >= 0 and col-1 >= 0 and board[row-1][col-1]) return false;
    if (row-1 >= 0 and col+1 <  n and board[row-1][col+1]) return false;
    return true;
}

void Nkings (int cr, int cc, int n, int count, vector<vector<bool>>& board) {
 if (count == n) {
     ans++;
     return;
 }

 for (int row = cr; row <n; row++) {
     for (int col = (row == cr)?cc:0; col < n; col++) {
         if (isSafe(row, col,n,board)) {
             board[row][col] = true;
             Nkings (row,col+1,n,count+1,board);
             board[row][col] = false;
         }
     }
 }
} 
int main() {
 int n; cin >> n;
 vector<vector<bool>> board(n,vector<bool>(n,false));
 Nkings(0,0,n,0,board);
 cout << ans;
}