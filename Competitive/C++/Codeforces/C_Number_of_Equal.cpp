#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n,m,k;
    cin >> n >> m;
    ll a[n],b[m],sum=0;
  
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) cin >> b[i];

   
      
    int j=0;
    for (int i=0;i<m;i++) {
        while (a[j] < b[i]) {
            j++;
        }
         //c[i] = j;
    }
      
     
    cout << sum <<"\n" ;
}