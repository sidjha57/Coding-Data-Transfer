#include <bits/stdc++.h> 
using namespace std;

int paths (int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;
    
    if (dp[i][j]) return dp[i][j];
    
    return dp[i][j] = paths(i-1, j, dp) + paths(i, j-1, dp);
}
int uniquePaths(int m, int n) {
// 	return paths(n-1,m-1);
    
    vector<vector<int>> dp(n, vector<int> (m,0));
//     return paths(n-1, m-1, dp);
//     dp[0][0] = 1;
    
//     for (int i=0; i<n; i++) {
//         for (int j=0; j<m; j++) {
//             if (i > 0) dp[i][j] += dp[i-1][j];
//             if (j > 0) dp[i][j] += dp[i][j-1];
//         }
//     }
    
    
//     return dp[n-1][m-1];
    
    vector<int> cur(m,0), prev(m,0);
    cur[0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i > 0) cur[j] += prev[j];
            if (j > 0) cur[j] += cur[j-1];
        }
        prev = cur;
        for (int j=0; j<m; j++) {
            cout << cur[j] << " ";
            cur[j] = 0;
        }
        cout << "\n";
    }
    return prev[m-1];
}

int main() {
    cout << uniquePaths(3,3);
}