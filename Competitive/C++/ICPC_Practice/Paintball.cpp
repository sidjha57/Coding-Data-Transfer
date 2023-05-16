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
#define MAXN 1000005
ll factorial[MAXN];

void precompute() { // all factorials are calculated and stored
    factorial[0]=1,factorial[1]=1;
    loop (i,2,MAXN) factorial[i] = (factorial[i-1]%mod*i%mod)%mod;
}

ll binpow(ll a, ll b) { // calculates a^b in logN
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll inverse_mod (ll n) { // Q^-1 % mod
    return binpow (n,mod-2ll);
}

ll Combinatrics (ll n, ll r) { // nCr
    ll n_r = factorial[n-r]; // n_r => n-r
    n = factorial[n], r = factorial[r];
    ll ans =  (n*inverse_mod(r)) %mod;
    ans = (ans*inverse_mod(n_r))%mod;
    return ans;
}


void solve() {
    
    ll N,G,K; cin >> N >> K >> G; 
    if (K == N-1) {
        cout << "1\n";
        return ;
    }
    if (K == 0) {
        cout << "0\n";
        return ;
    }
    ll n = factorial[N],g = factorial[G], g_1 = factorial[G-1],M = N/G; 
    ll n_m = factorial[N - M], num_of_ways_of_selecting = Combinatrics ( (N-K-1) , (M-1) ); // (n-k-1)C(m-1)
       M = factorial[M];
    ll m_g = binpow (M,G), m_g_1 = binpow (M, (G-1) );// (m!)^g , (m!)^(g-1)   
    ll total_num_teams =  (n * inverse_mod (g)) %mod; 
       total_num_teams = (total_num_teams * inverse_mod (m_g)) %mod ; // n!/((m!)^g*g!)
    ll num_of_ways_ashwin_has_no_friends = (num_of_ways_of_selecting * n_m ) % mod; 
       num_of_ways_ashwin_has_no_friends= (num_of_ways_ashwin_has_no_friends * inverse_mod (m_g_1)) % mod;
       num_of_ways_ashwin_has_no_friends = (num_of_ways_ashwin_has_no_friends * inverse_mod (g_1) ) % mod;
    ll ans = (total_num_teams - num_of_ways_ashwin_has_no_friends + mod) % mod;
       ans = (ans*inverse_mod (total_num_teams) ) % mod;
    cout << ans << "\n";

}

// void solve () {
//     ll N,G,K; cin >> N >> K >> G; 
//     ll M = N/G;
//     if (M-1 > N-K-1) {
//         cout << "1\n";
//         return;
//     }
//     ll a = factorial[N-K-1], b = factorial[N-M], c = inverse_mod (factorial[N-M-K]), d = inverse_mod (factorial[N-1]);
//     ll ans = (a*b)%mod;
//     ans = (ans*c)%mod;
//     ans = (ans*d)%mod;
//     ans = (1 + mod - ans) % mod;
//     cout << ans << "\n";
// }

int main(int argc, char const *argv[]){
    _fast
    precompute();
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}