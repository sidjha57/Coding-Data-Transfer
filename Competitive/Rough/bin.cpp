#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

int solve(vector<int>& nums) {
    map<int,int> occu;
    for (int i=0;i<nums.size();i++) {
        occu[nums[i]]++;
    }
    int ans=nums.size();
    for (auto x : occu) {
        ans += (x.second*(x.second-1)/2);
    } 
    return ans;
}


int main () {
    vector<int> nums {1,1,5,1};
    cout << solve(nums);
}