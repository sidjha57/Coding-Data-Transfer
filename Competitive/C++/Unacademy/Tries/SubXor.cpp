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


struct BinaryTrieNode {
    BinaryTrieNode* next[2];
    int count;
    BinaryTrieNode () {
        next[0] = next [1] = NULL;
        count = 0;
    }
};

void insert (BinaryTrieNode* root, int num) {
    BinaryTrieNode *cur = root;
    for (int i=31; i >=0; i--) {
        int bit = (num >> i) & 1;
        if (!cur->next[bit]) {
            cur->next[bit] = new BinaryTrieNode();
        }
        cur = cur->next[bit];
        cur->count++;
    }
}
int query (BinaryTrieNode* root, int pre , int k) {
    BinaryTrieNode* cur = root;
    int result = 0;
    for (int i = 31; i >=0; i--) {
        if (cur == NULL) break;
        int p = (pre >> i) & 1;
        int q = (k >> i) & 1;
        if (p == q) {
            if (q == 1)
                result += ((cur->next[1] != NULL) ? cur->next[1]->count: 0);
            cur = cur->next[0]; // go left        
        } else {
            if (q == 1)
                result += ((cur->next[0] != NULL) ? cur->next[0]->count: 0);
            cur = cur->next[1]; // go right
        }
    }
    return result;
}
void solve() {
    BinaryTrieNode *root = new BinaryTrieNode();
    int n,k,pre=0,ans=0; cin >> n >> k;
    
    while (n--) {
        int num; cin >> num;
        pre = pre^num;
        ans += query(root,pre,k);
        insert(root,pre);
    }
    cout << ans << "\n";
}

int main(int argc, char const *argv[]){
    _fast
    int t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}