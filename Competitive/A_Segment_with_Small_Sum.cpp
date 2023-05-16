#include <bits/stdc++.h>

using namespace std;


int main () {
    long long n, target; cin >> n >> target;

    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    long long sum = 0, ans = 0, l = 0, r = 0;
    for (r=0; r<n; r++) {
        sum += a[r];
        while (sum > target) {
            sum -= a[l];
            l++;
        }

        ans += (r-l+1);
    }

    cout << ans;

}