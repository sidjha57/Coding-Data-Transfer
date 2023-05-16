//template

#include<bits/stdc++.h>
#define ll                       long long int
#define pb                       push_back
#define vi                       vector<ll>

using namespace std;

ll *dp;
void dfs (int cur, int par, vector<vi> adj) {

    vi childrens;
    for (auto nb : adj[cur]) {
        if (nb == par) continue;
        
        dfs(nb,cur,adj);

        // we got all the dp values
        childrens.pb(dp[nb]);
    }
    // the subtree which takes maximum time needs to be burnt first 
    sort (childrens.rbegin(), childrens.rend()); // sorted in reverse order
    ll secs=1;
    dp[cur] = 0;
    for (auto val: childrens) {
        dp[cur] = max (dp[cur], secs+val);
        secs++;
    }
}

int main(int argc, char const *argv[]){
    
    //adjancecy list
    ll n; cin >> n;
    dp = new ll [n+1];
    vector <vi> adj(n+1);
    for (int i=0; i< n-1; i++) {
        int u,v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs (1,0,adj);
    cout << dp[1];

  return 0;
}