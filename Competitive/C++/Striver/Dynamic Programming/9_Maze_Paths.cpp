#include<bits/stdc++.h>
using namespace std;
#define mod 100000007;

int paths(int n, int m, vector< vector< int> > &mat) {
    if (n < 0 || m < 0) return 0;
    if (mat[n][m] == -1) return 0;
    if (n == 0 && m == 0) return 1;
    
    return (paths(n-1,m,mat) + paths(n,m-1,mat)) % mod;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    return paths(n, m, mat);
}

int main() {
    vector<vector<int>> mat 
    {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };
    cout << mazeObstacles(2,2,mat);
}