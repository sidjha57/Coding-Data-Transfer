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


// void solve() {
//     ll n; cin >> n;
//     vector<int> a(n), b(n);
//     for (int i=0; i<n; i++) cin >> a[i];

//     int x = INT_MIN;
//     for (int i=0; i<n-1; i++) {
//         if (a[i] > a[i+1]) {
//             int y = a[i+1] + (a[i] - a[i+1] + 1)/2;
//             x = max(x,y);
//         }
//     }

//     if (is_sorted(a.begin(), a.end())) {
//         cout << "0\n";
//         return;
//     } 

//     for (int i = 0; i <n; i++) {
//         b[i] = abs(a[i] - x);
//     }
//     if (is_sorted(b.begin(), b.end())) {
//         cout << x << "\n";
//         return;
//     }

//     cout << "-1\n";

//    vector<vector<int>> gre, eqa;
//    for (int i=n-1; i>=0; i--) {
//         if (res[i][0] > res[i][1]) gre.push_back({res[i][0], i});
//         if (res[i][0] == res[i][1]) eqa.push_back({res[i][1], i});
//    }
   
//    set<int> st;
//    int ans = 0;
//    for (int i=0; i<gre.size() && k-i>=0; i++) {
//       ans += gre[i][0];
//       st.insert(gre[i][1]);
//    }
//    if (k > num) {
//     k -= num;
//      for (int i=0; i<eqa.size()&& k-i>=0; i++) {
//         ans += eqa[i][0];
//         st.insert(eqa[i][1]);
//      }
//    }
//    for (int i=0; i<n; i++) {
//     if (st.find(i) == st.end()) ans += res[i][1];
//    }
    
// }

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
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

vector<int> solve (vector<vector<int>>& A) {
    int n = A.size();
    map<int, int> mp;
    vector<int> ans(n);
    
    for (int i=0; i<n; i++) {
        int l1 = A[i][0], r1 = A[i][1], l2, r2;

        if (mp.size() == 0) {
            mp[l1] = r1;
            ans[i] = mp.size();
            continue;
        }

        auto it = mp.lower_bound(l1);

        if (it == mp.end()) {
            it--;
            l2 = (*it).first, r2 = (*it).second;
            if (l1 <= r2) {
                mp[l2] = max(r1,r2);
            } else {
                mp[l1] = r1;
            }
        } else {
            l2 = (*it).first, r2 = (*it).second;            
            if (r1 < l2) {
                mp[l1] = r1;
            } else {
                if (l1 < l2) {
                    mp[l1] = max(r1,r2);
                    mp.erase(l2);
                } else {
                    mp[l2] = max(r1,r2);
                }
            }
        }

        ans[i] = mp.size();
    }
    
    return ans;
}

int main(int argc, char const *argv[]){
    _fast
  //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
  //#endif
//   ll a = 1;
//   ll ans = (a%mod) * (binpow(6,mod-2,mod)%mod);
//   ans %= mod;
//   cout << ans;

    vector<vector<int>> A {
        {1,2},
        {1,8},
        {9,11},
        {1,11},
        {7,10},
        {1,6},
        {9,11},
        {9,11},
        {10,11},
        {5,7}
    };
    vector<int> ans = solve(A);
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    // ll t; cin>>t;
    // while(t--){
    //  solve();
    // }
  return 0;
}

