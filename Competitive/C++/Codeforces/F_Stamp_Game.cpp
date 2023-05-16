// https://atcoder.jp/contests/abc228/tasks/abc228_f
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
    ll H,W,h1,w1,h2,w2; cin >> H >> W >> h1 >> w1 >> h2 >> w2;
    ll mat[H+1][W+1],rmat[H+1][W+1],cmat[H+1][W+1];
    map<ll,vector<vi>> mp;
    CLR(mat),CLR(cmat),CLR(rmat);
    loop (i,1,H) 
        loop (j,1,W)
            cin >> mat[i][j];

    if (h2 >= h1 && w2 >= w1) {
        cout << "0\n";
        return;
    }

    ll n = min(h1,h2), m = min(w1,w2);

    // row wise
     loop (i,1,H) 
        loop (j,1,W)
            rmat[i][j] += mat[i][j] + rmat[i][j-1];

    // column wise
     loop (i,1,H) 
        loop (j,1,W)
            cmat[i][j] += mat[i][j] + cmat[i-1][j];


      loop (i,1,H) 
        loop (j,1,W) 
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];

      ll i1,i2,j1,j2,ans;  
      for (i1=0,i2=h1; i2 <= H; i1++,i2++) {
          for (j1=0,j2=h1; j2 <= W; j1++,j2++) {
           ans = mat[i2][j2] - mat[i2-1][j2] - mat[i2][j2-1] + mat[i1][j1];
           mp[ans].push_back({i1,j1,i2,j2});
        }
      }

      ll mx = (*mp.rbegin()).ff;
      vector<vi> sub_mat = (*mp.rbegin()).ss;


      

        
      

    




    
}

int main(int argc, char const *argv[]){
    _fast
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}