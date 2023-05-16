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
   ll n,m,i,j,k;cin >> n >> m >> k;
   ll Alice[n][m],Bob[n][m],SAlice[n][m],SBob[n][m];
    loop (k,0,n*m-1) {
        ll i,j; cin >> i >> j;
        if (k&1) {
            Bob[i-1][j-1] = 1;
            Alice[i-1][j-1] = 0;
        }
        else {
            Bob[i-1][j-1] = 0;
            Alice[i-1][j-1] = 1;
        }
    }

       /* Set first column of S[][]*/
    for( i = 0; i < n; i++) {
        SAlice[i][0] = Alice[i][0];
        SBob[i][0] = Bob[i][0];
    }
     
    /* Set first row of S[][]*/
    for( j = 0; j < m; j++) {
        SAlice[0][j] = Alice[0][j];
        SBob[0][j] = Bob[0][j];
    }
         
    /* Construct other entries of S[][]*/
    for(i = 1; i < n; i++)
    {
        for(j = 1; j < m; j++)
        {
            if(Alice[i][j] == 1)
                SAlice[i][j] = min(SAlice[i][j-1],min( SAlice[i-1][j],
                                SAlice[i-1][j-1])) + 1;
            else
                SAlice[i][j] = 0;
            
            if(Bob[i][j] == 1)
                SBob[i][j] = min(SBob[i][j-1],min( SBob[i-1][j],
                                SBob[i-1][j-1])) + 1;
            else
                SBob[i][j] = 0;
        }
    }

    bool b=false,a=false;

    loop (i,0,n) {
        loop (i,0,m) {
            if (SAlice[i][j] == k) a=true;
            if (SBob[i][j] == k) b=true;
        }
    }

    if ((a^b) == 0) cout << "Draw\n";
    else if (a) cout << "Alice\n";
    else if (b) cout << "Bob\n";

}

int main(int argc, char const *argv[]){
    _fast
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}