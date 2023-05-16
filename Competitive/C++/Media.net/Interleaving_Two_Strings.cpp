#include<bits/stdc++.h>
using namespace std;

bool isInterleaveUtil (string& a, string& b, string& c, int i, int j, int k, map<pair<int,int>,bool>& dp) {
    if (i == 0 && j == 0 && k == 0) return dp[{i,j}] = 1;
    
    if (dp.find({i,j}) != dp.end()) return dp[{i,j}];
    
    if (i+j != k) return dp[{i,j}] = 0;
    
    if (i > 0 && j > 0 && k > 0 && a[i-1] == c[k-1] && b[j-1] == c[k-1]) 
        return dp[{i,j}] = isInterleaveUtil(a,b,c,i-1,j,k-1,dp) || isInterleaveUtil(a,b,c,i,j-1,k-1,dp);
    
    else if (i > 0 && k > 0 && a[i-1] == c[k-1]) 
        return dp[{i,j}] = isInterleaveUtil(a,b,c,i-1,j,k-1,dp);
    
    else if (j > 0 && k > 0 && b[j-1] == c[k-1]) 
        return dp[{i,j}] = isInterleaveUtil(a,b,c,i,j-1,k-1,dp);
    
    else
        return dp[{i,j}] = 0;
        
}

bool isInterleave(string a, string b, string c){
    map<pair<int,int>,bool> dp;
    return isInterleaveUtil(a,b,c,a.size(),b.size(),c.size(),dp);
}

int main () {
    int n; cin >> n;
    string a,b,c;
    for (int i=0; i<n; i++) {
        cin >> a >> b >> c;
        cout << isInterleave(a,b,c) << "\n";
    }
}