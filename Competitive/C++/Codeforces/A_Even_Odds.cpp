#include <iostream>
#define ll long long int
using namespace std;

void solve () {
 ll n,k;
   //cout << sizeof(ll);
   cin >> n >> k;
   if (n&1) {
       if (k > n/2 + 1) {
           k = k - n/2 -1;
           cout << 2*k;
       }
       else {
           cout << 2*k-1;
       }  
   }
   else {
       if (k > n/2) {
           k = k - n/2;
           cout << 2*k;
       }
       else cout << 2*k-1;
   }
}

int main () {
  ll t = 1;
  while (t--) {
      solve();
  }
}