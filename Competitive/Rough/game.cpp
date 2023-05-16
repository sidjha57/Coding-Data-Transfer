#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums) {
    int freq[13]={},sum=0,maxi=-1;
    freq[0] = nums.size();
    for (int i=0;i<nums.size();i++) {
        string s = to_string(nums[i]);
        freq[s.size()]++;
        sum += nums[i];
    }
    
    //for (int i=0;i<13;i++) cout << freq[i] << " ";
    int value=0,power=1;
    for (int i=0;i<13;i++) {
         value += power*freq[i];
         power *= 10;
    }
    // cout << value <<" ";
    return value*sum;
}

int main () {
    vector<int> nums {10,2,4,5};
    cout << solve(nums);
}