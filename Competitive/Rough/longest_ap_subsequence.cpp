#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int diff) {
        int a = *max_element (nums.begin(),nums.end());
        int b = *min_element (nums.begin(),nums.end());
        int n = max (a,-b);
        vector<int> mp(2*n+5,0);
        vector<int> dp(n,0);
        
        dp[0]=1;
        mp[nums[0]+n]=1;
       
        for(int i=1;i<nums.size();i++){
            if(mp[nums[i] - diff + n]){
                //current till index i we can make pervoius plus one
                dp[i]=mp[nums[i] - diff+n] + 1;
                // than store in map for futher use;
                mp[nums[i]+n]=dp[i];
            }
            else{
                 mp[nums[i]+n] = 1;
                 dp[i]=1;
            }
        }
        
        return *max_element(dp.begin(),dp.end());
}

int main () {
    vector<int> nums {-2, 0, 3, 6, 1, 9};
    cout << solve (nums,3);
}