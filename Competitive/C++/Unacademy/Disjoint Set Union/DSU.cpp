//Siddharth Jha

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

#define ll                       long long int
#define mod                      1000000007
#define inf                      1e18
#define pb                       push_back
#define vi                       vector<int>
#define vs                       vector<string>
#define pii                      pair<int,int>
#define ump                      unordered_map
#define mp                       make_pair
#define pq_max                   priority_queue<int>
#define pq_min                   priority_queue<int,vector<int>,greater<int> >
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

class DSU {
    vector<int> p,rank,mn,mx,sum;
    public :
    DSU(int n) {
        p.resize(n+1,0),rank.resize(n+1,0);
        for (int i=0; i <= n; i++) p[i] = i;
    }

    int Get (int a) {
        return p[a] = (p[a] == a) ? a : Get(p[a]);
    }

    void Union (int a, int b) {
        a = Get(a), b = Get(b);
        if (rank[a] > rank[b])
            p[b] = a, rank[a]++;
        else
            p[a] = b, rank[b]++;
    }
};

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
            seg[x] = seg[x]+v;
            return;
        }
 
        ll m = mid(lx,rx);
        if (i < m) {
            set (i, v, 2 * x + 1, lx, m);
        } else {
            set (i, v, 2 * x + 2, m, rx);
        }
 
        seg[x] = seg[2 * x + 1] + seg[2*x + 2];
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
        seg[x] = seg[2* x + 1] + seg[2* x + 2];
    }
    void build (vi& a) {
        build(a,0,0,size);
    }
    
    // l to r-1 
    ll sum (ll l, ll r, ll x, ll lx, ll rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return seg[x];
        
        ll m = mid(lx,rx);
        ll s1 = sum (l, r, 2 * x + 1, lx, m);
        ll s2 = sum (l, r, 2 * x + 2, m, rx);
        return s1+s2;
    }
 
    ll sum (ll l ,ll r) {
        return sum (l, r, 0, 0, size);
    }
};

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

void solve() {
    int n,q; cin >> n >> q;
    DSU ds (n);
    loop (i,1,n) {
        int a,b; cin >> a >> b;
        ds.Union(a,b);
    }
    loop (i,1,q) {
        int a; cin >> a;
        cout << ds.Get(a) << "\n";
    }

}

int main(int argc, char const *argv[]){
    _fast
  //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
  //#endif
    int t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}




