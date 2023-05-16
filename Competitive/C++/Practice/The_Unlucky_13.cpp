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
#define mod                      1000000009
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

struct Matrix {
  ll arr[2][2];
  Matrix () {
    arr[0][0]=0,arr[0][1]=0,arr[1][0]=0,arr[1][1]=0;
  }
  Matrix operator* (const Matrix &other) const {
    Matrix result;
    for (int i=0; i<2; i++)
      for (int j=0; j<2; j++) {
            ll tmp = 0;
        for (int k=0; k < 2; k++) {
            tmp = ((tmp+mod) % mod + (mod + arr[i][k]*other.arr[k][j])%mod)%mod;
        }
        result.arr[i][j] = tmp % mod;
      }
    return result;
  } 
};

Matrix pw (Matrix a, ll p) {
  Matrix result;
  result.arr[0][0]=1,result.arr[0][1]=0,result.arr[1][0]=0,result.arr[1][1]=1;
  while (p>0) {
    if (p&1) result = a*result;
    a = a*a;
    p >>= 1;
  }
  return result;
}

void solve() {
  ll n; Matrix m; 
  m.arr[0][0]=99,m.arr[0][1]=-10,m.arr[1][0]=10,m.arr[1][1]=-1;
  cin >> n;
  if (n == 0) cout << "0\n";
  if (n == 1) cout << "10\n";
  if (n == 2) cout << "99\n";
  if (n > 2) {
    if (n&1) {
    Matrix result = pw(m,(n+1)/2-1);
    cout << (99*result.arr[1][0] + 10*result.arr[1][1])%mod << "\n";
    }
    else {
      Matrix result = pw(m,n/2-1);
      cout << (99*result.arr[0][0] + 10*result.arr[0][1])%mod << "\n";
    }
  }

}

int main(int argc, char const *argv[]){
    _fast
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}