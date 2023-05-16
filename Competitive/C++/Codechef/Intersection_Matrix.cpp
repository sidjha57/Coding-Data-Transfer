#include <bits/stdc++.h>
using namespace std;

int subsetSum(int a[], int n, int sum)
{
	// Initializing the matrix
	int tab[n + 1][sum + 1];
// Initializing the first value of matrix
	tab[0][0] = 1;
	for (int i = 1; i <= sum; i++)
		tab[0][i] = 0;
	for (int i = 1; i <= n; i++)
		tab[i][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
		// if the value is greater than the sum
			if (a[i - 1] > j)
				tab[i][j] = tab[i - 1][j];
			else
			{
				tab[i][j] = tab[i - 1][j] + tab[i - 1][j - a[i - 1]];
			}
		}
	}


	return tab[n][sum];
}

int main()
{
	int n = 9;
	int a[] = {1,2,3,7,5,6,2,1,2};
	int sum = 6;

	cout << (subsetSum(a, n, sum));
}
