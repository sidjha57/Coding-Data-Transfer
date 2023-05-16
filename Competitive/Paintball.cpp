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
const int maxn = 1e6+5;
ll factorial[maxn];

void precompute() {
    factorial[0] = 1;
    loop (i,1,maxn) {
        factorial[i] = (i * factorial[i-1])%mod;
    }
}

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll Comb (ll n, ll r) {
   ll n_r = factorial[n-r]; n = factorial[n], r = factorial[r];  // n!/(r! * (n-r)!) 
   ll ans = (n * binpow(n_r, mod-2, mod))%mod;
   ans = (ans * binpow (r, mod-2, mod)) %mod;
   return ans;
}

void solve() {
    ll n,k,g; cin >> n >> k >> g;
    ll m = n/g; // size of group

    if (k == 0) {
        cout << "0\n";
        return;
    }

    if (m > n-k ) {
        cout << "1\n";
        return;
    } 

    ll tot = Comb(n-1,m-1);
    ll W = Comb(n-k-1,m-1);
    ll ans = (W * binpow (tot, mod-2, mod))%mod;

    ans = (1 - ans + mod) % mod;

    cout <<  ans << "\n";     
}

int main(int argc, char const *argv[]){
    _fast

    // (N + 6logN*Test) = 10^6 + 6*log(10^6)*10^5   = 10^7 
    //fileIO();
    precompute();
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}