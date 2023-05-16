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
#define eb                       emplace_back
#define em                       emplace
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
#define loop(i,a,b)              for(ll i=(a);i<=(b);i++)
#define looprev(i,a,b)           for(ll i=(a);i>=(b);i--)
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

void fileIO() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
char grid[50][50];
ll r,c,mx;
// map<pii,vector<pii>> adj;
// map<pii,bool> vis;
vector<pii> vis(2505);
vector<pii> adj[2505][2505];

void dfs (pii cur, ll cnt) {
    mx = max(cnt,mx);
    for (pii ch : adj[cur.ff][cur.ss]) {
        if (grid[ch.ff][ch.ss] - 1 == grid[cur.ff][cur.ss]) 
            dfs(ch,cnt+1);
    }
}

void add_edges (ll i, ll j) {
    ll dr[8] = {-1,-1,-1,0,0,1,1,1};
    ll dc[8] = {-1,0,1,-1,1,-1,0,1};
    loop (k,0,7) {
        if (i+dr[k] >=0 && i+dr[k] < r && j+dc[k] >=0 && j+dc[k] < c) 
            adj[i][j].pb({i+dr[k],j+dc[k]});
    }
}
void solve(ll test) {
    vis.clear();
    vis.resize(r*c+5);
   
    loop (i,0,r-1) {
        string str; cin >> str;
        loop (j,0,c-1) {
            adj[i][j].clear();
            grid[i][j] = str[j];
        }
    }
    
    loop (i,0,r-1)
        loop (j,0,c-1) {
            add_edges(i,j);
        }
    
    mx = 0;
    loop (i,0,r-1)
        loop (j,0,c-1) 
            if (grid[i][j] == 'A') {
              pii cur = {i,j};
              dfs(cur,1);
              vis.clear();
              vis.resize(r*c+5);
            }
    cout << "Case " << test << ": " << mx << "\n";  
}

int main(int argc, char const *argv[]){
    _fast
    //fileIO();
    ll test = 1;
    while(true){
     cin >> r >>c;
     if (r == 0 && c == 0) break;
     solve(test);
     test++;
    }
  return 0;
}