#include <bits/stdc++.h> 
using namespace std;
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int i =  m-1, j = n+m -1;
    while (i >= 0) {
        swap(arr1[i--],arr1[j--]);
    }
    arr1.push_back(100001);
    arr2.push_back(100001);
    i = 0;
    int k = 0;
    while (k < (n+m)) {
        if (arr1[j] > arr2[i]) arr1[k] = arr2[i++];
        else arr1[k] = arr1[j++];
        k++;
    }
    arr1.pop_back();
    return arr1;
}

int main () {
    vector<int> a {2, 5, 10, 0, 0, 0, 0, 0, 0 }, b {2,4,5,9,10,20};

    ninjaAndSortedArrays(a,b,3,6);
    return 0;
}