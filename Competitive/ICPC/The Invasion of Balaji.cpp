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
    ll n,q,lsum=0,rsum=0,sum=-inf,maxi=-inf,max_el=-inf; cin >> n >> q;
    ll a[n],t[n],pre_sum[n],suf_sum[n],pre_max[n],suf_max[n];
    loop (i,0,n-1) {
        cin >> a[i];
        max_el = max(max_el,a[i]);
    }
    loop (i,0,n-1) 
        cin >> t[i];
        
    loop (i,0,n-1) {
        pre_sum[i] = suf_sum[i] = 0;
        pre_max[i] = suf_max[i] = -inf;
    }

    pre_sum[0] = a[0],pre_max[0]=a[0],suf_sum[n-1]=a[n-1],suf_max[n-1]=a[n-1];
    loop (i,1,n-1) {
        pre_sum[i] += a[i] + pre_sum[i-1];
        pre_max[i] = max(pre_sum[i],pre_max[i-1]);
        suf_sum[n-i-1] += a[n-i-1] + suf_sum[n-i];
        suf_max[n-i-1] = max(suf_sum[n-i-1],suf_max[n-i]);
    }

    rsum = q*t[0] + a[0];
    if (pre_max[n-1]-a[0] > 0) rsum += pre_max[n-1]-a[0];

    lsum = q*t[n-1] + a[n-1];
    if (suf_max[0]-a[n-1] > 0) lsum += suf_max[0]-a[n-1]; 
    
    maxi = max({sum,lsum,rsum,max_el,pre_sum[n-1]});

    loop (i,1,n-2) {
        rsum = pre_max[n-1] - pre_sum[i];
        lsum = suf_max[0] - suf_sum[i];
        sum = q*t[i] + a[i]; 
        if (rsum > 0) sum += rsum;
        if (lsum > 0) sum += lsum;
        maxi = max(sum,maxi); 
    }
    
    if (maxi < 0) maxi = 0;
    
    cout << maxi << "\n"; 
}

int main(int argc, char const *argv[]){
    _fast
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}


// U[i] = T[i]*q + u[I]

//10 -5 -5 -1  30 15 -10
//q = 2
// 1 -10 30 5 -1 -2 -3 6 500 600 700
// 1 15 14 1 -100 -100 -100 26 -1000 -1000 -1000 -1000

// 3 20 58 7 -5 -6 -7 5
// -9 -10 58 5
// 63

//  