#include <bits/stdc++.h>
#define ll long long
#define PI 3.14159265359
using namespace std;

double f(double H, double R) {
    double ans = PI*H*H*(3*R - H)/3.0;

    return ans; 
}

int main () {
  double R,V; cin >> R >> V;
  double l=0,r=3*R, ans;
  for (int i=0; i<200; i++) {
    double mid = (r+l)/2.0;
    if (abs(f(mid, R) - V) <= 0.0000001) {
      ans = mid;
      break;
    } else if (f(mid,R) > V) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << setprecision(7) << ans;
}