//template

#include<bits/stdc++.h>
#include<functional>
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
ll n,m,cmp=0;




vector<pii> adj[1005][1005];


void bfs(pii src , vector<vector<bool>>& vis) {
    queue<pii> q;
    q.emplace(src);

    vis[src.ff][src.ss] = 1;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (pii ch : adj[cur.ff][cur.ss]) 
            if (!vis[ch.ff][ch.ss]) 
                q.emplace(ch),vis[ch.ff][ch.ss] = 1;
    }
}

void solve() {
    cin >> n >> m;
    char grid[n][m];

    vector<pii> nodes;

    loop (i,0,n-1) 
        loop (j,0,m-1) { 
            cin >> grid[i][j];
            if (grid[i][j] == '.') nodes.pb({i,j});
        }
    
    ll dr[4] = {-1,1,0,0};
    ll dc[4] = {0,0,-1,1};

    

    loop (i,0,n-1) 
        loop (j,0,m-1) { 
            if (grid[i][j] == '.') {
                loop (k,0,3) {
                    if (i+dr[k] >= 0 && i+dr[k] < n && j+dc[k] >= 0 && j+dc[k] < m && grid[i+dr[k]][j+dc[k]] == '.') {
                        adj[i+dr[k]][j+dc[k]].pb({i,j});
                        adj[i][j].pb({i+dr[k],j+dc[k]});
                    }
                }
            }
        }

    vector<vector<bool>> vis(n+1,vector<bool> (m+1,0));
    for (pii i : nodes) {
        ll u = i.ff,v=i.ss;
        if (!vis[u][v]) 
            bfs(i,vis),cmp++;
    }

    cout << cmp ;
}

int main(int argc, char const *argv[]){
    _fast
    //fileIO();
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}