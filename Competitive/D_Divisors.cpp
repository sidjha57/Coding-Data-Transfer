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
#define mod                      998244353
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

/*
  a = p^i * q^j
  It has exactly 3,5 divisors
  1) i = 1, j = 1  // 4 divisors
  2) i = 2, j = 0  // 3 divisors
  3) i = 3, j = 0  // 4 divisors
  4) i = 4, j = 0  // 5 divisors
  
  2,3,4 can be easily found by checking whether its a proper ith root 

  As for case 1, the best way to find the prime numbers p and q is by finding the gcd's among all others
  as we don't require the exact value of the p,q we just want to know the exponent corresponding to it

  lastly number of divisors can be calculated by 

  n = p1^e1 * p2^e2 * p3^e3 ... 
  num of divisors = (e1+1)*(e2+1)*(e3+1) ...
*/


void solve() {
    ll n,p;cin >> n;
    vi a(n); loop (i,0,n-1) cin >> a[i];
    ump<ll,ll> cnt,cnt2;
    ll exp_not_found = 0;
    loop (i,0,n-1) {
      // i = 4, j = 0  `
      p = sqrtl(sqrtl(a[i]));
      if (p*p*p*p == a[i]) {
        cnt[p] += 4;
        continue;
      }

      // i = 3, j = 0
      p = (cbrtl(a[i]) + 1e-6);
      if (p*p*p == a[i]) {
        cnt[p] += 3;
        continue;
      }

      // i = 2, j = 0
      p = sqrtl(a[i]);
      if (p*p == a[i]) {
        cnt[p] += 2;
        continue;
      }

      bool f = 1;
      loop (j,0,n-1) {
        if (a[i] == a[j]) continue;
        ll x = __gcd(a[i],a[j]);
        if (x>1) {
          f = 0;
          cnt[x]++;
          cnt[a[i]/x]++;
          break;
        } 
      }
      if (f) cnt2[a[i]] ++;

    }

    ll ans = 1;
    for (auto exp : cnt) 
      ans = (ans * (exp.ss + 1))%mod;
    
    for (auto exp : cnt2)
      ans = (ans * (exp.ss + 1)%mod * (exp.ss + 1) %mod)%mod;
    
    cout << ans;
}


int main(int argc, char const *argv[]){
    _fast
  //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
  //#endif
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}