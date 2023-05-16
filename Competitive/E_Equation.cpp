#include <bits/stdc++.h>

using namespace std;

double f (double x) {
  return x*x + sqrt(x);
}

int main () {
  double c; cin >> c;
  double l = 1, r = 1e10, ans;

  for (int i=1; i<100; i++) {
    double mid = (l+r)/2.0;

    if (abs(f(mid) - c) <= 0.000001) {
      ans = mid;
      break;
    } else if (f(mid) > c) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << fixed << setprecision(6) << ans;
}