#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool isElementPresent (vector<ll>& a, ll target) {
    ll n=a.size(), l = 0, r = n-1;
    while (r >= l) {
        ll mid = (r+l)/2;
        if (a[mid] == target) {
            return true;
        } else if (a[mid] > target) {
            r = mid - 1;
        } else if (a[mid] < target) {
            l = mid + 1;
        }
    }
    return false;
}

int main () {
    ll n,k,q; cin >> n >> k;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=0; i<k; i++) {
        cin >> q;
        if (isElementPresent(a,q)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}