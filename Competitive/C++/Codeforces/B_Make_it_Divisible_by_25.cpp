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
#define eb                       emplace_back
#define em                       emplace
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
#define loop(i,a,b)              for(ll i=(a);i<=(b);i++)
#define looprev(i,a,b)           for(ll i=(a);i>=(b);i--)
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

void solve() {
    string s; cin >> s;
    ll N = s.size();
    ll mn = inf;
    unordered_map<char,vi> freq;
    loop (i,0,s.size()-1) {
        if (s[i] == '0' || s[i] == '5' || s[i] == '7' || s[i] == '2') {
            freq[s[i]].pb(i);
        }
    }
    
    bool f0=0,f2=0,f5=0,f7=0;
    vi zeros,twos,fives,sevens;
    if (freq.find('0') != freq.end()) {
        zeros = freq['0']; f0 = 1;
    }
    if (freq.find('2') != freq.end()) {
        twos = freq['2']; f2 = 1;
    }
     if (freq.find('5') != freq.end()) {
        fives = freq['5']; f5 = 1;
    }
     if (freq.find('7') != freq.end()) {
        sevens = freq['7']; f7 = 1;
    }

    // 00
    if (f0 && zeros.size() > 1) {
        ll n = zeros.size()-1;
        looprev (i,n-1,0) {
            ll x = inf;
            if (zeros[i] != N-1)
                x = (N - zeros[i] -2);
            if (x < mn)
            mn = x;
        }
    }

    // 25
    if (f2 && f5) {
        ll n = twos.size()-1, m = fives.size()-1;
        looprev (i,n,0) {
            looprev (j,m,0) {
                ll x = inf;
                if (twos[i] != N-1)
                    x = (N - twos[i] -2);
                
                if (twos[i] < fives[j] && x < mn)
                 mn = x;
            }
        }
    }

    // 50
    if (f0 && f5) {
        ll m = zeros.size()-1, n = fives.size()-1;
        looprev (i,n,0) {
            looprev (j,m,0) {
                ll x = inf;
                if (fives[i] != N-1)
                    x = (N - fives[i] -2);

                if (fives[i] < zeros[j] && x < mn)
                 mn = x;
            }
        }
    }

    //75 
    if (f7 && f5) {
        ll n = sevens.size()-1, m = fives.size()-1;
        looprev (i,n,0) {
            looprev (j,m,0) {
                ll x = inf;
                if (sevens[i] != N-1)
                    x= (N - sevens[i] -2);
               
                if (sevens[i] < fives[j] && x < mn)
                 mn = x;
            }
        }
    }
    
    cout << mn << "\n";
}

int main(int argc, char const *argv[]){
    _fast
    //fileIO();
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}