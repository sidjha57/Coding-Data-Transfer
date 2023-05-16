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
// #define pii                      pair<ll,ll>
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

const long long INF = 1000000000000000;
vector<vector<pair<long long, long long>>> adj;

    void dijkstra(long long s, vector<long long> & d, vector<long long> & p) {
        int n = adj.size();
        d.assign(n, INF);
        p.assign(n, -1);
    
        d[s] = 0;
        using pii = pair<long, long>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, s});
        while (!q.empty()) {
            long long v = q.top().second;
            long long d_v = q.top().first;
            q.pop();
            if (d_v != d[v])
                continue;
    
            for (auto edge : adj[v]) {
                long to = edge.first;
                long len = edge.second;
    
                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    p[to] = v;
                    q.push({d[to], to});
                }
            }
        }
    }
    long long minimumCost(int n, int m, int x, vector<int> &A,
                          vector<vector<int>> &B) {
        
        map<pair<int,int>,bool> vis;
        adj = vector<vector<pair<long long, long long>>> (n+1);
        
        for (int i=0; i<m; i++) {
            if (vis.find({B[i][0],B[i][1]}) == vis.end() &&   vis.find({B[i][0],B[i][1]}) == vis.end()) {
                long long val = A[B[i][0]-1] + A[B[i][1]-1];
                adj[B[i][0]].push_back({B[i][1],val});
                adj[B[i][1]].push_back({B[i][0],val});
                vis[{B[i][0],B[i][1]}] = 1;
                vis[{B[i][1],B[i][0]}] = 1;
                
            }
        }
        vector<long long> d,p;
        dijkstra(1,d,p);
        long long val;
        val = x;
        val += A[0];
        val += A[n-1];
        cout << x << " " <<  A[0] << " " << A[n-1] << "\n";
        cout << val << " " << d[n] << " ";
        return min(d[n],val);
        
    }
void solve() {
    int n,m,x; cin >> n>>m >>x;
    vector<int> a(n);
    for (int i=0; i<n;i++) cin >> a[i];
    vector<vector<int>> b(m,vector<int>(2,0));
    for (int i=0; i<m; i++) cin >> b[i][0] >> b[i][1];
    long long ans = minimumCost(n,m,x,a,b);
    cout << ans;
}
int main(int argc, char const *argv[]){
    _fast
  #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
  #endif
    

     solve();
    
  return 0;
}