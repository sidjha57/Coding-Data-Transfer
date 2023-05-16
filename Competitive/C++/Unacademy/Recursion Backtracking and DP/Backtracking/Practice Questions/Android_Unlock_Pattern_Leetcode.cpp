//https://www.lintcode.com/problem/909/

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
int via[10][10];
int helper (vector<bool> &visited, int curr, int remaining) {
    if (remaining < 0) return 0;
    if (remaining == 0) return 1;
    visited[curr] = true;
    int result = 0;
    for (int i = 1; i <= 9;i++) {
        if (not visited[i] and (via[curr][i] == 0 or visited[via[curr][i]])) {
            result += helper (visited, i, remaining-1);
        }
    }
    visited[curr] = false;
    return result;

}
int numberOfPatterns (int m,int n) {
    memset(via,0,sizeof(via));
    via[1][3] = via[3][1] = 2;
    via[1][7] = via[7][1] = 4;
    via[7][9] = via[9][7] = 8;
    via[3][9] = via[9][3] = 6;
    via[1][9] = via[9][1] = via[3][7] = via[7][3] = via[2][8] = via[8][2] = 5;
    vector<bool> visited(10,0);
    int ways = 0;
    for (int i=m; i<=n ; i++) {
        ways += 4*helper(visited,1,i-1); // 1,3,7,9 symmetry 
        ways += 4*helper(visited,2,i-1); // 2,4,8,6 symmetry 
        ways += helper(visited,5,i-1); 
    }
    return ways;
}
void solve() {
    ll n,m; cin >> m >> n;
    cout << numberOfPatterns(m,n);
}

int main(int argc, char const *argv[]){
    _fast
    //fileIO();
    
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}