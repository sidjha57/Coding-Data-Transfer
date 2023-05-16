#include<bits/stdc++.h>

using namespace std;


int closest_left (vector<int>& a, int x) {
  int l=-1,r=a.size();
  while (r > l+1) {
    int m = (r+l)/2;
    if (a[m] <= x) {
      l = m;
    } else {
      r = m;
    }
  }
  return l+1;
}

int main () {
  int n,k; cin >> n >> k;

  vector<int> a(n);
  for (int i=0; i<n; i++) cin >> a[i];


// klog(n) => 10^6 ~ 10^7
  while (k--) {  // k
    int x; cin >> x;
    cout << closest_left(a,x) << "\n"; // log(n)
  }
}