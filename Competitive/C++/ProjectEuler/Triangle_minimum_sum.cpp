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
ll dp[105][105];
// int minimumTotal(vector<vector<int>>& triangle) {
//     memset(dp,0,sizeof(dp));
//     int n = triangle.size();
//     dp[0][0] = triangle[0][0];
//     // dp[1][0] = triangle[1][0]+dp[0][0];
//     // dp[1][1] = triangle[1][1]+dp[0][0];
//     for (int i=1;i<n;i++) {
//         for (int j=0;j<=i;j++) {
//             if (j == 0 ) dp[i][j] = triangle[i][j] + dp[i-1][j];
//             else if (j == i) dp[i][j] = triangle[i][j] + dp[i-1][j-1]; 
//             else dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]) + triangle[i][j];
//         }
//     }
//     int mini = INT_MAX;
//     for (int j=0;j<n;j++) 
//             mini = min(dp[n-1][j],mini);
//     return mini;
// }
int maximumTotal(vector<vector<int>>& triangle) {
    memset(dp,0,sizeof(dp));
    ll n = 100;
    dp[0][0] = triangle[0][0];
    for (int i=1;i<n;i++) {
        for (int j=0;j<=i;j++) {
            if (j == 0 ) dp[i][j] = triangle[i][j] + dp[i-1][j];
            else if (j == i) dp[i][j] = triangle[i][j] + dp[i-1][j-1]; 
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + triangle[i][j];
        }
    }
    ll mx = -inf;
    loop (j,0,99)
            mx = max(dp[99][j],mx);
    return mx;
}
void solve() {
    vector<vector<int>> triangle(100);
    loop (i,0,99) {
        loop (j,0,i){
            ll a;
            cin >> a;
            triangle[i].pb(a);
        }
    }
    cout << maximumTotal(triangle);
}

int main(int argc, char const *argv[]){
    _fast
    fileIO();
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}