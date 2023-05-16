//Siddharth Jha
// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6#problem

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

ll dp[20][2][2][2];

ll Digit_DP (string num, ll n,bool even, bool lead, bool tight) {
    if (n == 0) return 1;

    ll &ans = dp[n][even][lead][tight],ub,answer=0;
    if (ans > -1) return ans;

    if (even) {
        ub = (tight)? (num[num.size() - n] - '0') : 9;
        for (int d=0; d <= ub; d += 2)
            answer += Digit_DP (num, n-1, 0, 0, (tight & (ub == d)));
        return ans = answer;

    } else {
        ub = (tight)? (num[num.size() - n] - '0') : 9;
        if (lead) 
            answer += Digit_DP (num, n-1, 0, 1, 0);
        for (int d=1; d <= ub; d += 2)
            answer += Digit_DP (num, n-1, 1, 0, (tight & (ub == d)));
        return ans=answer;
    }

    // return ans;
    
}

void solve(ll test) {
    ll l,r; cin >> l >> r;
    l--;
    string L=to_string(l),R=to_string(r); 

    SET(dp);
    ll ans = Digit_DP(R,R.size(),0,1,1);
    SET(dp);

    ans -= Digit_DP(L,L.size(),0,1,1);

    cout << "Case #" << test << ": " << ans << "\n";
    
}

int main(int argc, char const *argv[]){
    _fast
    ll t,test=1; cin>>t;

    while(t--){
     solve(test);
     test++;
    }
  return 0;
}