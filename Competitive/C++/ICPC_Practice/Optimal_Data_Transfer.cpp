#include<bits/stdc++.h>
using namespace std;

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


struct trie{
	struct trie *child[2];
	bool isend;
 
	trie()
	{
		memset(child,0,sizeof(child));
		isend=false;
	}
 
};

void insert(trie* root,string& str)
{
	struct trie *cur=root;
	for(char ch:str)
	{
		int idx=ch-'0';
		if(cur->child[idx]==NULL)
		{
			cur->child[idx]=new trie;
		}
		cur=cur->child[idx];
	}
	cur->isend=true;
    delete cur;
}
 
int search(trie* root,string& str)
{
    int cnt=0;
	struct trie *cur=root;
	for(char ch:str)
	{
		int idx=ch-'0';
		if(cur->child[idx]==NULL)
			return cnt;
		cur=cur->child[idx];
        cnt++;
	}
	return cnt;
    delete cur;
}

void solve () {
    ll n,m,cost,x; cin >> n >> m;
     struct trie* root = new trie;
    cost = m;
    string s; 
    cin >> s;
    insert(root,s);
    loop (i,1,n-1) {
        cin >> s;
        x = search(root,s);
        cost += (m - x);
        if (m != x)
        insert(root,s);
    }
    cout << cost << "\n";
    delete root;
}
int main()
{  
   ll t; cin >> t;
  while(t--)
   solve();
  return 0;
}