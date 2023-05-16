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

void fileIO() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
bool check (ll x1, ll y1, ll x2, ll y2) {
    if (x1 == x2 || y1 == y2) return true;
    if (abs (x1 - x2) == abs (y1 - y2)) return true;
    return false;
}

ll point (ld x0, ld y0, ll *x, ll *y, ll n) {
     ll ans = 0;
     loop (k,0,n-1) {
        if (x0 == x[k] && y0 == y[k]) continue;
        if  (check(x0,y0,x[k],y[k])) ans++;
        else ans += 2;
    }
    return ans;
}

void solve() {
    ll n; cin >> n; 
    ll x[n],y[n],ans=0,mini=inf;
    ld x0,y0;
    loop (i,0,n-1) cin>>x[i];
    loop (i,0,n-1) cin>>y[i];
    loop (i,0,n-1) {
        loop (j,0,n-1) {
            // point taken x[i] and y[j]
            x0 = x[i],y0 = y[j];
            mini = min (mini,point(x0,y0,x,y,n));

            // mean point (x[i] + x[j])/2 and (y[j] + y[i])/2
            x0 = (x[i] + x[j])/2 ,y0 = (y[i] + y[j])/2;
            mini = min (mini,point(x0,y0,x,y,n));

            // another point (x[i] + y[i]) and (x[j] - y[j])
            ld c1 = (x[i] + y[i]), c2 = (x[j] - y[j]);
            x0 = (c1 + c2)/2 , y0 = (c1 - c2)/2;
            mini = min (mini,point(x0,y0,x,y,n));

            // another point (x[i] + y[i]) and x[j] 
            ld c3 = (x[i] + y[i]);
            x0 = x[j] , y0 = c3 - x0;
            mini = min (mini,point(x0,y0,x,y,n));

            // another point (x[i] + y[i]) and y[j]
            ld c4 = (x[i] + y[i]);
            y0 = y[j]  , x0 = c4 - y0;
            mini = min (mini,point(x0,y0,x,y,n));

            // another point (x[i] - y[i]) and x[j] 
            ld c5 = (x[i] - y[i]);
            x0 = x[j] , y0 = x0 - c5;
            mini = min (mini,point(x0,y0,x,y,n));

            // another point (x[i] - y[i]) and   y[j]
            ld c6 = (x[i] - y[i]);
            y0 = y[j] , x0 = c6 - y0;
            mini = min (mini,point(x0,y0,x,y,n));
        }
        
    }
    cout << mini <<"\n";
}

int main(int argc, char const *argv[]){
    _fast
    //fileIO();
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}
