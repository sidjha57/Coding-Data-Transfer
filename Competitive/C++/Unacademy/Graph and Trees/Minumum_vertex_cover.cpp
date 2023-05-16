//template

#include<bits/stdc++.h>
#define ll                       long long int
#define pb                       push_back
#define vi                       vector<ll>

using namespace std;
/* Find the size of minimum vertex cover of a tree
1) No adjacent nodes present 
2) All edges should be covered */
ll dp[100001][2];
void dfs (int cur, int par, vector<vi> adj) {

    /* 0 ->  It indicates that the current node is not considered only its children are
       1 ->  It indicates that the current node is selected therefore children will be skipped +1 */
       dp[cur][0] = 0;
       dp[cur][1] = 1;

       for (auto nb : adj[cur]) {
           if (nb == par) continue;

           dfs(nb,cur,adj);
           dp[cur][0] += dp[nb][1];
           dp[cur][1] += dp[nb][0];
       }
}

int main(int argc, char const *argv[]){
    
    //adjancecy list
    ll n; cin >> n;
    vector <vi> adj(n+1);
    for (int i=0; i< n-1; i++) {
        int u,v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs (1,0,adj);
    cout << min(dp[1][0],dp[1][1]);

  return 0;
}