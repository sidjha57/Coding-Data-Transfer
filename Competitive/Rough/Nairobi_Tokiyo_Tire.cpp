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
struct Node {
    Node *Bits[2];
    int count,collect;
    Node () { 
        Bits[0] = 0, Bits[1] = 0;
        count =0,collect = 0;
    }
};
void insert (Node *root, int value) {
    Node *cur = root;
    for (int i=31; i >= 0; i--) {
        int bit = (value >> i) & 1;
        if (!cur->Bits[bit]) 
            cur->Bits[bit] = new Node();
        cur = cur->Bits[bit];
        cur->count++;
    }
}

int max_xor (Node* root, int x) {
    Node* cur = root;
    int maxi = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (x >> i)&1;
        if (bit == 0) {
            if (cur->Bits[1] != NULL && cur->Bits[1]->count != cur->Bits[1]->collect ) {
                maxi += (1 << i);
                cur = cur->Bits[1];
                cur->collect++;
            } else if (cur->Bits[0] != NULL && cur->Bits[0]->count != cur->Bits[0]->collect) {
                cur = cur->Bits[0];
                cur->collect++;
            } 
        } else {
            if (cur->Bits[0] != NULL && cur->Bits[0]->count != cur->Bits[0]->collect) {
                 maxi += (1 << i);
                cur = cur->Bits[0]; 
                cur->collect++;
            } else if (cur->Bits[1] != NULL && cur->Bits[1]->count != cur->Bits[1]->collect ) {
                cur = cur->Bits[1];
                cur->collect++;
             } 
        }
    }
    return maxi;
}
void solve() {
    int n; cin >> n;
    Node *root = new Node();
    int arr[n]; loop (i,0,n-1) cin>> arr[i];
    sort(arr,arr+n);
    int max_xor_nairobi= arr[n-1], max_xor_tokyo = arr[n-2];
    if (n > 2) {
        loop (i,0,n-3) {
            insert(root,arr[i]);
        }
        bool f = true;
        loop (i,0,n-3) {
            if (f) {
                max_xor_nairobi = max_xor (root,max_xor_nairobi);
                f = false;
            } else {
                max_xor_tokyo = max_xor (root,max_xor_tokyo);
                f = true;
            }
        }
    }
    //log (max_xor_tokyo);log(max_xor_nairobi);

    if (max_xor_nairobi > max_xor_tokyo) cout <<"1\n";
    else if (max_xor_nairobi < max_xor_tokyo) cout <<"0\n";
    else cout <<"-1\n";
}

int main(int argc, char const *argv[]){
    _fast
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}