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

void dfs (int cur, int par, vector<vector<int>>& adj, vector<int>& subtree) {

    bool leaf = 1;
    for (int nb: adj[cur]) {
        if (nb == par) continue;
        leaf = 0;
        dfs (nb,cur,adj,subtree);

        subtree[cur] += subtree[nb];
    }

    if (leaf) subtree[cur] = 1;

}


int optimalValue(int n, int x, vector<int> &p) {
        vector<vector<int>> adj(n+1);
        vector<int> subtree(n+1,0);
        
        for (int i=1; i < n; i++) {
            adj[p[i]].push_back(i+1);
            adj[i+1].push_back(p[i]);
        }
        int sum = 0;
        dfs(1,0,adj,subtree);
        for (int i=1; i<=n ; i++) {
            cout << i << " " << subtree[i] << "\n";
        }

    return subtree[1];
}

int min_cost (int n, int k, vector<int>& arr) {
    int mx=0,sum=0;
    unordered_map<int,int> freq;
    for (int i : arr) {
        freq[i]++;
    }
    for (auto x: freq) {
        mx = max(mx,x.second);
        if (x.second > 1) sum += x.second;
    }

    return min(k+sum,k*mx);
}


void solve() {
    ll n,x; cin >> n >> x;
    vector<int> p(n);
    loop (i,0,n) cin >> p[i];
    cout << optimalValue(n,x,p);
   
}

int main(int argc, char const *argv[]){
    _fast
  //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
  //#endif
    ll t; cin >> t;
    while(t--){
     solve();
    }
  return 0;
}