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
class union_find
{

public:
	int *pr;
	int *sz;
	int cmp;

	union_find(int n)
	{
		pr = new int[n + 1];
		sz = new int[n + 1];

		for (int i = 1; i <= n; ++i)
			pr[i] = i, sz[i] = 1;

		cmp = n;
	}

	int root(int i)
	{
		if (pr[i] == i)
			return i;

		return pr[i] = root(pr[pr[i]]);
	}

	int find(int i, int j)
	{
		return (root(i) == root(j));
	}

	int un(int i, int j)
	{
		int u = root(i);
		int v = root(j);

		if (u == v)
			return 0;

		if (sz[u] < sz[v])
			swap(u, v);

		pr[v] = u;
		sz[u] += sz[v];
		cmp--;
		return 1;
	}
    int siz (int i) {
        return sz[root(i)];
    }
};

void solve() {
    int n, pairs; cin >> n >> pairs;
    union_find dsu(n + 1);
	for (int i = 0; i < pairs; ++i) {
		int u, v; cin >> u >> v;
		dsu.un(u,v);
	}
    int q; cin >> q;
  
    loop (i,0,q-1) {
        int a,b; cin >> a >> b;
        if (a == b) cout << "0\n";
        else if (dsu.find(a,b)) {
            if (dsu.siz(a)&1) cout << b << "\n";
            else cout << a << "\n";
        }
        else {
            if (dsu.siz(a) == dsu.siz(b)) cout << "0\n";
            else if (dsu.siz(a) > dsu.siz(b)) cout << a << "\n";
            else cout << b << "\n";
        }
    }

}

int main(int argc, char const *argv[]){
    _fast
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}