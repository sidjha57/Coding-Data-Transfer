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
const int maxn = 300005;
ll fact[maxn];
void precompute () {
    fact[0] = fact[1] = 1;
    loop (i,2,maxn-1) {
        fact[i] = i*fact[i-1];
        fact[i]%= mod;
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

ll nCr (ll n, ll r) {
    ll n_r = fact[n-r];
    n = fact[n];
    r = fact[r];
    ll ans = n*binpow(r,mod-2,mod);
    ans%=mod;
    ans = ans*binpow(n_r,mod-2,mod);
    ans%=mod;
    return ans;
}

void solve() {
    ll n,m,x=0,term,ans=0; cin >> n >> m;
    ll a[n];
    loop (i,0,n-1) {
        cin >> a[i];
        if (a[i] <= m) x++;
    }
    if (n > m) {
        cout << "0\n";
        return;
    }
    // mCn n! - xC1 * m-1Cn-1 (n-1)! + xC2 * m-2Cn-2 (n-2)! .....
    loop (i,0,x) {
        term = (nCr (x,i)) % mod;
        term = (term * nCr (m-i, n-i))%mod;
        term = (term * fact[n-i])%mod;
        
        if (i&1) {
            ans = (ans - term + mod)%mod;
        }
        else {
            ans = (ans + term) %mod;
        }
    }
    cout << ans << "\n";
}

int main(int argc, char const *argv[]){
    _fast
  //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
  //#endif
    ll t=1;
    precompute();
    while(t--){
     solve();
    }
  return 0;
}