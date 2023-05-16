#include <bits/stdc++.h>
#define FOR for (int i = 0; i < n; i++)
#define IO                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;
typedef long double dol;
typedef vector<vector<dol>> vvdol;

dol polyArea(vvdol &arr, int &n)
{
    dol sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += arr[i][0] * arr[(i + 1) % n][1];
        sum2 += arr[i][1] * arr[(i + 1) % n][0];
    }
    return 0.5 * abs(sum1 - sum2);
}

dol dist(vector<dol> &p1, vector<dol> &p2)
{
    return sqrt(pow(p2[0] - p1[0], 2) + pow(p2[1] - p1[1], 2));
}

dol sideSum(vvdol &arr, int &n)
{
    dol ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += dist(arr[i], arr[(i + 1) % n]);
    }
    return ret;
}

dol HalfAngleRecSum(vvdol &arr, int &n)
{
    dol ret = 0;
    for (int i = 0; i < n; i++)
    {
        vector<dol> pP(2), cP(2), nP(2);
        int j;
        if (i == 0)
            j = n - 1;
        else
            j = i - 1;
        pP[0] = arr[j][0], pP[1] = arr[j][1];
        cP[0] = arr[i][0], cP[1] = arr[i][1];
        nP[0] = arr[(i + 1) % n][0], nP[1] = arr[(i + 1) % n][1];
        dol m2 = (pP[1] - cP[1]) / (pP[0] - cP[0]);
        dol m1 = (nP[1] - cP[1]) / (nP[0] - cP[0]);
        if (m1 == INFINITY and m2 == 0) {
            ret += 1;
            continue;
        } else if (m2 == INFINITY and m1 == 0) {
            ret += 1;
            continue;
        }
        else if((m1 == INFINITY or m1 == -INFINITY) and m2 != 0) m1 = 0;
        else if((m2 == INFINITY or m2 == -INFINITY) and m1 != 0) m2 = 0;
        dol a = abs((m2-m1)/(1+m1*m2));
        dol r1 = (-2 + sqrt(4 + 4 * a * a)) / (2 * a);
        dol r2 = (-2 - sqrt(4 + 4 * a * a)) / (2 * a);
        if (atan(r1) > 0)
            ret += (1 / r1);
        else
            ret += (1 / r2);
    }
    return ret;
}

int main()
{
    // IO
    int t, n, q;
    dol v, time;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        vvdol arr(n, vector<dol>(2));
        FOR cin >> arr[i][0] >> arr[i][1];
        dol initArea = polyArea(arr, n), sideTot = sideSum(arr, n), angSum = HalfAngleRecSum(arr, n);
        while (q--)
        {
            cin >> v >> time;
            dol ans = initArea + sideTot * v * time + v * v * time * time * angSum;
            cout << fixed << setprecision(7) << ans << "\n";
        }
    }
    return 0;
}