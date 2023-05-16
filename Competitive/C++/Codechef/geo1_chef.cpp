#include <bits/stdc++.h>
#define FOR for (int i = 0; i < n; i++)
#define IO                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;
typedef long double dol;
typedef vector<vector<dol>> vvdol;
dol initArea, sideTot, angSum ;
dol arr[10005][2];
long long n;

void Area(){
    dol sum1 = 0, sum2 = 0; 
    sideTot = 0;
    for (int i = 0; i < n; i++) {
        sum1 += arr[i][0] * arr[(i + 1) % n][1];
        sum2 += arr[i][1] * arr[(i + 1) % n][0];
        sideTot += sqrt(abs(arr[(i + 1) % n][0] - arr[i][0])*abs(arr[(i + 1) % n][0] - arr[i][0]) + abs(arr[(i + 1) % n][1] - arr[i][1])*abs(arr[(i + 1) % n][1] - arr[i][1]));
           dol pP[2], cP[2], nP[2];
        int j;
        if (i == 0)
            j = n - 1;
        else
            j = i - 1;
        pP[0] = arr[j][0], pP[1] = arr[j][1];
        cP[0] = arr[i][0], cP[1] = arr[i][1];
        nP[0] = arr[(i + 1) % n][0], nP[1] = arr[(i + 1) % n][1];
        dol aa = (pP[0] - cP[0]),b=(nP[0] - cP[0]),m1,m2;

        if ( aa!= 0)
            m2 = (pP[1] - cP[1]) / aa;
        if (b!=0)
            m1 = (nP[1] - cP[1]) / b;
        if (aa == 0 and m1 == 0) {
            angSum += 1;
            continue;
        }  else if ( b == 0 and m2 == 0) {
            angSum += 1;
            continue;
        } 
        else if((aa == 0) and m1 != 0) m2 = 0;
        else if((b == 0) and m2 != 0) m1 = 0;
        dol a = abs((m2-m1)/(1+m1*m2));
        if (a == 0) continue;
        dol r1 = (-2 + sqrt(4 + 4 * a * a)) / (2 * a);
        dol r2 = (-2 - sqrt(4 + 4 * a * a)) / (2 * a);
        if (atan(r1) > 0)
            angSum += (1 / r1);
        else
            angSum += (1 / r2);
    }
    initArea = 0.5 * abs(sum1 - sum2);
}

int main()
{
    // IO
    int t, n, q;
    dol v, ti;
    cin >> t;
    while (t--) {
        sideTot = 0,initArea=0,angSum=0;
        cin >> n >> q;
        memset(arr,0,sizeof(arr));
        FOR cin >> arr[i][0] >> arr[i][1];
        Area();
        while (q--) {
            cin >> v >> ti;
            dol ans = initArea + sideTot * v * ti + v * v * ti * ti * angSum;
            cout << fixed << setprecision(12) << ans << "\n";
        }
    }
    return 0;
}