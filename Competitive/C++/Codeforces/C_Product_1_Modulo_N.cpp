#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rf(i, a, b) for (ll i = a; i >= b; i--)
typedef std::vector<long long> vi;
#define F first
#define S second
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mod 1000000007
#define PB push_back
#define MP make_pair
#define PI 3.14159265358979323846
#define all(a) a.begin(), a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
const ll INF = LLONG_MAX / 2;
const ll N = 2e5 + 1;
using namespace std;
ll pow1(ll n, ll p)
{
    if (p == 0)
        return 1;
    ll x = pow1(n, p / 2);
    x = (x * x) % mod;
    if (p % 2 == 0)
        return x;
    else
        return (x * n) % mod;
}
ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
 
    if (m == 1)
        return 0;
 
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
 
    return x;
}
void solve()
{
    ll n=10000000, i, j = 0, p = 0, k;
    
    set<ll> s;
    vi v;
    v.PB(1);
    map<ll, ll> mp;
    fr(i, 2, n)
    {
        if (__gcd(n, i) == 1)
        {
            v.PB(i);
            mp[i]++;
        }
    }
    ll nn = v.size();
    ll premod = 1;
    for (ll i = 1; i < nn; i++)
    {
        premod = (premod * v[i]) % n;
    }
    if (mp.find(premod) != mp.end())
    {
        sort(v.begin(), v.end());
        cout << v.size() - 1 << "\n";
        fr(i, 0, v.size())
        {
            if (v[i] == premod)
                continue;
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        sort(v.begin(), v.end());
        cout << v.size() << "\n";
        fr(i, 0, v.size())
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
}
 
int main()
{
    fast;
    ll t = 1;
    // std::cin >> t;
    while (t--)
    {
        solve();
    }
}
