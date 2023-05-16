#include <bits/stdc++.h>

using namespace std;

int main () {
    
    int n,s; cin >> n >> s;
    vector<long long> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    
    long long l=0, r=0, ans = 0, sum = 0;
    for (; r<n; r++) {
        while (sum < s) {
           sum += a[r++];
        }
        if (sum >= s)
            ans += (r-l+1);
        while (sum > s) {
            sum -= a[l++];
            if (sum >= s)
                ans += (r-l+1);
        }
    }

    cout << ans << "\n";
}

/*
    2 6 4 3 6 8 3
    2 -> 1
    2,6 -> 2
    2,6,4 -> 3
    6,4,3 -> 3
    6,4,3,6 -> 4
    3,6,8 -> 3
    3,6,8,3 -> 4
*/