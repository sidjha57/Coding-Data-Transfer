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
#define loop(x,start,end)        for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define _fast                    ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
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

// 0 based indexing
struct segtree {
 
    vi seg;
    ll size;
 
    void init(ll n) {
        size = 1;
        while (n > size) size *= 2;
        seg.assign(2*size , 0ll);
    }
 
    void set (ll i, ll v,ll x, ll lx, ll rx) {
        if ((rx-lx) == 1) {
            seg[x] = (seg[x]|v);
            return;
        }
 
        ll m = mid(lx,rx);
        if (i < m) {
            set (i, v, 2 * x + 1, lx, m);
        } else {
            set (i, v, 2 * x + 2, m, rx);
        }
 
        seg[x] = (seg[2 * x + 1] | seg[2*x + 2]);
    }
 
    void set (ll i, ll v) {
        set(i, v, 0, 0, size);
    }
    void build (vi& a,ll x, ll lx, ll rx) {
        if ((rx-lx) == 1) {
            if (lx < a.size()) {
                seg[x] = a[lx];
            }
            return;
        }
        ll m = mid(lx,rx);
        build (a, 2 * x + 1, lx, m);
        build (a, 2 * x + 2, m, rx);
        seg[x] = (seg[2* x + 1] | seg[2* x + 2]);
    }
    void build (vi& a) {
        build(a,0,0,size);
    }
    
    // l to r-1 
    ll OR (ll l, ll r, ll x, ll lx, ll rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return seg[x];
        
        ll m = mid(lx,rx);
        ll s1 = OR (l, r, 2 * x + 1, lx, m);
        ll s2 = OR (l, r, 2 * x + 2, m, rx);
        return (s1|s2);
    }
 
    ll OR (ll l ,ll r) {
        return OR (l, r, 0, 0, size);
    }
};

void solve() {
    ll n,k; cin >> n >> k;
    vector<ll> arr (n);
    for (ll &i: arr) cin >> i;
    segtree seg;
    seg.init(n);
    seg.build(arr);

    ll l=0, r=1, x=0, ans=0;
    for (r=0; r<n; r++) {
        x = seg.OR(l,r);
        while (x > k) {
            x = seg.OR(l,r);
            l++;
        }
        ans += (r-l+1);
    }
    cout << ans;

}

int main(int argc, char const *argv[]){
    _fast
  //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
  //#endif
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}