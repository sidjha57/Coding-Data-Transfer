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

int ways(string& s, int n)
{
 
    int dp[n][n];
 
    // Initialize DP table
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
 
    // Base Case
    for (int i = 0; i < n; i++)
        dp[0][i] = 1;
 
    for (int i = 1; i < n; i++) {
 
        // To store sub-string S[i][j]
        ll temp=0;
        for (int j = i; j < n; j++) {
            temp = temp*10 + (s[j] - '0');
 
            // To store sub-string S[k][i-1]
            ll test=0;
            for (int k = i - 1; k >= 0; k--) {
                 test= test*10 + (s[k] - '0');
                if (test < temp) {
                    dp[i][j] = (dp[i][j] + dp[k][i - 1])%mod;
                }
            }
        }
    }
 
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // Add all the ways where S[i][n-1]
        // will be the last partition
        ans = (ans + dp[i][n - 1])%mod;
    }
 
    return ans;
}
 
void solve() {
    ll n;
    string num; cin >> n >> num;
    cout << ways(num,n);
}

int main(int argc, char const *argv[]){
    _fast
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}