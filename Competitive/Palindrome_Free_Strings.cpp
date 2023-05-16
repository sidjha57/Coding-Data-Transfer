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
bool isPalindromic(string s, int i, int j) {   
    if (i > j) return 1;

    if (s[i] != s[j]) return  0;

    return isPalindromic(s, i + 1, j - 1);
}

bool check (string & str) {
    int count =0;
    
    for(int i=0;i<str.length();i++){
        for(int j=i+4;j<str.length();j++){
            if(isPalindromic(str,i,j)){
                return 0;
            }    
        }
    }
    return 1;
}
 
void solve(ll test) {
    ll n; cin >> n;
    vi idx;
    string s; cin >> s;
    
    ll q = 0;
    cout << "Case #" << test << ": ";
    if (s.size() < 5) {
        cout << "POSSIBLE\n";
        return;
    }

    loop (i,0,n-1) {
        if (s[i] == '?') {
            idx.pb(i);
            q++;
        }
    }
    for (int mask = 0; mask < (1 << q); mask++) {
		loop (j,0,q-1) {
            if (mask & (1 << (q - j - 1))) s[idx[j]] = '1';
            else s[idx[j]] = '0';
        }
        
        if (check(s)) {
            cout << "POSSIBLE\n";
            return;
        }
	}
    cout << "IMPOSSIBLE\n";
}

int main(int argc, char const *argv[]){
    _fast
  //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
  //#endif
    ll t,i=1; cin>>t;
    while(t--){
     solve(i);
     i++;
    }
  return 0;
}