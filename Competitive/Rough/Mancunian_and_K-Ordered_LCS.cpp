//https://code.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/

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

int dp[2005][2005][8];
int KorderedLCS(vector<int>& S1,vector<int>& S2, int i, int j, int k) {
    
    if ( i == S1.size() || j == S2.size()) return 0;
    if (dp[i][j][k] != -1) return dp[i][j][k];
    int res = 0;
    if (S1[i] == S2[j]) res = ( 1 + KorderedLCS (S1,S2,i+1,j+1,k));
    else {
        if (k > 0) res = (1 + KorderedLCS (S1,S2,i+1,j+1,k-1));
        return res = max ({res,KorderedLCS (S1,S2,i+1,j,k), KorderedLCS(S1,S2,i,j+1,k)});
    }
    return dp[i][j][k] = res;
}

int main(int argc, char const *argv[]){
    _fast
    ll t=1;
    while(t--){
     int n,m,k; cin >> n >> m >> k;
     SET(dp);
     vector<int> S1(n),S2(m); 
     loop (i,0,n-1) cin >> S1[i];
     loop (j,0,m-1) cin >> S2[j];
     cout << KorderedLCS (S1,S2,0,0,k);
    }
  return 0;
}