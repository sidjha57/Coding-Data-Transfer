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

void solve() {
    ll n,m,x1,y1,x2,y2,ch; cin >> n >> m;
    vector<vi> grid(n,vi(m,0));
    cin >> x1 >> y1;
    grid[x1-1][y1-1] = 1;
    cin >> x2 >> y2;
    grid[x2-1][y2-1] = 2;

    queue<pii> q;
    
    q.push({x1-1,y1-1});

    ll dx[4] = {0, 0, 1, -1},
       dy[4] = {1, -1, 0, 0};

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
    
        if (grid[cur.ff][cur.ss] == 1) ch = 2;
        else ch = 1;

        loop (i,0,3) {
            ll x = cur.ff + dx[i], y = cur.ss + dy[i];
            if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 0) {
                q.push({x,y});
                grid[x][y] = ch;
            }
        }
    }

    map<pii,bool> vis;

    vis[{x2-1,y2-1}] = 1;
    q.push({x2-1,y2-1});

    while (!q.empty()) {
        pii cur = q.front();
        vis[cur] = 1;
        q.pop();
    
        if (grid[cur.ff][cur.ss] == 2) ch = 3;
        else ch = 2;

        loop (i,0,3) {
            ll x = cur.ff + dx[i], y = cur.ss + dy[i];
            if (x >= 0 && y >= 0 && x < n && y < m && vis.find({x,y}) == vis.end() && grid[cur.ff][cur.ss] == grid[x][y]) {
                q.push({x,y});
                grid[x][y] = ch;
            }
        }
    }

    loop (i,0,n-1) {
        loop (j,0,m-1)
            cout << grid[i][j] << " ";
        cout << "\n";
    }

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