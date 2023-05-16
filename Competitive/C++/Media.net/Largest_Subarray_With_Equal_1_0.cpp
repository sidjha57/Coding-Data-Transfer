#include <bits/stdc++.h> 
using namespace std;
int findSubarray(vector<int> arr)
{
    vector<int> prefix(arr.size(),0);
    int mx = 0;
    unordered_map<int,int> mp; // num,idx
    prefix[0] = (arr[0] == 1) ? 1 : -1;
    mp[prefix[0]] = 0;
    for (int i=1; i<arr.size(); i++) {
        prefix[i] += (arr[i] == 1) ? prefix[i-1] + 1 : prefix[i-1]-1;
        if (prefix[i] == 0) mx = max(mx,i+1);
        else if (mp.find(prefix[i]) != mp.end()) {
            mx = max(mx, i - mp[prefix[i]]);
        } else {
            mp[prefix[i]] = i;
        }
    }
    return mx;
}


int main () {
    int n,t; cin >> t;
    while(t--) {
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i]; 
        }
        cout << findSubarray(a) << "\n";
    } 
}
