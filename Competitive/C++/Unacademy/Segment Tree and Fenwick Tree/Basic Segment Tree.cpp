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

class info {
public:
	int sum;
	info()
	{
		sum = 0;
	}
	info(int val)
	{
		sum = val;
	}
};

class segTree {
	vector<info> tree; // 1-based
	int n;
	vi arr;

	info merge(info left, info right)
	{
		return info(left.sum + right.sum);
	}

	void build(int cur, int l, int r)
	{
		if (l == r)
		{
			tree[cur] = info(arr[l]);
			return;
		}

		int mid = l + r >> 1; // (l+r)/2
		build(2 * cur, l, mid); // left child
		build(2 * cur + 1, mid + 1, r); // right child
		tree[cur] = merge(tree[2 * cur], tree[2 * cur + 1]); // parent will be left child + right child
	}

	info query(int cur, int tl, int tr, int ql, int qr)
	{
		// No overlap
		if (qr < tl or ql > tr)
			return info();

		// Complete overlap
		if (tl >= ql and tr <= qr)
			return tree[cur];

		int mid = tl + tr >> 1; // (tl+tr)/2

		return merge(query(2 * cur, tl, mid, ql, qr), query(2 * cur + 1, mid + 1, tr, ql, qr));
	}

	void update(int cur, int l, int r, int pos, int val)
	{
		if (l == r)
		{
			tree[cur] = info(val);
			return;
		}

		int mid = l + r >> 1;

		if (pos <= mid)
			update(2 * cur, l, mid, pos, val);
		else
			update(2 * cur + 1, mid + 1, r, pos, val);

		tree[cur] = merge(tree[2 * cur], tree[2 * cur + 1]);
	}

public:
	segTree(vi a, int nval) // arr is 1-based
	{
		n = nval;
		tree.resize(4 * n + 1);
		arr = a;
		build(1, 1, n); // O(n) -> ~4*n
	}

	info query(int l, int r) // O(logn) -> ~4*log2(n)
	{
		return query(1, 1, n, l, r);
	}

	void update(int pos, int val) // O(logn) -> ~log2(n)
	{
		update(1, 1, n, pos, val);
	}
};

int32_t main()
{
	FIO;
	int n, q; cin >> n >> q;

	vi arr(n + 1);

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	segTree st(arr, n);

	while (q--)
	{
		int tp, a, b; cin >> tp >> a >> b;

		if (tp == 1)
			st.update(a, b);

		else
			cout << st.query(a, b).sum << '\n';
	}

	return 0;
}