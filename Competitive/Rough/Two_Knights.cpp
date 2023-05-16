#include <bits/stdc++.h>
using namespace std;

int main() {
 int n,ans; cin >> n;
    for (int i=1; i<=n; i++) {
        ans = (i-1)*(i+4)*(i*i-3*i+4)/2;
        cout << ans << "\n";
    }
}