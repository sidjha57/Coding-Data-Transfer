//template

#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
#include<set>
#include<list>
#include<iomanip>
#include<queue>
#include<stack>
#include <math.h>
#include<climits>
#include<bitset>
#include<cstring>
#include<numeric>
#include<array>
#include<deque>
#include <cstdlib>
#include <cstdio>
#include<stdlib.h>
#include <cerrno>
#include <ctime>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <random>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>


//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;
#define forn(x,n) for(ll x = 0; x<n; x++)
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

void solve() {
    int n,k,L; string s; cin >> n >> s;
    ll dp[n+1][n+1],mx[n+1][n+1];
    CLR(dp),CLR(mx);

    // finding max length string which matches
    looprev(i,n-1,0) {
        looprev (j,n-1,0) {
            if (s[i] != s[j]) mx[i][j] = 0;
            else
                mx[i][j] = 1 + mx[i+1][j+1];
        }
    }

    //base case
    dp[0][0] = 1;
    // loop (i,0,n) {
    //      dp[i][0] = 1;
    // }
   //creating the actual dp
   for(ll i = 1; i<=n; i++){
       for(ll j = 1; j<=i; j++){
           ll k = 0;
           while(k < j){
               dp[i][j] += dp[i-j][k];
               dp[i][j] %= mod;
               k++;
           }
           if(i-2*j < 0) continue;
           ll l = mx[i-2*j][i-j];
           if(s[i-2*j+l] < s[i-j+l]){
               dp[i][j] += dp[i-j][j];
               dp[i][j] %= mod;
           }
       }
   }
    // loop (j,1,n) {
    //     loop (i,1,n) {
    //         k = 0;
    //         while (j > k) {
    //             dp[i][j] = (dp[i][j] + dp[i-j][k])%mod;
    //             k++;
    //         }
    //         L = mx[i-2*j][i-j];
    //         if (i < 1 || (i-2*j+L+1 < 0) || (i-j+L+1 < 0) || (i-j < 0)) continue;
    //         if (L < j && s[i-2*j+L] < s[i-j+L])
    //             dp[i][j] = (dp[i][j] + dp[i-j][j])%mod;
    //     }
    // }

    // forn(i,n+1){
    //     forn(j,n+1){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    ll ans = 0;
    loop (j,1,n) ans = (ans + dp[n][j])%mod;

    cout << ans << "\n";
}

int main(int argc, char const *argv[]){
    _fast
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}

/*
5
32745
*/