//https://atcoder.jp/contests/dp/tasks/dp_g


#include<bits/stdc++.h>

using namespace std;

#define SET(a)                   memset( a, -1, sizeof a )
#define loop(i,a,b)              for(int i=(a);i<=(b);i++)
#define _fast                    ios_base::sync_with_stdio(0);  cin.tie(0);


vector <int> graph[100005];
int dp[100005];
int FindlongestPath (int& src) {
    if (dp[src] != -1) return dp[src];
    int result = INT_MIN;
    bool noNeighbors = true; 
    for (auto neighbors: graph[src]) {
        noNeighbors = false;
        result = max(result, FindlongestPath(neighbors));
    }

    return dp[src] = (noNeighbors) ? 0: result + 1;
}
void solve() {
    int n,m; cin >>n >>m;
    loop(i,1,m) {
        int a,b; cin >>a >>b;
        graph[a].emplace_back(b);
    }
    SET(dp);
    int ans = INT_MIN;
    loop (src,1,n) {
        ans = max(ans,FindlongestPath(src));
    }
    cout << ans;
}

int main(int argc, char const *argv[]){
    _fast
    int t=1;
    while(t--){
     solve();
    }
  return 0;
}