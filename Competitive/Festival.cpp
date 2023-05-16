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

void solve(ll t) {
    ll d,n,k; cin >> d >> n >> k;
    ll days[d+1],happiness[d+1];
    CLR(days),CLR(happiness);
    loop (i,0,n-1) {
        ll h,a,b;
        cin >> h >> a >> b;
        happiness[a] += h;
        days[a] += 1;
        if (b+1 <= d ) {
            days[b+1] += -1;
            happiness[b+1] += -h;
        }
    }
    loop (i,1,d) {
        happiness[i] += happiness[i-1];
        days[i] += days[i-1];
    }
    ll ans = 0;
    loop (i,1,d) {
        if (days[i] <= k) {
            ans = max(ans,happiness[i]);
        }
    }
    cout << "Case #" << t << ": " << ans << "\n";
}
// void solve (ll t) {
//     ll d,k,n; cin >> d >> n >> k;
//     vector<multiset<ll,greater<ll>>> happiness(d+1); 
//     loop (i,0,n-1) {
//         ll h,a,b; cin >> h >> a >> b;
//         loop (i,a,b) happiness[i].emplace(h);
//     }
//     ll ans = 0;
//     loop (i,1,d) {
//         ll hap = 0,j=k;
//         for (auto x : happiness[i]) {
//             hap += x;
//             j--;
//             if (j == 0) break;
//         } 
//         ans = max(ans, hap);
//     }
//     cout << "Case #" << t << ": " << ans << "\n";
// }

int main(int argc, char const *argv[]){
    _fast
    //fileIO();
    ll t,i=1; cin>>t;
    while(t--){
     solve(i);
     i++;
    }
  return 0;
}