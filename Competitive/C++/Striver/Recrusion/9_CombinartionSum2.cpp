#include <bits/stdc++.h>

using namespace std;


void all_subsequences_given_sum(int s, int idx, int sum, vector<int>& arr, vector<int> sub ) {
    if (sum == s) {
        for (int &i: sub) cout << i << " ";
        cout << "\n";
        return;
    }
    
    if (s > sum) return;

    for (int i = idx; i<arr.size(); i++) {
        if (i > idx && arr[i] == arr[i-1]) continue;
        if (arr[i] + s > sum) break;
        
        sub.push_back(arr[i]);
        s += arr[i];
        all_subsequences_given_sum(s, i+1, sum, arr, sub);
        sub.pop_back();
        s -= arr[i];
    }
}

int main () {
    vector<int> arr {10,1,2,7,6,1,5};
    sort(arr.begin(),arr.end());
    int sum = 8;
    /*
        in alphabetical order, unique subsequences
        [
        [1,1,6],
        [1,2,5],
        [1,7],
        [2,6]
        ]
    */
    all_subsequences_given_sum(0,0,sum,arr,{});
}