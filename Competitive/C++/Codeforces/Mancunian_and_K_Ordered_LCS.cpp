
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}
 
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
  
ll dp[2005][2005][7];
ll korderedlcs(vi &s1, vi &s2, int k, int i, int j) {
	if(i == s1.size() or j == s2.size()) {
		return 0;
	}
 
	if(dp[i][j][k] != -1) return dp[i][j][k];
 
	ll res = 0;
	if(s1[i] == s2[j]) {
		res = 1 + korderedlcs(s1, s2, k, i+1, j+1);
	} else if(k > 0) 
		res = 1 + korderedlcs(s1, s2, k-1, i+1, j+1);	
    else res = max({res, korderedlcs(s1, s2, k, i, j+1), korderedlcs(s1, s2, k, i+1, j)});

	return dp[i][j][k] = res;
}
 
int main(int argc, char const *argv[]) { 
	ll n, m, k;
	cin>>n>>m>>k;
	memset(dp,-1,sizeof(dp));
	vi s1(n, 0),s2(m, 0);
	loop(i, 0, n-1) cin>>s1[i];
	loop(i, 0, m-1) cin>>s2[i];
	
	cout<<korderedlcs(s1, s2, k, 0, 0);
    // loop (i,1,n) {
    //     loop (j,1,m) {
    //         loop (l,0,k) {
    //             if (s1[i] == s2[j]) {
    //                 dp[i][j][l] = 1 + dp[i-1][j-1][l];
    //             } 
    //             else if (l > 0)
    //                 dp[i][j][l] = 1 + dp[i-1][j-1][l-1];
    //             else
    //             dp[i][j][l] = max ({dp[i][j][l],dp[i-1][j][l],dp[i][j-1][l]});
    //         }
    //     }
    // }
	 
    // cout << dp[n][m][k]-1;
	return 0;
}


f(i,j) = max (i-f(i+1,j), f(i,j-1) - j)