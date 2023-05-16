#include <bits/stdc++.h>
 
using namespace std;
 
 
int main () {
    long long n, target; cin >> n >> target;
 
    vector<long long> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    // for (auto &x : a) cin >> x;
 
    long long sum = 0, ans = 0, l = 0, r = 0;
    for (r=0; r<n; r++) {
        sum += a[r];
        while (sum > target) {
            sum -= a[l];
            l++;
        }

        long long len = (r-l+1); 
        ans += (len*(len+1))/2;
    }
 
    cout << ans;
 
}

