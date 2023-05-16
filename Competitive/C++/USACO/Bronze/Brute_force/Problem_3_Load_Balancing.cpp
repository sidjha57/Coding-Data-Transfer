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
ll found (ll *x, ll X, ll mid, ll n) {
    ll idx,idx1;
    idx = upper_bound(x,x+n,X-1) - x;
    idx1 = upper_bound(x,x+n,X+1) - x;
    ll a1 = abs(mid - idx) + abs(mid - (n-1-idx)),a2 = abs(mid-idx1) + abs(mid - (n-1-idx1));
    if (a1 < a2) 
        return X-1;
    
    return X+1;
}
void solve() {
    ll n,b,X,Y,mid,idx,idx1; 
    cin >> n >> b;
    ll x[n],y[n];
    pii co_ordinate [n];
    loop (i,0,n-1) {
        cin >> x[i] >> y[i];
        co_ordinate[i] = {x[i],y[i]};
    }
    sort(x,x+n);
    sort(y,y+n);
    mid = (n&1)? n/2: n/2-1;
    X = x[mid];
    X = found(x,X,mid,n);
    Y = y[mid];
    Y = found(y,Y,mid,n);

    ll first_quad=0,second_quad=0, third_quad=0, fourth_quad=0;
    loop (i,0,n-1) {
        ll &x1 = co_ordinate[i].ff, &y1 = co_ordinate[i].ss;
        if (x1-X > 0 && y1-Y > 0) first_quad++;
        else if (x1-X < 0 && y1-Y > 0) second_quad++;
        else if (x1-X <0 && y1-Y < 0) third_quad++;
        else fourth_quad++;
    } 

    cout << max({first_quad,second_quad,third_quad,fourth_quad}) << "\n";

}

int main(int argc, char const *argv[]){
    _fast
  #ifndef ONLINE_JUDGE
        freopen("balancing.in", "r", stdin);
        freopen("balancing.out", "w", stdout);
  #endif
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}