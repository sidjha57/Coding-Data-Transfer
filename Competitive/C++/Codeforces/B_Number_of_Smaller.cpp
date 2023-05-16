#include <bits/stdc++.h>
#define ll long long
#define inf 1000000005
using namespace std;

int main () {
    int n,m;
    cin >> n >> m;
    ll a[n+1],b[m+1],c[m];
    a[n] = inf, b[m] = inf;

    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) cin >> b[i];
    
    int j=0;
    for (int i=0;i<m;i++) {
        while (a[j] < b[i]) {
            j++;
        }
         c[i] = j;
    } 

    for (int i=0;i<m;i++) cout << c[i] <<" ";
}