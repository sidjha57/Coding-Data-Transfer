#include <bits/stdc++.h>

using namespace std;

int main () {

    long long n,m; cin >> n >> m;
    vector<long long> a(n),b(m), ans(m);

    for (int i=0; i<n; i++) cin >> a[i];
    for (int j=0; j<m; j++) cin >> b[j];

    long long i=0,j=0,k=0;
    while (i < n || j < m) {
        if (i < n && a[i] < b[j]) {
            i++;
        } else {
            ans[k] = i; // we have already visited these elements which are less than b[j]
            j++, k++;
        }
    }

    for (int i=0; i<m; i++) cout << ans[i] << " ";

    return 0;
}