#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        cout << "Case #" << z << ": ";

        int n;
        long long c;

        cin >> n >> c;

        set<long long> time;
        map<long long, long long> open;

        for (int i = 1; i <= n; i++) {
            long long l, r;
            cin >> l >> r;
            l++;
            time.insert(l);
            time.insert(r);
            open[l]++;
            open[r]--;
        }

        long long last = 0, cnt = 0, lastCnt = 0;
        vector<array<long long, 2>> data;

        for (auto t: time) {
            cnt += open[t];
            if (last) {
                data.push_back({lastCnt, t - last});
            }
            last = t;
            lastCnt = cnt;
        }

        sort(data.begin(), data.end(), greater<array<long long, 2>>());

        long long res = n;
        for (auto i: data) {
            long long toUse = min(c, i[1]);
            c -= toUse;
            res += toUse * i[0];
        }

        cout << res << "\n";
    }

    return 0;
}