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
void solve(ll t) {
    ll n; cin >> n;
    ll grid[n][n];
    char ch;
    loop (i,0,n-1) {
        loop (j,0,n-1) {
            cin >> ch;
            if (ch == '.') grid[i][j] = 0;
            else if (ch == 'X') grid[i][j] = 1;
            else grid[i][j] = -1;
        }
    }
    ll cntr = 0,cntc=0;
    bool posr = true,posc = true;
    map <ll,ll> freq;
    ll i,j,idxj;
    ll vis[n];
    SET(vis);
    // row wise 
   for (i=0; i<n; i++) {
        cntr = 0; posr = true;
        for (j =0;j<n;j++) {
            // row wise
            if (grid[i][j] == -1) {
                posr = false;
                break;
            } else if (grid[i][j] == 0) {
                idxj=j;
            }
            if (grid[i][j] == 1) cntr++;
        }
        if (posr) {
            freq[n-cntr]++;
        }
        if (cntr == n-1) {
            vis[i] = idxj;
        }
    }
    idxj = -2;
    // column wise 
   for (i=0; i<n; i++) {
        cntc = 0; posc = true;
        for (j =0;j<n;j++) {
            // row wise
            if (grid[j][i] == -1) {
                posc = false;
                break;
            } else if (grid[j][i] == 0) {
                idxj = j;
            }
            if (grid[j][i] == 1) cntc++;
        }
        if (posc) {
            if (cntc == n-1 && vis[idxj] != i) freq[n-cntc]++;
            else if (cntc < n-1) freq[n-cntc]++;
        }
   
    }

    if (freq.size() == 0) {
        cout << "Case #" << t << ": Impossible\n"; 
    } else {
        auto k = *freq.begin();
        cout << "Case #" << t << ": " << k.ff << " " << k.ss << "\n";
    }
}

int main(int argc, char const *argv[]){
    _fast
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    ll i = 1;
    while(t--){
     solve(i);
     i++;
    }
  return 0;
}