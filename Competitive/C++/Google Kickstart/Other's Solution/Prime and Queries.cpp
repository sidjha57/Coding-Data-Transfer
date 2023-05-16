#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> fen;
    BIT(int n): n(n) {
        fen.resize(n + 1);
    }
    void update(int a, long long val) {
        for (int i = a; i <= n; i += i & -i) {
            fen[i] += val;
        }
    }

    long long getSum(int a) {
        long long res = 0;
        for (int i = a; i; i -= i & -i) {
            res += fen[i];
        }
        return res;
    }
};

long long p;

long long vp(long long n) {
    if (n == 0) {
        return 0;
    }

    long long res = 0;
    while (n % p == 0) {
        n /= p;
        res++;
    }
    return res;
}

// vp(a^s - b^s) - vp(s), where a, b not divisible by p
long long lte(long long a, long long b) {
    return vp(a - b);
}

// p = 2 and s is odd
long long lte2(long long a, long long b) {
    return vp(a - b) + vp(a + b) - 1;
}


BIT divBit(1), unDivBit(1), unDivCntBit(1), unDivBit2(1);

void add(int pos, long long val) {
    if (val < p) return;
    if (val % p == 0) {
        divBit.update(pos, vp(val));
    }
    else {
        unDivBit.update(pos, lte(val, val % p));
        unDivCntBit.update(pos, 1);
        unDivBit2.update(pos, lte2(val, val % p));
    }
}

void remove(int pos, long long val) {
    if (val < p) return;
    if (val % p == 0) {
        divBit.update(pos, -vp(val));
    }
    else {
        unDivBit.update(pos, -lte(val, val % p));
        unDivCntBit.update(pos, -1);
        unDivBit2.update(pos, -lte2(val, val % p));
    }   
}

// v[1] + ... + v[pos]
long long query(int pos, long long s) {
    if (p > 2 || s % 2) {
        return s * divBit.getSum(pos) + vp(s) * unDivCntBit.getSum(pos) + unDivBit.getSum(pos);
    }
    return s * divBit.getSum(pos) + vp(s) * unDivCntBit.getSum(pos) + unDivBit2.getSum(pos);
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        cout << "Case #" << z << ": ";

        int n, q;
        cin >> n >> q >> p;

        divBit = BIT(n);
        unDivBit = BIT(n);
        unDivCntBit = BIT(n);
        unDivBit2 = BIT(n);

        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            add(i, a[i]);
        }

        for (int i = 1; i <= q; i++) {
            int type;
            cin >> type;
            if (type == 1) {
                int pos; long long val;
                cin >> pos >> val;
                remove(pos, a[pos]);
                add(pos, val);
                a[pos] = val;
            }
            else {
                int l, r; long long s;
                cin >> s >> l >> r;
                cout << query(r, s) - query(l - 1, s) << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}