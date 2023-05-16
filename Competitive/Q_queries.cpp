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

#define MAX 200010
int tree[MAX];
vector<int> ar;

ll constSegTree(ll strt, ll end, ll idx)
{
  if(strt == end)
    return tree[idx] = ar[strt];

  int mid = (strt + end) / 2;
  return tree[idx] = constSegTree(strt, mid, 2*idx+1) ^
            constSegTree(mid+1, end, 2*idx+2);
}
void constSegTree(ll n)
{
  constSegTree(0, n-1, 0);
}

ll getXor(ll strt, ll end, ll l, ll r, ll idx)
{
  if(strt <= l && r <= end)
    return tree[idx];
  
  if(end < l || r < strt || l > r)
    return 0;
  
  ll mid = (l + r) / 2;
  return getXor(strt, end, l, mid, 2*idx+1) ^
      getXor(strt, end, mid+1, r, 2*idx+2);
}
ll getXor(ll n, ll strt, ll end) {
  return getXor(strt, end, 0, n-1, 0);
}



void solve() {
  ll n,q; cin >> n >> q;
  ar.resize(n+1);
  ar[0] = 0;
  loop (i,1,n) cin >> ar[i];
  constSegTree(n+1);
  loop (i,0,q-1) {
      ll a,b; cin >> a >> b;
      cout << getXor(n,a-1,b-1) << "\n";
  }
}

int main(int argc, char const *argv[]){
    _fast
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}