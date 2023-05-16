#include <bits/stdc++.h>
#define ll long long

using namespace std;

int MaximumSumSize (int arr[],int num,int n) {
    vector<int> PrefixSum(n,0);
    int i,sum=0,j,l,k;
    for (i=0;i<n;i++) {
        if (arr[i] > num) return -1; 
        sum += arr[i];
        PrefixSum[i] = sum;
    }
    if (PrefixSum[n-1] < num) return n;
    k = 1,l;
    while (k != n-2) {
         i = n-1-k;
        if (PrefixSum[i] < num) {
        l = 0,i=n-k,j=0;
        while (l != k) {
           
           sum = PrefixSum[i] - PrefixSum[j];
           if (sum > num) break;
         
         l++,j++,i++;
        }
        if (l == n-k) return l;
      } 
        k++;
    }
    return 1;  
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int k = 16, n = (sizeof(arr)/sizeof(arr[0]));
    cout<<MaximumSumSize(arr,k,n);
}