#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool f(double len, vector<ll>& a, ll k) {
    ll m = 0;
    for (int i=0; i<a.size(); i++) {
        m += (a[i]/len);
    }
    return m >= k;
}

int main () {
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    double l=1,r=1e7, ans=0;
    for (int i=0; i<100; i++) {
        double mid = (l+r)/2.0;
        if (f(mid,a,k)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << setprecision(10) << ans;
}