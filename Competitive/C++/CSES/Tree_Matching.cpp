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
int dp[200005][2];
void dfs (int cur, int par, vector<vi>& adj) {
  vi prefix,suffix;
  dp[cur][0] = 0 , dp[cur][1] = 0;
  bool leaf =1;
  for (auto child : adj[cur]) {
    if (child != par) {
      leaf = 0;
      dfs(child,cur,adj);
    }
  }
  if (leaf) return; // if its leaf node just return

  for (auto child : adj[cur]) {
    if (child != par) {
      prefix.pb (max(dp[child][0],dp[child][1]));
      suffix.pb (max(dp[child][0],dp[child][1]));
    }
  }

  for (int i=1; i< prefix.size(); i++) 
    prefix[i] += prefix[i-1];
  
  for (int i=suffix.size()-2; i>=0; i--)
    suffix[i] += suffix[i+1];

  dp[cur][0] = suffix[0];

  int c_no = 0;

  for (auto child : adj[cur]) {
    if (child != par) {
      int leftchild = (c_no == 0) ? 0 : prefix[c_no - 1];
      int rightchild = (c_no == suffix.size() - 1) ? 0 : suffix[c_no + 1];

      dp[cur][1] = max (dp[cur][1], leftchild + dp[child][0] + rightchild + 1);
      c_no ++ ;
    }
  }

}
void solve() {
    ll n; cin >> n;
    vector<vi> adj(n+1);
    loop (i,1,n-1) {
      ll u,v; cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    dfs(1,0,adj);
    cout << max (dp[1][0],dp[1][1]);
}

int main(int argc, char const *argv[]){
    _fast
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}