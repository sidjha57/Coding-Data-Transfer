//template

#include<bits/stdc++.h>
#define ll                       long long int
#define pb                       push_back
#define vi                       vector<ll>

using namespace std;
/* Find the size of minimum vertex cover of a tree
1) No adjacent nodes present 
2) All edges should be covered */
vi in,out;
ll tim = 0,dp[100001][20];
void dfs (int cur, int par, vector<vi> adj) {

      dp[cur][0] = par;
      in[cur] = ++tim;    

      for (int i=0;i<20;i++) {
          int two_i_minus_1 = dp[cur][i-1];
          dp[cur][i] = dp[two_i_minus_1][i-1];
      }    

       for (auto nb : adj[cur]) 
           if (nb != par) 
             dfs(nb,cur,adj);

      out[cur] = ++tim;
           
}

bool is_u_ancestor_of_v (int u, int v) {
    return in[u] >= in[v] && out[u] <= out[v];
}

int find_lca (int u, int v) {
    if (is_u_ancestor_of_v(u,v)) return u;
    if (is_u_ancestor_of_v(v,u)) return v;

    for (int i=19;i>=0;i--) 
        if (!is_u_ancestor_of_v(dp[u][i],v))
            u = dp[u][i];
    return dp[u][0];
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
    int u,v;
    cin >> u >> v;
    cout << find_lca(u,v); 

  return 0;
}