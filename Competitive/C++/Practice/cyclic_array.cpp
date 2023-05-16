#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector<int> sort_cyclic_shifts(string const &s, vector<int> &c)
{
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[p[i]] != s[p[i - 1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h)
    {
        for (int i = 0; i < n; i++)
        {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++)
        {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

ll solve(int n, ll k, string s)
{
    vector<int> c(n);
    vector<int> p = sort_cyclic_shifts(s, c);
    int count = 1, prevClass = c[p[n-1]];
    for (int i = n-2; i >= 0; i--)
    {
    	if(c[p[i]] == prevClass)
    		count++;
    	else
    		break;
    }
    if(count == 1)
        return (ll)(p[n - 1] + n * (k - 1));
    else
    {
    	vector<int> cp;
    	int push = 0, idx = n-1;
    	while(push < count)
    	{
    		cp.push_back(p[idx]);
    		push++;
    		idx--;
    	}
    	sort(cp.begin(), cp.end());
    	ll ans = cp[0];
    	if(k == 1)
    		return ans;
    	int sz = (int)cp.size(), sum = 2;
    	vector<int> ab;
    	for (int i = 1; i < sz; i++)
    	{
    		ab.push_back(abs(cp[i] - cp[i-1]));
    		sum += abs(cp[i] - cp[i-1]);
    	}
    	ans += ((k-1)/sz)*sum;
    	int x = (k-1)%sz;
    	for (int i = 0; i < x; i++)
    		ans += ab[i];
    	return ans;
    }
}

int main()
{
    int t, n;
    ll k;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        getchar();
        cin >> s;
        cout << solve(n, k, s) << "\n";
    }
    return 0;
}