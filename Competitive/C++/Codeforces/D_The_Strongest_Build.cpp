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
#define eb                       emplace_back
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
#define loop(i,a,b)              for(ll i=(a);i<=(b);i++)
#define looprev(i,a,b)           for(ll i=(a);i>=(b);i--)
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

void fileIO() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

void solve() {
    ll n,m,val=0; cin >> n;
    vi a[n+1],idx;
    priority_queue <pair<ll,vi>> pq;
    idx.eb(0);
    loop (i,1,n) {
        cin >> m;
        a[i].eb(0);
        while (m--) {
            ll x; cin >> x;
            a[i].eb(x);
        }
        val += a[i][a[i].size()-1];
        idx.eb(a[i].size()-1);
    }

    pq.emplace(val,idx);

    cin >> m; 
    set<vi> banned; 
    loop (i,1,m) {
        vi slot; 
        slot.eb(0);
        loop (j,1,n) {
            ll a; cin >> a;
            slot.eb(a);
        }
        banned.emplace(slot);
    }
    set<vi> done_builds;
    while (banned.count(pq.top().ss)) {
        vi b = pq.top().ss;
        ll val= pq.top().ff;
        pq.pop();
        loop (i,1,n) {
            if (b[i] > 1) {
               ll new_val = val + a[i][b[i]-1] - a[i][b[i]];
                b[i]--;
                if (!done_builds.count(b)) {
                    pq.emplace(new_val,b);
                    done_builds.emplace(b);
                }
                b[i]++;
            }
        }
    }
    vi ans = pq.top().ss;
    for (auto a : ans)
        if (a != 0)
        cout << a << " ";
    cout << "\n";

}

int main(int argc, char const *argv[]){
    _fast
    //fileIO();
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}