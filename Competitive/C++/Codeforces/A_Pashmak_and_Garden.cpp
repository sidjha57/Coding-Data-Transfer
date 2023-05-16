#include <bits/stdc++.h>
using namespace std;
int abs(int x)
{
    return (x > 0 ? x : -x);
}

int solve(vector<vector<int>>& intervals) {
    int n= intervals.size(), start[n],end[n];
    for (int i = 0; i < n;i++) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }
    sort (start,start+n);
    sort (end,end+n);
    int dif=end[0]-start[0];
    for (int i=1; i<n;i++) {
        if (start[i] < end[i-1]) {
            if (end[i] > end[i-1]) 
                dif += end[i] - end[i-1];
        } else {
            dif += end[i]- start[i];
        }
    }
    return dif;
}
 
int main()
{
    ios::sync_with_stdio(false);
    int x1, y1, x2, y2;
    // cin >> x1 >> y1 >> x2 >> y2;
    // if (x1 != x2 && y1 != y2 && abs(x1 - x2) != abs(y1 - y2))
    //     cout << -1 << endl;
    // else if (x1 == x2)
    //     cout << x1 + abs(y1 - y2) << " " << y1 << " " << x2 + abs(y1 - y2) << " " << y2 << endl;
    // else if (y1 == y2)
    //     cout << x1 << " " << y1 + abs(x1 - x2) << " " << x2 << " " << y2 + abs(x1 - x2) << endl;
    // else
    //     cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
    // return 0;
    vector<vector<int>> a = {{45,60},{1,5},{5,15},{2,3}};
    cout << solve(a);
}

 
