#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;

    int l=1,r=n-1,suml=a[0],sumr=0;
    while (l <= r)
    {
        if (suml <= sumr)
        {
            suml += a[l++];
        }
        else
        {
            sumr += a[r--];
        }
    }

    cout << l << " " << (n-l);
}