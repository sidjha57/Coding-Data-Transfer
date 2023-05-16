#include <bits/stdc++.h>

using namespace std;

int main () {
    
    vector<long long> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    map<long long, long long> mp;
    long long l=0, r=0, ans = 0;
    for (; r<n; r++) {
        mp[a[r]]++;
        while (mp[a[r]] > 1) {
            mp[a[l]]--;
            if (mp[a[l]] == 0) mp.erase(a[l]);
            l++;
        }
        ans += (r-l+1);
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