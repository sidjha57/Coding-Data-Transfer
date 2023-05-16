//https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

#include<bits/stdc++.h>

using namespace std;
int maxCost(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
    if (n < 0) return 0;
    
    if (dp[day][last] != -1) return dp[day][last];
    
    int mx = 0;
    for (int task=0; task<3; task++) {
        if (task == last) continue;
        mx = max(mx, points[day][task] + maxCost(day-1,task,points,dp));
    }
    
    return dp[day][last] = mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int> (4,-1));
//     return maxCost(n-1,3,points,dp);
    
    
    // Tabulation TC O(N) SC O(N)
//     for (int task=0; task<3; task++) dp[0][task] = points[0][task];  
    
//     for (int day=1; day<n; day++) {
//         for (int task=0; task<3; task++) {
//             dp[day][task] = points[day][task];
//             int mx = 0;
//             for (int k=0; k<3; k++) {
//                 if (j == k) continue;
//                 mx = max(mx,dp[day-1][k]);
//             }
//             dp[day][task] += mx;
//         }
//     }
    
//     return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    
    vector<int> prev(3,0),cur(3,0);
    
    for (int task=0; task<3; task++) prev[task] = points[0][task];  
    
    for (int day=1; day<n; day++) {
        for (int task=0; task<3; task++) {
            cur[task] = points[day][task];
            int mx = 0;
            for (int k=0; k<3; k++) {
                if (j == k) continue;
                mx = max(mx,prev[k]);
            }
            cur[task] += mx;
        }
        prev = cur;
    }
    
    return max(prev[0], max(prev[1], prev[2]));
    
}

int main() {

}