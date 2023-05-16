#include <bits/stdc++.h>

using namespace std;


void all_subsequences_given_sum(int s, int i, int sum, vector<int>& arr, vector<int> sub ) {
    if (i >= arr.size()) {
        if (sum == s) {
            for (int &i: sub) cout << i << " ";
            cout << "\n";
        }
        return;
    }

    // pick
    sub.push_back(arr[i]);
    s += arr[i];
    all_subsequences_given_sum(s, i+1, sum, arr, sub);
    sub.pop_back();
    s -= arr[i];

    //not pick
    all_subsequences_given_sum(s, i+1, sum, arr, sub);
}

bool subsequences_given_sum(int s, int i, int sum, vector<int>& arr, vector<int> sub ) {
    if (i >= arr.size()) {

        // condition satisfied
        if (sum == s) {
            for (int &i: sub) cout << i << " ";
            return true;
        }

        // condition not satisfied
        return false;
    }

    // pick
    sub.push_back(arr[i]);
    s += arr[i];
    if (subsequences_given_sum(s, i+1, sum, arr, sub)) return true;
    sub.pop_back();
    s -= arr[i];

    //not pick
    if (subsequences_given_sum(s, i+1, sum, arr, sub)) return true;

    return false;
}

int count_subsequences_given_sum(int s, int i, int sum,vector<int>& arr) {
    if (i >= arr.size()) {
        if (s == sum) return 1;
        return 0;
    }

    // pick
    s += arr[i];
    int l = count_subsequences_given_sum(s, i+1, sum, arr);
    s -= arr[i];

    //not pick
    int r = count_subsequences_given_sum(s, i+1, sum, arr);

    return l+r;
}

int main() {
    vector<int> arr {2,3,6,7};
    
    all_subsequences_given_sum(0,0,7,arr,{});

    /*
        Print Only One Possible Answer

         Make function boolean and return true when condition satisfied
    */
    // subsequences_given_sum(0,0,2,arr,{});

    /*
        Count Number Of Possible Answer

         Make function integer 
         return 1 when condition satisfied 
         return 0 when condition not satisfied 

         l = f()
         r = f()

         return l+r
    */
//    cout << count_subsequences_given_sum(0,0,2,arr);

}