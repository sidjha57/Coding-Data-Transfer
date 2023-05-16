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

/* If he decides to work on ith day then he has option to work on (i-1)th or (i-2)th or (i-3)th day which 
   he can take min of these whereas if he decides not to work on ith day then he has to work on (i-1)th or (i-2)th day*/
void solve() {
    ll n; cin >> n;
    ll arr[n+1], dp[n+1][2]; // dp[i][0] states that it has not worked on that day and vice versa for dp[i][1]
    loop (i,1,n) cin >> arr[i];
    
    // base case
    dp[1][0] = min(arr[2],arr[3]), dp[1][1] = arr[1];
    if (n > 1)
    dp[2][0] = min(arr[1],arr[3]), dp[2][1] = arr[2];
    if (n > 2) 
    dp[3][0] = min(arr[1],arr[2]), dp[3][1] = arr[3];

    loop (i,4,n) {

        // if he decides to not work on ith day, then
        dp[i][0] = min (dp[i-1][1],dp[i-2][1]);

        // if he decides to not work on ith day, then
        dp[i][1] = arr[i] + min ({dp[i-1][1],dp[i-2][1],dp[i-3][1]});
    }

    cout << min (dp[n][0],dp[n][1]) ;
    
}

int main(int argc, char const *argv[]){
    _fast
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}