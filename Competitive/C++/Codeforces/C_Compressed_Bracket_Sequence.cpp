// CPP program to find number of
// balanced parenthesis sub strings
#include <bits/stdc++.h>
using namespace std;

// Function to find number of
// balanced parenthesis sub strings
int Balanced_Substring(string str, int n)
{
	// To store required answer
	int ans = 0;

	// Vector to stores the number of
	// balanced brackets at each depth.
	vector<int> arr(n / 2 + 1, 0);

	// d stores checks the depth of our sequence
	// For example level of () is 1
	// and that of (()) is 2.
	int d = 0;
	for (int i = 0; i < n; i++) {
		// If open bracket
		// increase depth
		if (str[i] == '(')
			d++;

		// If closing bracket
		else {
			if (d == 1) {
				for (int j = 2; j <= n / 2 + 1 && arr[j] != 0; j++)
					arr[j] = 0;
			}
			++ans;
			ans += arr[d];
			arr[d]++;
			d--;
		}
	}

	// Return the required answer
	return ans;
}

// Driver code
int main()
{
	string str = "(((())))";

	int n = str.size();

	// Function call
	cout << Balanced_Substring(str, n);

	return 0;
}
