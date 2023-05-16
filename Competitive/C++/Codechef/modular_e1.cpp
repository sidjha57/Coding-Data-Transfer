#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0);
using namespace std;

int main() {
    _cin
    ll t,n,m,a,b,x,count;
    cin>>t;
    while (t--) {
        cin>>n>>m;
        count = 0;
        vl mod(n+1,1);
        for (a=2;a<=n;a++) {
            x = m%a;
            count += mod[x];
            for (b=x;b<=n;b+=a) {
                mod[b]++;
            }
        }
        cout << count << "\n";
    }
}