#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    map <string,int> freq;
    int n; cin>>n;
    string s,a="",ans; cin >>s;
    int maxi = 0;
    for(int i=0;i<n-1;i++) {
            a = "";
            a = a +s[i]+s[i+1];
            freq[a]++;
    }
    for (auto x: freq) {
        if (x.second > maxi) {
             maxi = x.second;
             ans =x.first;
        }
       
    }
    
    cout << ans;
    return 0; 
}
