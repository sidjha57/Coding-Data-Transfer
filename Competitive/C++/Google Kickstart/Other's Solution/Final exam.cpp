#include <bits/stdc++.h>
using namespace std;

const long long INF = 2e18;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        cout << "Case #" << z << ": ";

        set<pair<long long, long long>> s;

        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            long long l, r;
            cin >> l >> r;
            s.insert({l, r});
        }   

        // return {-1, -1} if not found
        auto findIntervalContain = [&](long long x) {
            auto it = s.lower_bound({x, INF});

            if (it == s.begin()) {
                return pair<long long, long long>(-1, -1);
            }

            it--;
            auto p = *it;
            if (p.first <= x && x <= p.second) {
                return p;
            }
            return pair<long long, long long>(-1, -1);
        };

        auto remove = [&](long long x) {
            auto p = findIntervalContain(x);
            s.erase(s.lower_bound(p));

            if (p.first <= x - 1) {
                s.insert({p.first, x - 1});
            }
            if (x + 1 <= p.second) {
                s.insert({x + 1, p.second});
            }
        };

        auto print = [&]() {
            for (auto i: s) {
                cout << "[" << i.first << ", " << i.second << "] ";
            }
            cout << endl;
        };

        auto findIntervalLeft = [&](long long x) {
            auto it = s.lower_bound({x, INF});

            if (it == s.begin()) {
                return -1LL;
            }

            it--;
            auto p = *it;
            return p.second;
        };

        auto findIntervalRight = [&](long long x) {
            auto it = s.lower_bound({x, INF});

            if (it == s.end()) {
                return -1LL;
            }

            auto p = *it;
            return p.first;
        };

        for (int i = 1; i <= m; i++) {
            long long x;
            cin >> x;

            auto p = findIntervalContain(x);
            if (p.first == -1) {
                long long a = findIntervalLeft(x);
                long long b = findIntervalRight(x);
                long long res = 0;
                if (a == -1) {
                    res = b;
                }
                else if (b == -1) {
                    res = a;
                }
                else if (x - a <= b - x) {
                    res = a;
                }
                else res = b;

                remove(res);
                cout << res << " ";
            }
            else {
                cout << x << " ";
                remove(x);
            }
        }
        cout << "\n";
    }

    return 0;
}