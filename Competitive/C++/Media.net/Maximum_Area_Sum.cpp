#include <bits/stdc++.h>
using namespace std;

int maximumAreaSquare(vector<vector<int>>& MAT, int n, int m)
{
    int mx=0;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {  
            if (i-1 >= 0) MAT[i][j] += MAT[i-1][j];
            if (j-1 >= 0) MAT[i][j] += MAT[i][j-1];
            if (i-1 >= 0 && j-1 >= 0) MAT[i][j] -= MAT[i-1][j-1];
            if (MAT[i][j] >= 1) mx = 1;
        }
    }
    
    for (int siz=1; siz < n; siz++) {
        for (int i2 = siz; i2 < n; i2++) {
            for (int j2 = siz; j2 < m; j2++) {
                int i1 = i2-siz, j1 = j2-siz, ans = MAT[i2][j2];
                if (i1-1 >= 0 && j1-1 >= 0) ans += MAT[i1-1][j1-1];
                if (i1-1 >= 0) ans -= MAT[i1-1][j2];
                if (j1-1 >= 0) ans -= MAT[i2][j1-1];
                if (ans == (siz+1)*(siz+1)) {
                    mx = max(mx,(siz+1)*(siz+1));
                }
            }
        }
    }
    return mx;
}

int main () {
    int t; cin >> t;
    while (t--) {
        int n,m; cin >> n >> m;
        vector<vector<int>> MAT(n, vector<int> (m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m;j++) cin >> MAT[i][j];
        }
        cout << maximumAreaSquare(MAT,n,m) << "\n";
    }
}