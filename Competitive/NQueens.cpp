//Siddharth Jha

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

#define ll                       long long int
#define mod                      1000000007
#define inf                      1e18
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

bool check (ll n, ll i, ll j, vector<vector<char>>& grid,vi& col, vi& left_diag, vi& right_diag, ll& ans) {
    if (i >= 0 && j >= 0 && i < n && j < n and !col[j] and !left_diag[j-i+n] and !right_diag[i+j]) return true;
    return false;
}

void display (vector<vector<char>>& grid,ll n) {
    loop (i,0,n-1) {
        loop (j,0,n-1) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

void NQueens (ll n, ll row, vector<vector<char>>& grid,vi& col, vi& left_diag, vi& right_diag, ll& ans) {
    //base case
    if (row == n) {
        ans ++;
        display(grid,n);
        return;
    }
    loop (c,0,n-1) {
        if (check(n,row,c,grid,col,left_diag,right_diag,ans)) {
            col[c] = 1, left_diag[c-row+n] = 1, right_diag[row+c] = 1;
            grid[row][c] = 'Q';
            // recursion
            NQueens (n,row+1,grid,col,left_diag,right_diag,ans);
            // prunning 
            grid[row][c] = '.';
            col[c] = 0, left_diag[c-row+n] = 0, right_diag[row+c] = 0;
        }
    }
}
void solve() {
    ll n; cin >> n;
    vi col(n,0),left_diag(2*n+1,0),right_diag(2*n+1,0);
    vector<vector<char>> grid (n,vector<char>(n,'.'));
    ll ans = 0;
    NQueens(n,0,grid,col,left_diag,right_diag,ans);
    cout << ans << "\n";

}

int main(int argc, char const *argv[]){
    _fast
  //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
  //#endif
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}