#include<bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h> 

int maxi (int i, vector<int>& nums, vector<int>& dp) {
    if (i < 0) return 0;
    
    if (dp[i] != -1) return dp[i];
    
    int pick = INT_MIN, not_pick = INT_MIN;
    pick = nums[i] + maxi(i-2, nums, dp);
    not_pick = 0 + maxi(i-1, nums, dp);
    
    return dp[i] = max(pick, not_pick);
} 

int maximumNonAdjacentSum(vector<int> &nums){
    
    // TC O(N) SC O(N)
//     vector<int> dp(nums.size()+1, -1);
//     return maxi(nums.size()-1, nums, dp);
    
    // Tabulation
//     dp[0] = 0;
//     dp[1] = nums[0];
    
//     for (int i=2; i<=nums.size(); i++) {
//         int pick = nums[i-1] + dp[i-2];
//         int not_pick = 0 + dp[i-1];
//         dp[i] = max(pick,not_pick);
//     }
    
//     return dp[nums.size()];
    
    // Space Optimized TC O(N) SC O(1)
    
    int prev2 = 0, prev1 = nums[0];
    
    for (int i=2; i<=nums.size(); i++) {
        int pick = nums[i-1] + prev2;
        int not_pick = 0 + prev1;
        prev2 = prev1;
        prev1 = max(pick,not_pick);
    }
    return prev1;
} 

int main() {
    vector<int> nums {2, 1, 4, 9};
    cout << maximumNonAdjacentSum(nums);
}