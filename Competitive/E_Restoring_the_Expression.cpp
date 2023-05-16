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
bool check (string& a, string& b, string& c) {
    bool f = 0;
    if (a.length() > b.length()) {
        f = 1;
        swap(a, b);
    }
    string str = "";
 
    ll carry = 0;
 
    reverse(all(a));
    reverse(all(b));
 
    loop(i,0,a.size()-1) {
        
        int sum = ((a[i]-'0')+(b[i]-'0')+carry);
        str.push_back(sum%10 + '0');
 
        carry = sum/10;
    }
 
  
    loop(i,a.size(),b.size()-1) {
        int sum = ((b[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    if (carry)
        str.push_back(carry+'0');

    reverse(all(str));
    reverse(all(a));
    reverse(all(b));
    if (f) swap(a,b);

    // log(str,c);
    
    return c == str;
}
void solve() {
    string s,a,b,c; cin >> s;
    ll n = s.size(),k = n/3;

   
        ll id = n-1;
        looprev (i,n-1,0) {
            if (s[i] == '1') {
                c += "1";
                id = i;
                // reverse(all(c));
                break;
            }
            c += s[i];
        }

        // log(c);
        looprev (i,id-1,0) {
            if (s[i] == '1') {
                id = i;
                reverse(all(c));
                break;
            }
            b += s[i];
        }
        // log(b);
        loop (i,0,id) 
            a += s[i];

        // log(a);
        
        if (a.size() > 0 && b.size() > 0 && c.size() && check(a,b,c)) {
            cout << a << "+" << b << "=" << c;
            return;
        }
    

    if (n%3 == 0) {
        // n/3 + n/3 = n/3
        a = s.substr(0,k);
        b = s.substr(k,k);
        c = s.substr(2*k,k);
        if (check(a,b,c)) {
            cout << a << "+" << b << "=" << c;
            return;
        } 

        // n/3-1 + n/3 = n/3
        a = s.substr(0,k-1);
        b = s.substr(k-1,k);
        c = s.substr(2*k-1,k+1);
        if (check(a,b,c)) {
            cout << a << "+" << b << "=" << c;
            return;
        }

        // n/3 + n/3-1 = n/3
        a = s.substr(0,k);
        b = s.substr(k,k-1);
        c = s.substr(2*k-1,k+1);
        if (check(a,b,c)) {
            cout << a << "+" << b << "=" << c;
            return;
        }
        
    }

    if (n%3 == 1) {
        // n/3 + n/3 = n/3+1
        a = s.substr(0,k);
        b = s.substr(k,k);
        c = s.substr(2*k,k+1);
        if (check(a,b,c)) {
            cout << a << "+" << b << "=" << c;
            return;
        } 

        // n/3-1 + n/3+1 = n/3+1
        a = s.substr(0,k-1);
        b = s.substr(k-1,k+1);
        c = s.substr(2*k,k+1);
        if (check(a,b,c)) {
            cout << a << "+" << b << "=" << c;
            return;
        }

        // n/3+1 + n/3-1 = n/3+1
        a = s.substr(0,k+1);
        b = s.substr(k+1,k);
        c = s.substr(2*k,k+1);
        if (check(a,b,c)) {
            cout << a << "+" << b << "=" << c;
            return;
        }
    }

    if (n%3 == 2) {
        // n/3 + n/3 = n/3+2
        a = s.substr(0,k);
        b = s.substr(k,k);
        c = s.substr(2*k,k+2);
        if (check(a,b,c)) {
            cout << a << "+" << b << "=" << c;
            return;
        } 

        // n/3+1 + n/3 = n/3+1
        a = s.substr(0,k+1);
        b = s.substr(k+1,k);
        c = s.substr(2*k+1,k+1);
        if (check(a,b,c)) {
            cout << a << "+" << b << "=" << c;
            return;
        }

        // n/3 + n/3+1 = n/3+1
        a = s.substr(0,k);
        b = s.substr(k,k+1);
        c = s.substr(2*k+1,k+1);
        if (check(a,b,c)) {
            cout << a << "+" << b << "=" << c;
            return;
        }
    }
}

int main(int argc, char const *argv[]){
    _fast
  //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
  //#endif
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}