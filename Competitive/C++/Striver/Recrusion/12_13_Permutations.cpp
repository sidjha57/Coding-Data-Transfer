#include<bits/stdc++.h>

using namespace std;

void premute_extra_space (vector<int>& ds, vector<int>& nums, vector<int>& freq) {
    if (ds.size() == nums.size()) {
        for (int i: ds) cout << i << " ";
        cout << "\n";
         return;
    }

    for (int i=0; i<nums.size(); i++) {
        if (!freq[i]) {
            ds.push_back(nums[i]);
            freq[i] = 1;
            premute_extra_space(ds,nums,freq);
            ds.pop_back();
            freq[i] = 0;
        }
    }
}
void permute(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            for (int i: nums) cout << i << " ";
            cout << "\n";
            return;
        }

        for (int i=idx; i<nums.size(); i++) {
            swap(nums[idx],nums[i]);
            permute(idx+1,nums);
            swap(nums[idx],nums[i]);
        }

}

int main () {
    vector<int> nums {1,2,3},ds;
    vector<int> freq(nums.size(),0);
    // permute(0,nums);
    premute_extra_space(ds,nums,freq);
}