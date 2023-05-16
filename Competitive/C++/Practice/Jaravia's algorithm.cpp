#include <bits/stdc++.h>
using namespace std;




  // 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross
  // product. Returns a positive value, if OAB makes a counter-clockwise turn,
  // negative for clockwise turn, and zero if the vector<int>s are collinear.
  int cross(const vector<int> &O, const vector<int> &A, const vector<int> &B) {
    return (A[0] - O[0]) * (B[1] - O[1]) -
           (A[1] - O[1]) * (B[0] - O[0]);
  }

  static bool cmp(vector<int> &p1, vector<int> &p2) {
    return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
  }

  static bool equ(vector<int> &p1, vector<int> &p2) { return p1[0] == p2[0] && p1[1] == p2[1]; }
  // Returns a list of vector<int>s on the convex hull in counter-clockwise order.
  // Note: the last vector<int> in the returned list is the same as the first one.
  vector<vector<int>> outerTrees(vector<vector<int>> &P) {
    int n = P.size(), k = 0;
    vector<vector<int>> H(2 * n);

    // Sort vector<int>s lexicographically
    sort(P.begin(), P.end(), cmp);

    // Build lower hull
    for (int i = 0; i < n; i++) {
      while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
      H[k++] = P[i];
    }

    // Build upper hull
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
      while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
      H[k++] = P[i];
    }

    // Remove duplicates
    H.resize(k);
    sort(H.begin(), H.end(), cmp);
    H.erase(unique(H.begin(), H.end(), equ), H.end());
    return H;
  }
// Driver program to test above functions
int main()
{
    vector<vector<int>>  points {{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}},ans;
	// vector<int> vector<int>s[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
	// 				{3, 0}, {0, 0}, {3, 3}};
	// int n = sizeof(vector<int>s)/sizeof(vector<int>s[0]);
	// convexHull(vector<int>s, n);
    ans = outerTrees(points);
    for (auto p : ans) {
        cout << p[0] << " " << p[1] << "\n ";
    }
	return 0;
}


