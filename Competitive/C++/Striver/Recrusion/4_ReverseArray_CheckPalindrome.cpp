#include <bits/stdc++.h>
using namespace std;


void reverse(int i, int j, vector<int>& arr) {
    if (i > j) return;
    swap(arr[i], arr[j]);
    reverse(i+1,j-1,arr);
}

bool palindrome (int i, int j, string& s) {
    if (i > j) return true;
    if (s[i] != s[j]) return false;
    return palindrome(i+1,j-1,s);
}

int main() {
    vector<int> arr {1,2,3,4,5};
    reverse(0,arr.size()-1,arr);
    for (auto i: arr) cout << i << " ";

    string s = "abccba";
    cout << palindrome(0,5,s);
    s = "ababbs";
    cout << palindrome(0,5,s);
    return 0;
}