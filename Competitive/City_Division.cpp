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


/*  Horizontal
    Dp(i1,j1,i2,j2) = min (dp(i1,j1,k,j2) + dp(k+1,j1,i2,j2) + w*(j2-j1+1) ) 
        j1 <= k <= j2-1

    Vertical
    Dp(i1,j1,i2,j2) = min (dp(i1,j1,i2,l) + dp(i1,l+1,i2,j2) + w*(i2-i1+1) )
        i1 <= l <= i2-1
*/

ll a,b,c,d,w,n,m;
map <ll,ll> cost;
vector<vi> grid(25,vi(25,0));
ll dp[25][25][25][25]; // dp[i1][j1][i2][j2] => minimum cost such that it fullfills the conditions from submatrix i1,j1 to i2,j2

ll gold_mines (vector<vi>& grid,ll i1, ll j1, ll i2, ll j2) {
   return grid[i2][j2] - grid[i2][j1-1] - grid[i1-1][j2] + grid[i1-1][j1-1];
}

ll cityDivision (ll i1, ll j1, ll i2, ll j2) {
    ll &ans = dp[i1][j1][i2][j2];
    if (ans != -1) return ans;

    ans = inf;

    ll cnt = gold_mines(grid,i1,j1,i2,j2);

    if (cnt == 0) return ans = cost[0];
    else if (cnt < 4) ans = cost[cnt];

    //horizontal  
    loop (k,i1,i2-1) ans = min (ans, cityDivision(i1,j1,k,j2) + cityDivision(k+1,j1,i2,j2) + w*(j2-j1+1));

    //vertical
    loop (l,j1,j2-1) ans = min (ans, cityDivision(i1,j1,i2,l) + cityDivision(i1,l+1,i2,j2) + w*(i2-i1+1));

    return ans;

    // 20^4*(20+20) => 80^5
}


void solve() {
    cin >> a >> b >> c >> d >> w >> n >> m;
    cost[0] = a, cost[1] = b, cost[2] = c, cost[3] = d;

    loop (i,1,n)
        loop (j,1,m)
            cin >> grid[i][j];
    
    // prefix sum
    loop (i,1,n) 
        loop (j,1,m)
            grid[i][j] += grid[i-1][j];

    loop (i,1,n) 
        loop (j,1,m)
            grid[i][j] += grid[i][j-1];

    //cout << gold_mines(grid,1,1,2,4);

    loop (i,0,24) loop (j,0,24) loop (k,0,24) loop (l,0,24) dp[i][j][k][l] = -1;
    cout << cityDivision(1,1,n,m);
     
  
}

int main(int argc, char const *argv[]){
    _fast
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}