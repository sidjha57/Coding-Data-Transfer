#include<bits/stdc++.h>
using namespace std;
long long find_max (vector<long long>& arr, int len, int x) {
   long long ans = -1;
   int i=0;
   while (i+len < arr.size()) {
      long long an = arr[i];
      for (int j=i+1; j<len; j++) {
         an &= arr[j];
      }
      ans = max(ans,(an|x));
      i++;
   }
   
   
   return ans;
}
vector<long long> solve (int n, int m, vector<int>& a, vector<vector<int>>& q) {
   vector<vector<long long>> sum (n+1);
   vector<long long> pre(n+1,0),ans, arr;
   for (int i=0; i<n;i++) {
      pre[i+1] += a[i] + pre[i];
   }
   for (int i=0; i<=n;i++) {
      for (int j =i+1; j <= n; j++) {
         sum[(j-i)].push_back((pre[j]-pre[i]));
      }
   }
   
   for (int i=0; i<m; i++) {
      int siz = q[i][0], len = q[i][1], x = q[i][2];
      
      arr = sum[siz];
    //   for (int i=0; i<arr.size(); i++) arr[i] |= x;
      
      long long mx = find_max(arr,len,x);
      ans.push_back(mx);
   }
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int M;
    cin >> M;
    vector<int> A(N);
    for(int i_A = 0; i_A < N; i_A++)
    {
    	cin >> A[i_A];
    }
    vector<vector<int> > Q(M, vector<int>(3));
    for (int i_Q = 0; i_Q < M; i_Q++)
    {
    	for(int j_Q = 0; j_Q < 3; j_Q++)
    	{
    		cin >> Q[i_Q][j_Q];
    	}
    }

    vector<long long> out_;
    out_ = solve(N, M, A, Q);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}