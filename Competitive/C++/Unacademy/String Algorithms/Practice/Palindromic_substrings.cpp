//https://leetcode.com/problems/palindromic-substrings/

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

vi pre,suf;
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
bool check (ll i,ll j, ll len, ll n) {
    ll left,right,pow_31=1;
    if (i-len+1 >= 0 && j+len <= n) {
        if (i-len+1 == 0) left = pre[i];
        else {
            left = pre[i] - pre[i-len];
            pow_31 = binpow(31,i-len+1,mod);
            left = left*binpow(pow_31,mod-2,mod);
            left %= mod;
        }
        if (j+len == n) right = suf[j];
        else {
            right = suf[j] - suf[j+len];
            pow_31 = binpow(31,(n-j-1),mod);
            right = right*binpow(pow_31,mod-2,mod);
            right %= mod;
        }
        if (left == right) 
            return true;
    }
    return false;
}

int countSubstrings(string s) {
    ll n = s.size(),pow_31=31,ans=0;
    pre.assign(n,0), suf.assign(n,0); 
    pre[0] = s[0] - 'a'+1;
    suf[n-1] = s[n-1] - 'a'+1;
    loop (i,1,n-1) {
        pre[i] = pow_31*(s[i] - 'a' + 1) + pre[i-1];
        pre[i] %= mod;
        suf[n-i-1] = pow_31*(s[n-i-1] - 'a' + 1) + suf[n-i];
        suf[n-i-1] %= mod;
        pow_31 = pow_31*31;
        pow_31 %= mod;
    }
    loop (i,0,n-1) {
        ll l = 0,r=n;
        while (r > l+1) {
            ll mid = l + (r-l)/2;
            if (mid == 1 || check(i-1,i+1,mid,n))
                l = mid;
            else
                r = mid;
        }
        ans += (2*l+2)/2;
    }
    loop (i,0,n-1) {
        ll l = 0,r=n;
        while (r > l+1) {
            ll mid = l + (r-l)/2;
            if (check(i-1,i,mid,n))
                l = mid;
            else
                r = mid;
        }
        ans += (2*l+1)/2;
    }
    
    return ans;
}


int main(int argc, char const *argv[]){
    _fast
    ll t=1;
    while(t--){
     string s; cin >> s;
     cout << countSubstrings(s);
    }
  return 0;
}