#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main () {
    ll i,j,k;
    ll n,q,c,t;
    cin >> n >> q >> c;
    ll sky[11][101][101];
    memset(sky, 0, sizeof(sky));
    for (i=0;i<n;i++) {
       ll x,y,s;
       cin >> x >> y >> s;
      for (int time=0;time<=c;time++) {
       sky[time][x][y] += s;
       s = (s+1)%(c+1);//s++ if(s>c) s=0
      }
    }

    for (int time=0;time<=c;time++) {
        for (int i=1;i<=100;i++) {
            for (int j=1;j<=100;j++) {
                sky[time][i][j] += sky[time][i-1][j] + sky[time][i][j-1] - sky[time][i-1][j-1];//2d prefix sum
            }
        }
    }
 

   while(q--) {
        ll t,x1,y1,x2,y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t%=(c+1);
        ll bright = sky[t][x2][y2] - sky[t][x1-1][y2] - sky[t][x2][y1-1] + sky[t][x1-1][y1-1];
        cout << bright << "\n";
    }

}