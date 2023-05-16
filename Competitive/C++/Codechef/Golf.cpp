#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll t,n,x,k;
	cin >> t;
	while(t--) {
	    cin >> n>>x>>k;
	    if (x%k == 0) cout << "yes\n";
	    else {
	        ll a = k*ceil((n+1)/k) - n-1;
	        if (x%k == abs(a)) cout << "yes\n";
	        else cout << "no\n";
	    }
	}
	return 0;
}
