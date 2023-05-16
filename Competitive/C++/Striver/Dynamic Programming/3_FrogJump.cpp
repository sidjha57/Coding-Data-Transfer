#include<bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h> 

int min_jumpcost (int i, vector<int>& heights, vector<int>& dp) {
    if (i == 0) return 0;
    if (i == 1) return abs(heights[1] - heights[0]);
    if (dp[i] != -1) return dp[i];
    int l = abs(heights[i-1] - heights[i]) + min_jumpcost(i-1,heights,dp);
    int r = abs(heights[i-2] - heights[i]) + min_jumpcost(i-2,heights,dp);
    return dp[i] = min(l,r);
}
int frogJump(int n, vector<int> &heights)
{
    //memomization TC O(N) SC O(N)
    vector<int> dp(n+1,-1);
    //     return min_jumpcost(n-1,heights,dp);

    // tabulation TC O(N) SC O(N)
//     dp[0] = 0;
//     dp[1] = abs(heights[1] - heights[0]);
//     for (int i=2; i<n; i++) {
//         int l = abs(heights[i] - heights[i-1]) + dp[i-1];
//         int r = abs(heights[i] - heights[i-2]) + dp[i-2];
//         dp[i] = min(l,r);
//     }
    
//     return dp[n-1];
    
    // space optimised TC O(N) SC O(1)
    int prev2 = 0, prev1 = abs(heights[1] - heights[0]),cur;
    for (int i=2; i<n; i++) {
        int l = abs(heights[i] - heights[i-1]) + prev1;
        int r = abs(heights[i] - heights[i-2]) + prev2;
        prev2 = prev1;
        prev1 = min(l,r);
    }
    
    return prev1;
}



int main() {
    vector<int> heights {10, 20, 30, 10};
    cout << frogJump(heights.size(), heights);
}