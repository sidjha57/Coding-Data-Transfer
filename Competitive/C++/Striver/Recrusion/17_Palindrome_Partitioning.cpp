#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int start, int end) {
    while (start <= end) 
        if (s[start++] != s[end--])
            return false;
    
    return true;
}

void Palindrome_Partition(int idx, string& s, vector<string>& partition, vector<vector<string>>& ans) {
    if (idx == s.size()) {
        ans.push_back(partition);
        return;
    }

    for (int i=idx; i<s.size(); i++) {
        if (isPalindrome(s, idx, i)) {
            partition.push_back(s.substr(idx, i - idx +1));
            Palindrome_Partition(i+1, s, partition, ans);
            partition.pop_back();
        }
    }
}

int main () {
    string s = "aabb";
    vector<vector<string>> ans;
    vector<string> partition;
    Palindrome_Partition(0,s,partition,ans);

    for (auto x: ans) {
        for (auto i: x) {
            cout << i << " ";
        }
        cout << "\n";
    }
}