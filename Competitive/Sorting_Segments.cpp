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
vi a {1,2,3,4,5,6};
ll n=6,k=4;
void solve() {
    // ll n,k; cin >> n >> k;
    // vi a(n); loop (i,0,n-1) cin >> a[i];
    if (is_sorted(a.begin(),a.end())) {
        cout << "0\n";
        return;
    } 
    vector<bool> b(n,0);
    loop (i,0,n-1) 
        if (a[i] == i+1) b[i] = 1;
    
    ll x=0,y=n-1;
    loop (i,0,n-1) 
        if (b[i] == 0) {
            x = i;
            break;
        }
    looprev (i,n-1,0)
        if (b[i] == 0) {
            y = i;
            break;
        }
    

    if (k >= (y-x+1)) {
        //cout << "1\n";
        return;
    }
    vi d(y-x+1);
    
    ll j=0;
    loop (i,x,y) d[j++] = a[i];
    
    vi c(y-x+1);
    c = d;
    ll mn = 3;
    sort(c.begin(), c.begin() + k);
    if (is_sorted(c.begin(), c.end())) mn = min (mn,(ll)1);
    sort(c.end()-k, c.end());
    if (is_sorted(c.begin(), c.end())) mn = min (mn,(ll)2);
    c = d;
    sort(c.end()-k, c.end());
    if (is_sorted(c.begin(), c.end())) mn = min (mn,(ll)1);
     sort(c.begin(), c.begin() + k);
    if (is_sorted(c.begin(), c.end())) mn = min (mn,(ll)2);
    //cout << mn << "\n";

    if (mn == 3) {
        loop (i,0,n-1) cout << a[i] << " ";
        cout << "\n" << x << " " << y << "\n";
        
        // loop (i,0,n-1) cout << b[i] << " ";
        // cout << "\n";
    }

}

int main(int argc, char const *argv[]){
    _fast
    ll t; cin>>t;
    while(t--){
      next_permutation(a.begin(), a.end());
      solve();
    }
  return 0;
}