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
    ll c,r,k; cin >> c >> r >> k;
    ll r1,c1,r2,c2; cin >> r1 >> c1 >> r2 >> c2;
    // r1 = r-r1,r2 = r-r2,c1 = c-c1,c2 = c-c2;
    ll len = c2-c1+1,bred = r2-r1+1; 
    ll mini = min ({r1,r2,c1,c2});
    ll tot = 0;
    if (r1 == 1 || r1 == r || r2 == 1 || r2 == r || c1 == 1 || c1 == c || c2 == 1 || c2 == c) {
        if (r1 == 1) {
            tot += (len/k + len%k)*bred + (bred/k + bred%k)*len;
        } 
        cout << "Case #" << t << ": " << tot << "\n";
        return;
    }
    if (mini == r1 || mini == r2) {
        if (mini == r1) {
            if ( (r1 + abs(r2-r1)) % k == 0) 
                tot += (r1 + abs(r2-r1)) / k;
            else {
                tot += (r1 + abs(r2-r1)) / k;
            }
        } else {
             if ( (r2 + abs(r2-r1)) % k == 0) 
                tot += (r2 + abs(r2-r1)) / k;
            else {
                tot += (r2 + abs(r2-r1)) / k;
            }
        }

        if (bred%k == 0) {
            tot += (bred/k)*(len);
        } else {
            tot += (bred/k + bred%k)*(len);
        }
        if (len % k == 0) {
            tot += (len/k)*(bred+1);
        }
    } else {
        if (mini == c1) {
            if ( (c1 + abs(c2-c1)) % k == 0) 
                tot += (c1 + abs(c2-c1)) / k;
            else {
                tot += (c1 + abs(c2-c1)) / k;
            }
        } else {
             if ( (c2 + abs(c2-c1)) % k == 0) 
                tot += (c2 + abs(c2-c1)) / k;
            else {
                tot += (c2 + abs(c2-c1)) / k;
            }
        }

        if (len%k == 0) {
            
            tot += (len/k)*(bred);
        } else {
            
            tot += (len/k + len%k)*(bred);
        }
        if (bred % k == 0) {
            tot += (bred/k)*(len+1);
        }
    }

    cout << "Case #" << t << ": " << tot << "\n";
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