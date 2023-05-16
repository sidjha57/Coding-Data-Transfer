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
/*
        x = 10 y = 2  n = 6

        0 1 2 3 4 5 
        . . . . . *

        j = 0 and j = 1 two = 1  j = 2 

        j = 2 and j = 3 two = 2  j = 4

        j = 4 and j = 5 

        0 1 2 3 4 5
        * * . . * *

        j = 0 and j = 1 

        j = 1 and j = 2

        j = 2 and j = 3  two = 3 j = 4

        j = 4 and j = 5 

        0 1 2 3 4 5
        . . . * * *

        j = 0 and j = 1 two = 4 j = 2
        j = 2 and j = 3 
        j = 3 and j = 4

*/
void solve() {
    ll n, m, x , y,white_cell_count=0,adj_white_cell_count=0; 
    cin >> n >> m >> x >> y;
    char grid[n][m];

    loop (i,0,n-1) 
        loop (j,0,m-1) {
            cin >> grid[i][j];
            if (grid[i][j] == '.') 
                white_cell_count++;
        }
    
    // when we paint one cell at a time as x+x is less than or equal to y
    if (2*x <= y) {
        cout << x*white_cell_count << "\n";
    } else {
        loop (i,0,n-1) {
            loop (j,0,m-2) {
               if (grid[i][j] == '.' && grid[i][j+1] == '.') {
                   adj_white_cell_count++;
                   j++;
               }
            }
        }
        ll one_cells = white_cell_count - 2*adj_white_cell_count;
        cout << y*adj_white_cell_count + x*one_cells << "\n";
    }

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


