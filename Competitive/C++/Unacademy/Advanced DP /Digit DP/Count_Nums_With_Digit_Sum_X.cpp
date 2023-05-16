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
ll dp[1000][9000][2]; // 10^1000
string s ;
ll Digit_DP (string& num, ll n, ll x, bool tight) {
    if (x < 0) return 0;
    if (n == 1) {
        if (x >= 0 && x <= 9) return 1;
        return 0;
    }
    ll &ans = dp[n][x][tight];
    if (ans) return ans;
    ll ub = tight ? (num[(num.size() - n)] - '0') : 9;
   
    loop (d,0,ub) {
        ans += Digit_DP(num, n-1, x-d,  (tight&(d == ub)));
    }
    return ans;
    

}

void solve() {
    ll x;
    string l,r; cin >> l >> r >> x; 
    /* dp (n,x,tight) => represents count of numbers with digit sum equal to x 
       dp(i,j,k)  reached ith digit with sum remaining j such that the tight is k
       dp(N,X,0) => 0 _ _ _ or dp(N,X-1,0) => 1 _ _ _ 

    */
   
    ll ans = Digit_DP (r,r.size(),x,1);
    cout << ans ;

}

int main(int argc, char const *argv[]){
    _fast
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}