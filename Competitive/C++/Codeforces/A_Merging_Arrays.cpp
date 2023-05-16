#include <bits/stdc++.h>
#define ll long long
#define inf 1000000005
using namespace std;

int main () {
    int n,m;
    cin >> n >> m;
    ll a[n+1],b[m+1],c[n+m];
    a[n] = inf, b[m] = inf;

    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) cin >> b[i];
    
    int i=0,j=0,k=0;
    while (i < n || j < m) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            k++,i++;
        }
        else  {
            c[k] = b[j];
            k++,j++;
        }
    }

    for (int i=0;i<(n+m);i++) cout << c[i] <<" ";
}