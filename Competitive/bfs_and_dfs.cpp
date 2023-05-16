#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi adj[1001];
int n, m;

void bfs_util(int src, vector<bool> &vis)
{
	queue<int> q;

	q.push(src);
	vis[src] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		cout << cur << ' ';
		q.pop();

		for (int nb : adj[cur])
			if (!vis[nb])
				q.push(nb), vis[nb] = 1;
	}
}

vi bfs_dist(int src)
{
	queue<int> q;
	vector<bool> vis(n + 1);
	vi d(n + 1, -1);
	vi par(n + 1, -1);

	q.push(src);
	vis[src] = 1;
	d[src] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		cout << cur << ' ';
		q.pop();

		for (int nb : adj[cur])
			if (!vis[nb])
			{
				q.push(nb);
				vis[nb] = 1;
				d[nb] = d[cur] + 1;
				par[nb] = cur;
			}
	}
	return d;
}

void bfs()
{
	vector<bool> vis(n + 1);

	for (int i = 1; i <= n; ++i)
		if (!vis[i])
		{
			bfs_util(i, vis);
			cout << '\n';
		}
}

void dfs_util(int i, vector<bool> &vis)
{
	if (vis[i])
		return;

	cout << i << ' ';
	vis[i] = 1;
	for (int nb : adj[i])
		dfs_util(nb, vis);
}

void dfs()
{
	vector<bool> vis(n + 1);

	for (int i = 1; i <= n; ++i)
		if (!vis[i])
		{
			dfs_util(i, vis);
			cout << '\n';
		}
}

bool detect_cycle_dfs_util(int i, int par, vector<bool> &vis)
{
	cout << i << ' ';
	vis[i] = 1;
	for (int nb : adj[i])
	{
		if (nb == par)
			continue;

		if (vis[nb])
		{
			// from = nb, to = i;
			return 1;
		}

		bool cyc = detect_cycle_dfs_util(nb, i, vis);
		if (cyc)
			return 1;
	}
	return 0;
}

bool detect_cycle_dfs()
{
	vector<bool> vis(n + 1);

	for (int i = 1; i <= n; ++i)
		if (!vis[i])
		{
			bool found = detect_cycle_dfs_util(i, -1, vis);

			if (found)
				return 1;
			cout << '\n';
		}

	return 0;
}

int32_t main()
{
	FIO;
	cin >> n >> m;

	while (m--)
	{
		int i, j; cin >> i >> j;
		adj[i].pb(j);
		adj[j].pb(i);
	}

	detect_cycle_dfs();
	return 0;
}