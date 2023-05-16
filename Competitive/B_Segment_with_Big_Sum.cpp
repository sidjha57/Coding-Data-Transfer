#include <bits/stdc++.h>

using namespace std;


int main () {
    long long n, s; cin >> n >> s;

    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    long long l=0, r=0, x=0, ans=INT64_MAX;
    for (r=0; r<n; r++) {
        x += a[r];
        while ((x - a[l]) >= s) {
            x -= a[l];
            l++;
        }
        if (x >= s) {
            ans = min(ans,(r-l+1));
        }
    }
    if (ans == INT64_MAX) cout << -1;
    else    cout << ans;
}