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

void solve() {
 int n, ans = 0, mn = 0;
 cin >> n;
 vector<int> a(n), b(n);
 for(int i = 0; i < n; i++)
  cin >> a[i];
 for(int i = 0; i < n; i++)
  cin >> b[i];
 vector<int> inverted(n, -1);
 for(int i = 29; i >= 0; i--) {
  int isPossible = 1;
  for(int j = 0; j < n; j++) {
   if(inverted[j] != -1) {
    if(inverted[j] == 1) isPossible = ((isPossible&(b[j]>>i)&1));
    else isPossible = ((isPossible&(a[j]>>i)&1));
    continue;
   }
   if(((a[j]>>i)&1) || ((b[j]>>i)&1)) {}
   else {
    isPossible = 0;
    break;
   }
  }
  if(!isPossible)
   continue;
  int val = 1;
  for(int j = 0; j < n; j++) {
   if(inverted[j] != -1) {
    if(inverted[j] == 1) val = ((val&(b[j]>>i)&1));
    else val = ((val&(a[j]>>i)&1));
    continue;
   }
   if(((a[j]>>i)&1) && ((b[j]>>i)&1)) {}
   else if(((a[j]>>i)&1)) inverted[j] = 0;
   else if(((b[j]>>i)&1)) inverted[j] = 1, mn++;
   else {
    val = 0;
    break;
   }
  }
  ans += (val * (1ll<<i));
 }
 cout << ans << " " << mn << '\n';
}

int main() {

 ll t;
 cin>>t;
 while(t--){
     solve();
 }
 return 0;
}