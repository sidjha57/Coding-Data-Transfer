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


void solve(int t) {
    ll n,q,a,b,a1,b1; cin >> n >> q;
    ll ans[q];
    map<ll,ll> problems;
    while (n--) {
        cin >> a >> b;
        problems.emplace(mp(a,b));
    }

    loop (i,0,q-1) {
        ll sk; cin >> sk;
        auto k = problems.upper_bound(sk);
        auto k1=k;
        
        // case 1 when skill is less than all
        if (k == problems.begin()) {
            a = (*k).ff, b = (*k).ss;
            ans[i] = a;
            problems.erase(a);
            if (a+1 <= b) problems[a+1] = b;
        } else if (k == problems.end()) { // case 2 when skill is greater than all
             k--;
             a = (*k).ff, b = (*k).ss;
             if (sk > b) {
                 ans[i] = b;
                 problems.erase(a);
                 if (a <= b-1) problems[a] = b-1;
             } else { // its in between
                    ans[i] = sk;
                    problems.erase(a);
                    if (a <= sk-1) problems[a] = sk-1;
                    if (sk+1 <= b) problems[sk+1] = b;
             }
        } else {
            k1 = k;
            k1--;
            a = (*k1).ff, b = (*k1).ss,
            a1 = (*k).ff, b1 = (*k).ss;
            // case 3 inside some range
            if (a <= sk && sk <= b) {
                ans[i] = sk;
                problems.erase(a);
                if (a <= sk-1) problems[a] = sk-1;
                if (sk+1 <= b) problems[sk+1] = b;
            } else {
                // case 4 in between some range
                if (abs(sk-b) <= abs(sk-a1)) {
                    ans[i] = b;
                    problems.erase(a);
                    if (a <= b-1) problems[a] = b-1;
                } else {
                    ans[i] = a1;
                    problems.erase(a1);
                    if (a1+1 <= b1) problems[a1+1] = b1;
                }
            }
        }

    }


    cout << "Case #" << t << ": ";
    loop (i,0,q-1) cout << ans[i] << " ";
    cout << "\n";

}

int main(int argc, char const *argv[]){
    _fast
    ll t,i=1; cin>>t;
    while(t--){
     solve(i);
     i++;
    }
  return 0;
}