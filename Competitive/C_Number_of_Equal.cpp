#include <bits/stdc++.h>

using namespace std;

int main () {
    long long n,m,l=0,r=0,ans=0,cnt1=0,cnt2=0;
    cin >> n >> m;
    vector<long long> a(n),b(m);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int j=0; j<m; j++) cin >> b[j];

    while (l < n && r < m) {
        while (a[l] == b[r]) {
           if (l+1 < n && a[l+1] == b[r]) {
            l++,cnt1++;
           } else if (r+1 < m && a[l] == b[r+1]) {
            r++,cnt2++;
           } else {
             break;
           }
        }

        ans += cnt1*cnt2;

        if (a[l+1] == b[r+1]) {
            l++,r++, cnt1 = 1, cnt2 = 1;
        } else {
            l++,r++;
        }

    }

    cout << ans;
}