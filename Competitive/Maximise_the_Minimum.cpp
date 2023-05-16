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
#define loop(i,a,b)              for(ll i=(a);i<=(b);i++)
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
ll max_min (ll i, ll k, ll n, ll suma, ll sumb, vi& a, vi& b, vector<pii>& A, vector<pii>& B, ll& j) {
    if (k == 0) 
        return min(suma,sumb);
    if (i == n) 
        return min(suma,sumb);
    
    ll case1 = max_min(i+1,k-1,n,suma+a[i],sumb + b[i],a,b,A,B, j);
    ll case2 = max_min(i+1,k,n,suma,sumb,a,b,A,B, j);
    return max(case1,case2);
}

void test () {
    ll n,k; cin >> n >> k;
    vi a(n),b(n);
    loop (i,0,n-1) cin >> a[i];
    loop (i,0,n-1) cin >> b[i];
    // cout <<  max_min(0,k,n,0,0,a,b) << "\n";
}

ll dp[6][6][16],n,k;
vi a(40),b(40); 

ll max_min_dp (ll i, ll j, ll s) {
    if (i == n) return dp[i-1][j][s];
    if (j == k) return max_min_dp(i+1,j,s);

    if (dp[i][j][s]) return dp[i][j][s];

    dp[i][j][s] = max(max_min_dp(i+1,j,s),dp[i][j][s]);
    dp[i][j+1][s+a[i]] = max(max_min_dp(i+1,j+1,s+a[i])+b[i],dp[i][j+1][s+a[i]]);

    return dp[i][j][s];

    // dp[i+1][j+1][s+a[i+1]] = max (max_min_dp (i+1,j+1,s + a[i+1]), max_min_dp (i,j,s) + b[i+1]);
    // dp[i+1][j][s] = max(max_min_dp (i+1,j,s), max_min_dp (i,j,s));

    // dp[i+1][j+1][s] = max(max_min_dp (i+1,j+1,s+a[i])+b[i], max_min_dp (i+1,j,s));

    // return dp[i][j][s];

    /*
        dp[i][j][s] where i is the index visited so far such that we have selected j elements with s in array a
        dp[i][j][s] = max (dp[i-1][j][s], dp[i-1][j-1][s-a[i]] + b[i])

        dp[i+1][j+1][s+a[i+1]]=max(dp[i+1][j+1][s+a[i+1]],dp[i][j][s]+b[i+1]) and
        dp[i+1][j][s] = max(dp[i+1][j][s] , dp[i][j][s])
    */
}

void solve() {
    cin >> n >> k;
    
    loop(i,0,n-1) cin >> a[i];
    loop(i,0,n-1) cin >> b[i];
    CLR(dp);
    max_min_dp (0,0,0);
    ll ans = 0;
    loop (s,1,16) {
        ans = max(ans, min(dp[n][k][s],s)); 
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