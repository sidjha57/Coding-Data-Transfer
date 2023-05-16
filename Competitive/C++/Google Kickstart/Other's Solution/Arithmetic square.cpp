#include <bits/stdc++.h>
using namespace std;

bool check(int a, int b, int c) {
    return a + c == b * 2;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        cout << "Case #" << z << ": ";

        int a[3][3];
        cin >> a[0][0] >> a[0][1] >> a[0][2];
        cin >> a[1][0] >> a[1][2];
        cin >> a[2][0] >> a[2][1] >> a[2][2];

        int res = check(a[0][0], a[0][1], a[0][2]);
        res += check(a[2][0], a[2][1], a[2][2]);
        res += check(a[0][0], a[1][0], a[2][0]);
        res += check(a[0][2], a[1][2], a[2][2]);

        map<int, int> cnt;

        auto add = [&](int x, int y) {
            int s = x + y;
            if (s % 2) return;
            cnt[s / 2]++;
        };

        add(a[0][0], a[2][2]);
        add(a[0][2], a[2][0]);
        add(a[1][0], a[1][2]);
        add(a[0][1], a[2][1]);

        int maxVal = 0;
        for (auto i: cnt) {
            maxVal = max(maxVal, i.second);
        }

        cout << res + maxVal << "\n";
    }


    return 0;
}