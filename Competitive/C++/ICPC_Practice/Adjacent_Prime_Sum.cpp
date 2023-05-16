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


vector<char> is_prime(2005, true);

void prime_sieve () {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 2005; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 2005; j += i)
                is_prime[j] = false;
        }
    }
}

void solve() {
      ll n, sum,j,idx; cin >> n; 
     
      ll arr[n]; bool flag;
      if ((n&1) == 1) {
          cout << "-1\n";
          return;
      }
      loop (i,0,n-1) arr[i] = i+1; // 1 2 3 4 5 6

      looprev (i,n-1,0) {
          int k = i;
          sum = arr[k%n]+arr[(k+1)%(n)];
          if (is_prime[sum]) continue;

          if ((arr[k%n]&1) == 0) k=(i+1)%n; // arr[i] = 5
          j = 0, idx = 0, flag = false;

          while (j < n && (!flag)) {
              int sum1 = arr[idx%n] + arr[(k+1)%(n)], sum2 = arr[idx%n] + arr[(k-1+n)%(n)];
              int sum3 = arr[k%n] + arr[(idx+1)%(n)], sum4 = arr[k%n] + arr[(idx-1+n)%(n)];
              
              if (is_prime[sum1] && is_prime[sum2] && is_prime[sum3] && is_prime[sum4]) {
                  swap(arr[k%n],arr[idx%n]);
                  flag = true;
                  break;
              }

              idx = (idx + 2) % (n);
              j++;
          } 

          if (!flag) {
              cout << "-1\n"; return;
          }
      }

      for (int j = 0; j <n; j++) cout << arr[j] << " ";
      cout << "\n";
}

int main(int argc, char const *argv[]){
    _fast
    prime_sieve();
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}