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

void fileIO() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
char nums[10] = {'0','1','2','3','4','5','6','7','8','9'};
unordered_map<char,ll> char_num;
void num () {
  char_num['0'] = 0;  
  char_num['1'] = 1;
  char_num['2'] = 2;
  char_num['3'] = 3;
  char_num['4'] = 4;
  char_num['5'] = 5;
  char_num['6'] = 6;
  char_num['7'] = 7;
  char_num['8'] = 8;
  char_num['9'] = 9;
  
}
void solve() {
    ll n; cin >> n;
    vector<string> numbers;
    loop (i,0,n-1) {
        string num ; cin >> num ; 
        numbers.push_back(num);
    } 
    ll sum=0, carry = 0;
    string ans = "";
    looprev (j,49,0) {
        loop (i,0,n-1) {
            sum += char_num[numbers[i][j]];
        }
        carry = sum/10;
        sum %= 10;
        ans += nums[sum];
        sum = carry;
    }
    string car = to_string(carry);
    loop (i,0,car.size()-1)
        ans += car[i];
    looprev(i,ans.size()-1,ans.size()-10)
    cout << ans[i];
}

int main(int argc, char const *argv[]){
    _fast
    //fileIO();
    num();
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}