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
ll x,y,l,r; 
string bitx="",bity="",strx="";
vector<int> idx;
string deci_bin (ll n) {
    string ans = "";
    while (n > 0) {
        (n&1)? ans += '1': ans += '0';
        n /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

bool check (string s, string str) {
    idx = prefix_function(str);
    l = 0,r=0;
    loop (i,0,idx.size()) {
        if (idx[i] == s.size()) r = i;
    }
    if (r != 0) {
        r = r - (s.size() + 1);
        l = r-s.size();        
        bool f = 1;
        loop (i,0,l) 
            if (bity[i] == '0') f = 0;
        loop (i,r+1,bity.size()-1) 
            if (bity[i] == '0') f = 0;
        
        if (f && (bity[bity.size()-1] != '0')) 
            return 1;
    }
    return 0;
}
void solve() {
    cin >> x >> y;
    bitx = deci_bin(x), bity = deci_bin(y);

    if ( x == y) {
        cout << "YES\n";
        return;
    }

    // Case 1 : 1's are added without reversing x  
    if (check(bitx,bitx + '#' + bity)) {
        cout << "YES\n";
        return;
    }
   
    // Case 2 : 0's from last of x are discarded 
    ll j=bitx.size()-1;
    looprev (k,bitx.size()-1,0) {
        if (bitx[k] == '1') {
            j = k+1;
            break;
        }
    }

    strx = bitx.substr(0,j);
    if (check(strx,strx + '#' + bity)) {
        cout << "YES\n";
        return;
    }
 
    reverse(strx.begin(), strx.end());
    if (check(strx,strx + '#' + bity)) {
        cout << "YES\n";
        return;
    }
    
    // Case 3 : add 1 in bitx

    bitx += '1';
    if (check(bitx,bitx + '#' + bity)) {
        cout << "YES\n";
        return;
    }

    reverse(bitx.begin(), bitx.end());
    if (check(bitx,bitx + '#' + bity)) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
    
}

int main(int argc, char const *argv[]){
    _fast
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}
// 10100
// 1001011111