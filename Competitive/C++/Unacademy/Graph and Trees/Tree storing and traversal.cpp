/* Tree storing and traversal */

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

#define ll                       long long int
#define ld                       long double
#define mod                      1000000007
#define inf                      1e18
#define endl                     "\n"
#define pb                       push_back
#define vi                       vector<ll>
#define vs                       vector<string>
#define pii                      pair<ll,ll>
#define ump                      unordered_map
#define mp                       make_pair
#define pq_max                   priority_queue<ll>
#define pq_min                   priority_queue<ll,vi,greater<ll> >
#define all(n)                   n.begin(),n.end()
#define ff                       first
#define ss                       second
#define mid(l,r)                 (l+(r-l)/2)
#define bitc(n)                  __builtin_popcount(n)
#define SET(a)                   memset( a, -1, sizeof a )
#define CLR(a)                   memset( a,  0, sizeof a )
#define Pi                       3.141592653589793
#define loop(i,a,b)              for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)           for(int i=(a);i>=(b);i--)
#define _fast                    ios_base::sync_with_stdio(0);  cin.tie(0);
#define iter(container,it)       for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)             {string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)          for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
template <typename T> T          gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T          lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
cout << *it << " = " << a << endl;
err(++it, args...);
}

/*BFS*/

void bfs (int root, vector<vi> &adj, int n) {
    vi par(n+1);
    par[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {

        int cur = q.front();

        cout << cur << " ";
        q.pop();

        for (auto nb : adj[cur]) {

            if (nb != par[cur]) {
                q.emplace(nb);
                par[nb] = cur;
            }
        }
    }
}

void bfs_level (int root, vector<vi> &adj, int n) {
    vi par(n+1);
    par[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur_sz = q.size();
        while (cur_sz--) {
            int cur = q.front();

            cout << cur << " ";
            q.pop();

            for (auto nb : adj[cur]) {

                if (nb != par[cur]) {
                q.emplace(nb);
                par[nb] = cur;
                }
            }
        }
        cout << "\n";
        
    }
}

/*DFS*/
int level[100] = {}, subtree[100] = {};
void dfs (int cur,int par, vector<vi> adj) {
    
    //cout << cur << " ";
    subtree[cur] = 1;
    level[cur] = level[par] + 1; 
    /* If array of values are given of each node and its asked to calculate the sum of all its parents*/
    // dp[cur] = dp[par] + arr[cur]

    for (int nb : adj[cur]) {
        if (nb == par) continue; 
        
        dfs (nb,cur,adj);
        
        subtree[cur] += subtree[nb];
    }
    
}

void solve() {
    ll n; cin >> n;

    // adjaency list
    vector<vi> adj(n+1) ;
    for (int i = 0; i < n-1; i++) { // n-1 number of edges
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
     dfs (1,0,adj);
    //  cout << "\n";
    //  for (int i=1; i<=n ; i++) {
    //      cout << i << " " << subtree[i] << "\n";
    //  }
    
    //bfs_level(1,adj,n);

   

    // parent array is given and we want in adjancey list
    // vector<vector<int>> adj (n+1);
    // int par[n+1];
    // for (int i=1; i<= n; i++) {
    //     cin >> par[i];
    //     if (par[i] != -1 && par[i] != 0) {
    //         int u = i, v = par[i];
    //         adj[u].pb(v), adj[v].pb(u);
    //     }

    // }

    // for (int i=1; i <= n; i++) {
    //     for (auto nb : adj[i]) 
    //         cout << nb <<" ";
    //         cout << "\n";
    // }

    

}

int main(int argc, char const *argv[]){
    _fast
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}