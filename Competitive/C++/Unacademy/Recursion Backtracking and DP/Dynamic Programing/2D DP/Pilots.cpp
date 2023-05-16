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
ll ass[10005],cap[10005],dp[10005][10005],n;
// dp[i][a] denotes the ith member and the number of assistants selected so far 
int CrewMen(int i, int c, int a) {
    if (dp[i][a] != -1) return dp[i][a];
    if (i == n) return 0;
    
    if (a == n/2 ) return dp[i][a] = (CrewMen(i+1,c+1,a) + cap[i]); // all men were assistants
    else if (a == c) return dp[i][a] = (CrewMen(i+1,c,a+1) + ass[i]); // so far num of ass and cap are same therefore an ass will be selected as he is the youngest among those who are not selected
    else return dp[i][a] = min (CrewMen(i+1,c,a+1)+ass[i], CrewMen(i+1,c+1,a)+cap[i]);
}

int main(int argc, char const *argv[]){
    _fast
    ll t=1;
    while(t--){
        cin >> n;
        CLR(ass),CLR(cap),SET(dp);
        loop (i,0,n-1) cin >> cap[i] >> ass[i];
        dp[0][0] = ass[0] + CrewMen(1,0,1);
        cout << dp[0][0];
    }
  return 0;
}