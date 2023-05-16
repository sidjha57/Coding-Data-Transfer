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

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

vector<vi> adj(100005);

vi subtree_max(100005),weight(100005);
ll ans = 0,mx=-inf;
void dfs (ll cur, ll par) {

    subtree_max[cur] = weight[cur];
    for (auto ch : adj[cur]) {
        if (ch != par) {
            dfs (ch,cur);
            subtree_max[cur] = max (subtree_max[cur], subtree_max[ch]);
        }
    }
    ans = (ans + (mx - subtree_max[cur])%mod)%mod;
    
}

void solve() {
    ll root,n; cin >> n; 
    
    adj.clear();
    adj.resize(n+1);
    subtree_max.clear();
    subtree_max.resize(n+1,-1);
    mx= -inf;
    ans = 0;
    
    loop (i,1,n-1) {
        ll u,v,wt; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    loop (i,1,n) {
         cin >> weight[i];
         if (weight[i] > mx) {
            root = i;
            mx = weight[i];
        }
    }
    //subtree_max[root] = mx;
    //log (root);
    dfs (root,0);
    // ll ans;
    ll div_n = binpow(n-1,mod-2,mod);
    // loop (i,1,n) {
    //     ans = (ans + ((mx - subtree_max[i])%mod)%mod); 
    //     //ans = (ans + (mx - subtree_max[i])/(n-1));
    // }
    ans = (ans * div_n)%mod;
    cout << ans << "\n";
}

int main(int argc, char const *argv[]){
    _fast
    //fileIO();
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}