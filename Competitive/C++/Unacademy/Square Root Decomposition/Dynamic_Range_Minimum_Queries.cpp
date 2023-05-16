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

int B=450;
const ll MAX = 10e10;
int getBlock (int id){
    return id/B;
}
void solve() {
    ll n,q,qtype; cin >> n >> q;
    ll arr[n+1],minBlock[n/B+1];
    loop (i,0,n/B) minBlock[i] = MAX;
    loop (i,1,n) {
        cin >> arr[i];
        if (minBlock[getBlock(i)] > arr[i]) minBlock[getBlock(i)] = arr[i];
    }
 
   
    while (q--) {
               cin >> qtype;
        if (qtype == 1) {
            ll k,u,j; cin >> k >> u;
            arr[k] = u;
            minBlock[getBlock(k)] = MAX;
            
             for (int i=getBlock(k)*B;i<(getBlock(k)+1)*B && i<=n;i++) {
                if (minBlock[getBlock(i)] > arr[i]) minBlock[getBlock(i)] = arr[i];
            }  
        }
        else {
            ll a,b,min=MAX; cin >> a >> b;
            if (getBlock(a) == getBlock(b)) {
                loop (i,a,b) 
                    if (arr[i] < min) min = arr[i];
            }

            else {
                loop (i,getBlock(a)+1,getBlock(b)-1) 
                    if (minBlock[i] < min) min = minBlock[i];
                ll i = a;
                while (getBlock(i) == getBlock(a)) {
                    if (arr[i] < min) min = arr[i];
                    i++;
                }
                i = b;
                while (getBlock(i) == getBlock(b)) {
                    if (arr[i] < min) min = arr[i];
                    i--;
                }
            }
        cout << min << "\n";
    }
  }
}

int main(int argc, char const *argv[]){
    _fast
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}