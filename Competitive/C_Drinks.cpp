#include <bits/stdc++.h>
using namespace std;

int main() {
	int sum=0;
	float ans;
	int n;
	cin >> n;
	int A[n];
	for (int i=0;i<n;i++)
	{
		cin>>A[i];
	    sum += A[i];
	}

        ans=1.0*sum/n;
	cout<<setprecision(6)<<ans;
      
}