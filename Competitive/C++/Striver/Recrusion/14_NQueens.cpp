#include <bits/stdc++.h>

using namespace std;

 bitset<10> column,left_diag,right_dia;
    int ways = 0,n;
    vector<vector<string>> ans;
void display (int n, vector<vector<int>>& board) {
    vector<string> vec;
	for (int i=0;i<n; i++) {
        string s="";
	    for (int j=0;j<n;j++) {
            if (board[i][j] == 0)
			    s += ".";
            else
                s += "Q";
		}
        cout << s << "\n";
        // vec.emplace_back(s);
    }
    cout << "\n\n";
    // ans.emplace_back(vec);
}
void Nqueens (int cur_row, vector<vector<int>> &board) {
	if (cur_row == n) {
		ways++;
        display(n,board);
		return;
	}

	for (int col=0;col<n;col++) {
		if (!column[col] && !left_diag[cur_row-col+n] && !right_dia[cur_row+col]) {
			column[col] = left_diag[cur_row-col+n] = right_dia[cur_row+col] = board[cur_row][col] = 1;
			Nqueens (cur_row+1,board);
			column[col] = left_diag[cur_row-col+n] = right_dia[cur_row+col] = board[cur_row][col] = 0;
		}
	}
	
}
vector<vector<string>> solveNQueens(int N) {
        n = N;
        vector<vector<int>> board(n,vector<int> (n,0));
	    Nqueens(0,board);
        return ans;
}

int main() {
    solveNQueens(5);

}