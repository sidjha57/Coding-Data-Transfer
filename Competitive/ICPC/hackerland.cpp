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

const int maxn = 1e6+5;
vi least_prime(maxn,0);
bitset<maxn> vis;
void leastPrimeFactor()
{    
    ll i,j;
    least_prime[1] = 1;   
    for (i = 2; i<= maxn; i++)
    {
        if (least_prime[i] == 0)
        {
            least_prime[i] = i;
            for (j = i*i; j <= maxn; j += i)
                if (least_prime[j] == 0)
                   least_prime[j] = i;
        }
    }
}

void getFactorization(int x)
{
    // vector<int> ret;
    while (x != 1)
    {
        if (vis [least_prime[x]] == 0)
            vis[least_prime[x]] = 1;
            // ret.push_back(least_prime[x]);
        x = x / least_prime[x];
    }
    // return ret;
}
 
void solve() {
    vis.reset();
    ll n,count=0,mini,mincost=inf;
    cin>>n;
    map<ll,vi> m;
    ll a[n];
    loop(i,0,n-1) {
        cin>>a[i];
        m[least_prime[a[i]]].emplace_back(a[i]);
    }
    map<ll,ll> freq;
    ll tot2=0,tot3=0,tot=0;
    for (auto x : m[2]) {
        getFactorization(x);
    }
    loop (i,0,n-1) {
        if (vis[least_prime[a[i]]] == 0) {
            freq[least_prime[a[i]]]++;
            getFactorization(a[i]);
        } 
    }
    if (freq.size() == 0) mini =0;
    else mini = 2*(freq.size()-1) + 2*freq[1];
    
    mincost = min (mini,mincost);
    vis.reset();
    for (auto x : m[3]) {
        getFactorization(x);
    }
    map<ll,ll> freq1;
    loop (i,0,n-1) {
        if (vis[least_prime[a[i]]] == 0){
            freq1[least_prime[a[i]]]++;
            getFactorization(a[i]);
        } 
    }
    if (freq.size() == 0) mini =0;
    else {
        mini = 3*(freq1.size()-1);
        if (vis[2]) mini += freq1[1]*2;
        else mini += freq1[1]*3;
        if (freq1.size() == 0) mini = 0;
    }
    mincost = min (mini,mincost);
  
    
    cout << mincost << "\n";
    
}

int main(int argc, char const *argv[]){
    _fast
    leastPrimeFactor();
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}