#include<bits/stdc++.h>

using namespace std;

void print_subsequences(vector<int>& arr, vector<int> sub, int i) {
    if (i >= arr.size()) {
        for (int x : sub) cout << x << " ";
        cout << "\n";
        return;
    }
    print_subsequences(arr,sub,i+1);
    sub.push_back(arr[i]);
    print_subsequences(arr,sub,i+1);
    sub.pop_back();
}

int main() {
    vector<int> arr {3,1,2};
    print_subsequences(arr,{},0);
}

/*
    f({},0) => f({},1) => f({},2) => f({},3) (line 9) => f({2},2) => f({2},3) (line 9) => f({},2) 
    => f({},1) 

            

*/