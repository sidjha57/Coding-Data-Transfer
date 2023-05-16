#include <bits/stdc++.h>

using namespace std;


void all_subsequences_given_sum(int s, int i, int sum, vector<int>& arr, vector<int> sub ) {
    if (i >= arr.size()) {
        if (sum == s) {
            for (int &x: sub) cout << x << " ";
            cout << "\n";
        }
        return;
    }

    if (s > sum) return;
    // pick
    sub.push_back(arr[i]);
    s += arr[i];
    all_subsequences_given_sum(s, i, sum, arr, sub);
    sub.pop_back();
    s -= arr[i];

    //not pick
    all_subsequences_given_sum(s, i+1, sum, arr, sub);
}

int main () {
    vector<int> arr {2,3,6,7};
    int sum = 7;
    // 2 2 3, 7 each index can be picked more than once
    all_subsequences_given_sum(0,0,sum,arr,{});
}