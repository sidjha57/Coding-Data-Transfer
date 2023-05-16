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

void solve() {
    ll n,q,v,t,x0,x1,x2,y0,y1,y2,i1,i2,j1,j2,d; 
    cin >> n >> q;
    vector<pii> pts (n);
    loop (i,0,n-1) cin >> pts[i].ff >> pts[i].ss;
    ld init_area = 0.0,perimeter = 0.0,sum_cot_2 = 0.0,cos_theta;
    loop (i,0,n-1) {
        x0 = pts[(i-1+n)%n].ff,y0 = pts[(i-1+n)%n].ss ;
        x1 = pts[i].ff,y1 = pts[i].ss;
        x2 = pts[(i+1)%n].ff, y2 = pts[(i+1)%n].ss;
        init_area += (x1*y2) - (x2*y1); // shoelace formula to calculate area of a convex polygon
        perimeter += sqrtl ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
        i1 = x2-x1,j1 = y2-y1; // vector from {x2,y2} -> {x1,y1} 
        i2 = x0-x1, j2 = y0-y1; // vector from {x0,y0} -> {x1,y1}
        cos_theta = (i1*i2 + j1*j2)/ (sqrtl(i1*i1 + j1*j1) * sqrtl (i2*i2 + j2*j2)); // a.b/(|a|*|b|) dot product
        sum_cot_2 += sqrtl ( (1 + cos_theta ) / (1 - cos_theta)); // cot(x/2) = root ((1+cos(x) / (1-cos(x))
    }
    init_area = init_area / 2.0; 

    while (q--) {
        cin >> v >> t;
        d = v*t;
        cout << fixed << setprecision(12) << (init_area + perimeter*d + sum_cot_2*d*d) << "\n";
    }
}

int main(int argc, char const *argv[]){
    _fast
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}