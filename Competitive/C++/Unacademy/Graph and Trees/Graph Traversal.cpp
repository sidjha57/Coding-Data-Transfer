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
vector<vi> adj(1000005);
vi dis;
ll cmp = 0,n,m; 
void bfs_util (ll src, vector<bool>& vis ) {
    
    queue<ll> trav;
    dis.clear();
    dis.resize(n+1);

    trav.push(src);
    vis[src] = 1;
    dis[src] = 0;

    while (!trav.empty()) {
        ll cur = trav.front();
        cout << cur << " ";
        trav.pop();

        for (ll nb : adj[cur]) 
            if (!vis[nb]) {
                trav.push(nb), vis[nb] = 1;
                dis[nb] = dis[cur] + 1;
            }   
    }
}

void bfs () {
    vector<bool> vis(n+1);
    loop (i,1,n) 
        if (!vis[i]) {
            bfs_util(i,vis);
            cout << '\n';
            cmp++;
        }
}

void dfs_util (ll i, vector<bool>& vis) {

    cout << i << " ";
    vis[i] = 1;

    for (ll nb : adj[i]) 
        if (!vis[nb]) 
            dfs_util(nb,vis);
    
}

void dfs () {
    vector<bool> vis(n+1);
    loop (i,1,n) 
        if (!vis[i]) {
            dfs_util(i,vis);
            cout << "\n";
        }
}

void cycle (ll cur, ll b, vi& cyc, vi& vis) {
    if (cur == b) return;
    vis[cur] = 1;
    cyc.eb(cur);
    for (ll ch : adj[cur]) {
        if (!vis[ch]) 
            cycle (ch,b,cyc,vis); 
    }
    if (cyc.size() > 0)
    cyc.pop_back();
}

bool dfs_util_cycle_detect (ll i, ll par, vector<bool> vis) {

    vis[i] = 1;

    for (ll nb : adj[i]) {
        if (nb == par) continue;

        if (vis[nb]) {
            // to print from nb to i
            vi cyc,vis(n+1);
            cycle(nb,i,cyc,vis);
            loop(i,0,cyc.size()-1) cout << cyc[i] << " ";
            return 1;
        }

        bool cyc = dfs_util_cycle_detect (nb,i,vis);

        if (cyc) return 1;
    }
    return 0;
}

bool dfs_cycle_detect () {
    vector<bool> vis(n+1);
    loop (i,1,n) 
        if (!vis[i]) {
            bool cyc = dfs_util_cycle_detect(i,-1,vis);
            if (cyc) return 1;
        }
    
    return 0;
}

void solve() {
    cin >> n >> m;
    loop (i,1,m) {
        ll u,v; cin >> u >> v;
        adj[u].pb(v),adj[v].pb(u);
    }
    cout << "\nBFS call\n";
    bfs();
    cout << "\nDFS call\n";
    dfs();
    loop (i,1,n) 
        cout << i << " " << dis[i] << "\n";

    cout << "\nDFS Cycle\n";
    cout << dfs_cycle_detect() << "\n";

    
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