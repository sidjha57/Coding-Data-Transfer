#include <bits/stdc++.h>

using namespace std;

void permutationsBacktrack (string str, int j) {
    if (j == str.size() - 1) {
        cout << str << "\n";
        return;
    } 
    for (int i=j;i<str.size();i++) {
        swap(str[i],str[j]);
        permutationsBacktrack (str,j+1);
        swap(str[i],str[j]);
    }
    
} 

void subsetsBacktrack (int i, int n, int *arr, vector<int>& temp) {
    // base case
    if (i == n) {
        if (temp.size() > 0)
            for (auto x: temp) cout << x << " "; // self work
        cout << "\n";
        return;
    }
    // include
    temp.push_back(arr[i]);
    subsetsBacktrack (i+1, n,arr,temp); // recursion case go and cal all subsets of i+1
    temp.pop_back();
    // not include
    subsetsBacktrack (i+1, n,arr,temp); // recursive case
}

int main() {
    //permutationsBacktrack("ABC",0);
    int arr[] = {1,2,3};
    vector<int> temp;
    subsetsBacktrack (0, 3,arr,temp);
}