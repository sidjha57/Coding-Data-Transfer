#include <bits/stdc++.h>

using namespace std;

void subsets (int idx, vector<int>& nums, vector<int> subs, vector<vector<int>>& ans) {
    ans.push_back(subs);
    
    for (int i=idx; i<nums.size(); i++) {
        if (i > idx && nums[i] == nums[i-1]) continue;
        subs.push_back(nums[i]);
        subsets(i+1, nums, subs, ans);
        subs.pop_back();
    }

}

int main() {

}