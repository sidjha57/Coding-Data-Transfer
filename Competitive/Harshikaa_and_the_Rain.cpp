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
#define pq_max                   priority_timeue<ll>
#define pq_min                   priority_timeue<ll,vi,greater<ll> >
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
void dfs(ll cur, ll par, vector<vi>& adj, vi& level, vi& leaf) {
    level[cur] = level[par]+1;
    ll le = 1;
    for (ll ch : adj[cur]) {
        if (ch != par) {
            le = 0;
            dfs(ch,cur,adj,level,leaf);
        }
    }
    if (le) leaf[cur] = 1;
}

void solve() {
    ll n,m,ans=0; cin >> n >> m;
    vector<vi> adj(n+1);
    map<ll,ll> time;
    vi leafs;
    vi q (m),level(n+1,0),leaf(n+1,0);

    loop (i,1,n-1) {
        ll u,v; cin >> u >> v;
        adj[u].pb(v),adj[v].pb(u);
    }
  
    loop (i,0,m-1) cin >> q[i];
    time[q[0]-1]++;
    loop (i,1,m-1) 
        time[q[i]-q[i-1]-1]++;
    
    level[0] = -1;
    dfs(1,0,adj,level,leaf);
    // loop (i,1,n) cout << i << " " << level[i] << " " << leaf[i] << "\n";

    loop (i,1,n) 
        if (leaf[i]) leafs.pb(level[i]);
    
    sort(all(leafs));

    vi pre(leafs.size(),0);

    pre[0] = leafs[0];
    loop (i,1,leafs.size()-1) pre[i] = leafs[i] + pre[i-1];

    // loop (i,0,pre.size()-1) cout << leafs[i] << " " << pre[i] << "\n";

    for (auto tim = time.begin(); tim != time.end(); ++tim) {
       ll k = upper_bound(leafs.begin(),leafs.end(),tim->ff) - leafs.begin();
       //cout << k << " " << tim->ff << "\n";
       ll a = (k*tim->ff - pre[k-1] + k)*tim->ss;
       if (a > 0)
       ans += a; 
        // for (auto le = leafs.begin(); le != leafs.end(); ++le) {
        //     if (le->ff <= tim->ff) {
        //         ll contri = (tim->ff-le->ff+1);
        //         ans += contri*tim->ss*le->ss;
        //     } else {
        //         break;
        //     }
        // }
    }

    cout << ans << "\n";
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