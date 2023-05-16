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

ll bfs(ll st, unordered_map<ll,ll>& vis, unordered_map<ll,ll>& nums) {
    ll siz = nums[st];
    vis[st] = 1;
    queue<pii> q;
    q.push({st,0});
    bool f1 = 1, f2 = 1;
    while(!q.empty()) {
        pii cur = q.front();
        ll num = cur.ff, rad = cur.ss + 1;
        q.pop();
        for (auto x: nums) {
            if (f1 && x.ff <= num + rad && vis.find(x.ff) == vis.end()) {
                siz += x.ss;
                q.push({x.ff,rad});
                vis[x.ff] = 1;
            } else {
                f1 = 0;
            }
            if (f2 && x.ff >= num - rad && vis.find(x.ff) == vis.end()) {
                siz += x.ss;
                q.push({x.ff,rad});
                vis[x.ff] = 1;
            } else {
                f2 = 0;
            }
        }
        
    }
    return siz;
}

void solve() {
    ll n,ans=0,a,last=0; cin >> n;
    unordered_map<ll,ll> nums, vis;

    loop (i,0,n) {
        cin >> a;
        nums[a]++;
    }
    for (auto x: nums) {
        vis.clear();
        ans = max(ans,bfs(x.first,vis,nums));
    }

    cout << ans;
}

int main(int argc, char const *argv[]){
    _fast
//   #ifndef ONLINE_JUDGE
//         freopen("angry.in", "r", stdin);
//         freopen("angry.out", "w", stdout);
//   #endif
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}