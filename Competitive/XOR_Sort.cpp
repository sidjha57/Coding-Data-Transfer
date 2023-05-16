#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<pair<int, int>> ops;
        int largest = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] < largest) {
                int j = i;
                while (j > 0 && a[j] < a[j-1]) {
                    ops.push_back({j, j-1});
                    swap(a[j], a[j-1]);
                    j--;
                }
            } else {
                largest = a[i];
            }
        }
        for(auto it : a) cout<<it<<" ";
        cout<<endl;

        cout << ops.size() << "\n";
        for (auto op : ops) {
            cout << op.first + 1 << " " << op.second + 1 << "\n";
        }
    }
    return 0;
}