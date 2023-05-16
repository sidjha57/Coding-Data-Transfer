#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0);

const int MAXN = 5e5 + 5;

vector<vector<ll>> factors(MAXN);

void precompute () {
	ll i,j;
	for (i = 1; i < MAXN; i++) {
		for (j=i;j< MAXN; j+=i) {
			factors[j].emplace_back(i);
		}
	}
}
int main() {
    _cin
	int n,m,t; cin >> t;
	precompute();
	while (t--) {
		cin >> n >> m;
		ll count=0;
            for (ll b=2; b <= n ; b++) {
				int x = m - (m%b);
				if (x > 0) 
                count += lower_bound(factors[x].begin(),factors[x].end(),b)-factors[x].begin();
				else 
				count += b-1;
            }
        
		cout << count << "\n";
	}
	
	return 0;
}