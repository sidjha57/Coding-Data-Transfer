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
const int MAX = 6e5;
bitset<600000> U;

struct BinTrieNode {
    BinTrieNode *left, *right;
};

void insert ( BinTrieNode* head, ll n) {
    BinTrieNode *cur = head;
    for (int i=31; i>=0; i--) {
        int bit = (n >> i) & 1;
        if (bit == 0) {
            if (cur->left == NULL) {
                cur->left = new BinTrieNode();
            }
            cur = cur->left;
        } else {
            if (cur->right == NULL) {
                cur->right = new BinTrieNode();
            }
            cur = cur->right;
        }
    }
}

ll findMinXorPair (BinTrieNode* head, ll value) {
    ll cur_xor = 0;
    BinTrieNode* cur = head;
    for (int i =31; i>= 0; i--) {
        int bit = (value >> i) & 1;
        // we desire to have 0 which means left child should be there
        if (bit == 0) {
            if (cur->left != NULL) {
                cur = cur->left;
            } else {
                cur_xor += (1 << i);
                cur = cur->right;
            }
        } else {
            // we desire to have 1 which means right child should be there
            if (cur->right != NULL) 
                cur = cur->right;
               
             else { 
                cur_xor += (1 << i);
                cur = cur->left; 
             }
        }
    }
    return cur_xor;
}

void solve() {
    ll n,m,a,prev_query=0,cur_query=0,mex=0; cin >> n >> m; 
    BinTrieNode *head = new BinTrieNode();
    loop (i,0,n-1) {
        cin >> a;
        U[a] = true;
    }
    loop (i,0,MAX) {
        if (!U[i])
        insert(head,i);
    }

    while (m--) {
        cin >> cur_query;
        cur_query ^= prev_query;
        mex = findMinXorPair (head,cur_query);
        cout << mex << "\n";
       
        prev_query = cur_query;
    }
    
}

int main(int argc, char const *argv[]){
    _fast

     solve();
    
  return 0;
}