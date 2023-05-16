#include<bits/stdc++.h>
using namespace std;

bool check (int i, int j, int n, int m) {
    if (i >= 0 && j >= 0 && i < n && j < m) return true;
    return false;
}
int solve(int n, int m, vector<string> &s) {
    priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> pq;
    vector<vector<int>> dis (n, vector<int> (m, INT_MAX));
    dis[0][0] = 0;
    pq.push({0,{0,0}});
    unordered_map<char,pair<int,int>> mp;
    mp['U'] = {-1,0}, mp['R'] = {0,1}, mp['L'] = {0,-1}, mp['D'] = {1,0};
    while (!pq.empty()) {
        pair<int,vector<int>> cur = pq.top(); 
        pq.pop();
        for (auto x : mp) {
            int i = cur.second[0], j = cur.second[1];
            int wt = 1 - (s[i][j] == x.first);
            wt += dis[i][j];
            i += x.second.first, j += x.second.second;
            if (check(i,j,n,m) && wt < dis[i][j]) {
                pq.push({wt,{i,j}});
                dis[i][j] = wt;
            }
        }
    }
    
    return dis[n-1][m-1];
}

int main () {
    vector<string> s {
       "RRRRD", 
       "DLLLL", 
       "RRRRD", 
       "DLLLL", 
       "RRRRR"
    };
    cout << solve (5,5,s);
}