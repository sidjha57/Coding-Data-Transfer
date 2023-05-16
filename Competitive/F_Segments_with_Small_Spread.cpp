#include <bits/stdc++.h>

using namespace std;
long long check (map<long long, long long>& mp) {
    long long mn = (*mp.begin()).first; 
    long long mx = (*mp.rbegin()).first;
    
    return (mx - mn);
}

int main () {
    long long n,k; cin >> n >> k;
    vector<long long> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    map<long long, long long> mp;
    long long l=0, r=0, ans = 0;
    for (; r<n; r++) {
        mp[a[r]]++;
        while (check(mp) > k) {
            mp[a[l]]--;
            if (mp[a[l]] == 0) mp.erase(a[l]);
            l++;
        }
        ans += (r-l+1);
    }
    cout << ans << "\n";
}

/*
  2 -> 1
  6,4 -> 2
  6,4,3 -> 3
  6,4,3,6 -> 4
  6,8 -> 2
  6,8,9 -> 3
*/