//https://www.codechef.com/FOUR21B/problems/S03E02

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

// void solve() {
//     ll n,k,idx; cin >> n >> k;
//     string s,s1=""; cin >> s;
//     vi overall_freq(26,0),freq(26,0);
//     if (k == 0) {
//         cout << "-1\n";
//         return;
//     }
//     char last = 'a';
//     loop (i,0,s.size()-1) {
//         overall_freq[(s[i] - 'A')]++;
//         if (last != s[i]) s1 += s[i];
//         last = s[i];
//     }

//     if (k == 1) {
//         int len = 1;
//         char c = s[0];
//         loop (i,1,s.size()-1) {
//             if (c != s[i]) {
//                 len = i;
//                 break;
//             }
//         }
        
//         c = s[s.size()-1];
//         looprev (i,s.size()-2,0) {
//             if (c != s[i]) {
//                 len = max (len, int(s.size()-i-1));
//                 break;
//             }
//         }
//         cout << len << "\n";
//         return;
//     }
//     vi vis(26,0);
//     loop (i,0,s1.size()-1) {
//         idx = (s1[i] - 'A');
//         if (!vis[idx]) {
//             freq[idx] = 2;
//             vis[idx]=1;
//         } else {
//             freq[idx]++;
//         }

//     }
//     idx = s1[0] - 'A';
//     freq[idx]--;
//     idx = s1[s1.size()-1] - 'A';
//     freq[idx]--;
//     ll mn =-inf;
//     loop (i,0,25) {
//         if (freq[i] <= k) {
//             mn = max (mn,overall_freq[i]);
//         }
//     }
//     cout << mn << "\n";
// }

void solve () {
    ll n,k,idx; cin >> n >> k;
    string s; cin >> s;
    if (k == 0) {
        cout << "-1\n";
        return;
    }
    // if (k == 1) {
    //     int len = 1;
    //     char c = s[0];
    //     loop (i,1,n-1) {
    //         if (c != s[i]) {
    //             len = i;
    //             break;
    //         }
    //     }
        
    //     c = s[n-1];
    //     looprev (i,n-2,0) {
    //         if (c != s[i]) {
    //             len = max (len, int(s.size()-i-1));
    //             break;
    //         }
    //     }
    //     cout << len << "\n";
    //     return;
    // }
    // vector<vi> prefix_freq (n,vi (26,0));
    // idx = s[0] - 'A';
    // prefix_freq[0][idx] = 1;
    // loop (i,1,n-1) {
    //     idx = s[i] - 'A';
    //     prefix_freq[i][idx] += prefix_freq[i-1][idx];
    //     loop (j,0,25) {
    //         if (idx != j) prefix_freq[i][j] = prefix_freq[i][j-1];
    //     }
    // }

    // loop (i,0,25) {
    //     if (prefix_freq[n-1][i] == n) {
    //         cout << n << "\n";
    //         return;
    //     }
    // }

    vector<pii> k_val (26, {k+1,0});
    idx = s[0] - 'A';
    k_val[0] = {k,1};
    char last = s[0];
    loop (i,1,n-1) {
        idx = s[i] - 'A';
        if (last != s[i]) {
            if (k_val[idx].ff > 0) {
                k_val[idx].ff--,k_val[idx].ss++;
            }
        } else {
            k_val[idx].ss++;
        }
        last = s[i];
    }
    ll mx = -inf;
    loop (i,0,25) {
        mx = max(mx,k_val[i].ss);
    }
    cout << mx << "\n";
}



int main(int argc, char const *argv[]){
    _fast
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}