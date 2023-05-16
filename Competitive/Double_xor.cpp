#include<bits/stdc++.h>
using namespace std;

long long find_max (vector<long long> arr) {
   long long ans = 0;
   for (int i=32; i>=0; i--) {
     
      vector<long long> new_arr;
      int bit,set_bits=0,n=arr.size();

      for (int j=0; j<n; j++) {
         if ((arr[j]>>i)&1) 
            set_bits++;
      }

      if (n == 2*set_bits) continue;

      (2*set_bits > n)? bit = 0: bit = 1;

      for (int j=0; j<n; j++) {
         if (((arr[j]>>i)&1) == bit) 
            new_arr.push_back(arr[j]);
      }

      if (!new_arr.empty())
        arr = new_arr;

      if (arr.size() == 1) 
        return arr[0];
   }

   return arr[0];
}
long long maximumPossibleScore (int n, vector<long long> a) {
   
   long long ans = 0, x;
   x = find_max(a);
   for (int i=0; i<n; i++) {
      ans += (x^a[i]);
   }
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i_A = 0; i_A < N; i_A++)
    {
    	cin >> A[i_A];
    }

    long long out_;
    out_ = maximumPossibleScore(N, A);
    cout << out_;
}


/*  
    3 2 1 0
    1 1 1 1
    1 0 0 0
    1 0 1 1
    1 1 0 0
    1 0 0 1
        

    i = 2
      0's = 3
      1's = 2
    
    1 1 0 0
    1 1 1 1

    i = 1
        0's = 1
        1's = 1
    
    i = 0

    

*/