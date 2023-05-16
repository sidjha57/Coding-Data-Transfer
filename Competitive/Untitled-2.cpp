//Siddharth Jha

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

#define ll                       long long int
#define mod                      1000000007
#define inf                      1e18
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
#define loop(x,start,end)        for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define _fast                    ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
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
void dfs (int node, vector<vector<pair<int,int>>>& adj, vector<bool>& vis, int& siz, bool& flag) {
    vis[node] = 1;
    siz++;
    for (auto ch : adj[node]) {
        if (!vis[ch.first]) {
            if (!ch.second) flag = 0;
            dfs(ch.first,adj,vis,siz,flag);
        }
    }
}
void solve() {
    int n,a,b; cin >> n >> a >> b;
    
    vector<vector<int>> land(a,vector<int>(2)), water(b,vector<int>(2));
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i=0; i<a; i++) {
        cin >> land[i][0] >> land[i][1];
        int u = land[i][0], v = land[i][1];
        adj[u].pb({v,1}), adj[v].pb({u,1});
       
    }
    for (int i=0; i<b; i++) {
        cin >> water[i][0] >> water[i][1];
        int u = water[i][0], v = water[i][1];
        adj[u].pb({v,0}), adj[v].pb({u,0});
    }
    
    int mx = 0;
    vector<bool> vis(n+1,0);
    for (int i=1; i <= n; i++) {
       if (!vis[i]) {
        int siz = 0;
        bool flag = 1;
        dfs(i,adj,vis,siz,flag);
        if (flag) mx = max(mx,siz);
       }
    }
    cout << mx << "\n";
}

int main(int argc, char const *argv[]){
    _fast
  //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
  //#endif
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}