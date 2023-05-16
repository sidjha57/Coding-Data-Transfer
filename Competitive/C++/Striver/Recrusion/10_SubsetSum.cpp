#include<bits/stdc++.h>

using namespace std;

void SubsetSum (int i, int sum, vector<int>& arr) {
    if (i >= arr.size()) {
        cout << sum << " ";
        return;
    }

    SubsetSum(i+1, sum, arr);
    SubsetSum(i+1, sum+arr[i], arr);
}

int main() {
    vector<int> arr {2,3};
    SubsetSum(0,0,arr);
}