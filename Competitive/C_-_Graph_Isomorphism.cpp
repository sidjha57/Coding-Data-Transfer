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

void solve() {
    ll n,m; cin >> n >> m;

    vector<vi> grapha(n+1,vi(n+1,0)),graphb(n+1,vi(n+1,0));
    loop (i,0,m) {
        ll u,v; cin >> u >> v;
        grapha[u][v] = 1, grapha[v][u] = 1;
    }
    loop (i,0,m) {
        ll u,v; cin >> u >> v;
        graphb[u][v] = 1, graphb[v][u] = 1;
    }
    vi p (n);
    loop (i,1,n+1) p[i-1] = i;
    do {
        bool f = 1;
        
        loop (i,1,n+1) {
            loop (j,1,n+1) {
                if (grapha[i][j]) {
                    if (!graphb[p[i-1]][p[j-1]]){
                        f = 0; break;
                    }
                }
            }
            if (!f) break;
        }
        
        if (f) {
            // loop (i,0,n) cout << p[i] << " ";
            cout << "Yes\n";
            return;
        }

    } while (next_permutation(all(p)));

    cout << "No\n";
}

int main(int argc, char const *argv[]){
    _fast
  //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
  //#endif
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}