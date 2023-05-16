//template

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
// longest path of subtree i that starts at i
int downpath[200001];
// diameter of the tree if it includes the root 1
int diameter[200001];
void eval_downpath (int cur, int par, vector<vi>& adj) {
    int bestChildDownpath = 0;
    bool leaf=1;
    for (auto child : adj[cur]) {
        if (child != par) {
            leaf = 0;
            eval_downpath (child,cur,adj);
            bestChildDownpath = max (bestChildDownpath,downpath[child]);
        }
    }
    if (leaf) downpath[cur] = 0;
    else downpath[cur] = 1 + bestChildDownpath; 
}

void dfs (int cur, int par, vector<vi>& adj) {
    int ans = 0; // root 1 not included
    vi childrenDownpaths;
    for (auto child : adj[cur]) {
        if (child != par) {
            dfs(child,cur,adj);
            childrenDownpaths.pb(downpath[child]);
            ans = max (ans,diameter[child]);
        }
    }
    int numOfChildren = childrenDownpaths.size();
    sort (all(childrenDownpaths));
    if (numOfChildren == 0) diameter[cur] = 0;
    else if (numOfChildren == 1) diameter[cur] = 1 + childrenDownpaths[0];
    else  diameter[cur] = 2 + childrenDownpaths[numOfChildren-1] + childrenDownpaths[numOfChildren-2];

    diameter[cur] = max(ans,diameter[cur]); // to choose root u or not
}
void solve() {
    ll n; cin >> n;
    vector<vi> adj(n+1);
    loop (i,1,n-1) {
        ll u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    eval_downpath (1,0,adj);
    dfs(1,0,adj);
    cout << diameter[1];
}

int main(int argc, char const *argv[]){
    _fast
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}