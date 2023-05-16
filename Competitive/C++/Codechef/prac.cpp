// //template
// #include <iostream>
// #include <string>
// #include <set>
// #include <list>
// #include <map>
// #include <unordered_map>
// #include <stack>
// #include <queue>
// #include <deque>
// #include <vector>
// #include <utility>
// #include <iomanip>
// #include <sstream>
// #include <bitset>
// #include <cstdlib>
// #include <iterator>
// #include <algorithm>
// // C Header Files
// #include <cstdio>
// #include <cctype>
// #include <cmath>
// #include <math.h>
// #include <ctime>
// #include <cstring>

// using namespace std;

// #define ull unsigned long long
// #define ld long double
// #define pb push_back
// #define pu pop_up
// #define ff first
// #define ss second
// #define mp make_pair
// #define vv vector
// #define endl '\n'
// #define f(i,n) for(ll i=0;i<n;i++)
// #define fo(i,a,b) for(ll i=a;i<=b;i++)
// #define SET(a) memset( a, -1, sizeof a )
// #define CLR(a) memset( a,  0, sizeof a )
// #define Pi 3.141592653589793
// #define mod 1000000007
// #define _cin ios_base::sync_with_stdio(0);  cin.tie(0);

// /// TypeDef Start
// typedef  long long int       ll;
// typedef  map<string,int>     msi;
// typedef  map<int,int>	    mii;
// typedef  map<ll, ll>         mll;
// typedef  map<char,int>       mci;
// typedef  map<int,string>     mis;
// typedef  pair<int,int>       pii;
// typedef  pair<string,int>    psi;
// typedef  pair<string,string> pss;
// typedef  vector<int> 	    vi;
// typedef  vector<string>      vs;
// typedef  vector<char>	    vc;
// typedef  vector<bool>        vb;
// typedef  vector<ll>          vl;
// typedef  vector< pii >       vii;

// /// Functions Start
// template <class T> T amax( T a, T b ) {return ( a > b ? a : b );}
// template <class T> T amin( T a, T b ) {return ( a < b ? a : b );}
// template <class T> T gcd(T a,T b) {if(b == 0)return a;return gcd(b,a%b);}
// template <class T> T lcm(T a, T b ) {return (a*b)/gcd(a,b);}
// template <class T> T prime(T n) { if(n%2==0)return 0; else{T count=0; 
// for(T i=3;i<sqrt(n)+1;i+=2)
// {if(n%i==0)count++;if(count==1)break;}
// if(count==1)return 0; else return 1;}} //at max 15812 times for 9 digit long number

//     vector<int> plusOne(vector<int>& digits) {
//         int i =digits.size();
//         while (digits[i-1] == 9)
//             --i;
//         if (i != 0) digits[i-1] += 1;
        
//         else {
//         for (int j =i;j<digits.size(); j++)
//             digits[j] = 0;
//             if (i == 0 ) {
//                 digits[0] = 1;
//                 digits.push_back(0);
//             }
//         }
       
//         return digits;
//     }
// // Driver Code
// int main()
// {
//     vector<int> nums = {9,9,9,3};
//      plusOne(nums);
    
    
//     return 0;
// }

// C++ implementation to perform 
// above operations and queries 
#include <bits/stdc++.h> 
using namespace std; 

/* 
Code Parameters 
p->for every node first value is it's original value 
and second value is it's addup value 
subtree_sum[]-> to store the subtree_sum at every node 
visit-> for dfs1 
visit2->for dfs2 
*/
vector<pair<int, int> > p; 
vector<int> adj[10000]; 
int subtree_sum[10000], visit[10000], visit2[10000]; 

int dfs1(int root) 
{ 
	// for leaf node 
	if (adj[root].size() == 0) { 

		// if leaf node then add the addup 
		// sum to it's original value 
		p[root].first += p[root].second; 
		return 0; 
	} 

	int sum = 0; 

	for (int i = 0; i < adj[root].size(); i++) { 
		if (visit[adj[root][i]] == 0) { 
			dfs1(adj[root][i]); 

			// add the addup sum of all the adjacent 
			// neighbors to the current node 
			p[root].second += p[adj[root][i]].second; 
			visit[adj[root][i]] = 1; 
		} 
	} 

	// process the root node 
	p[root].first += p[root].second; 

	return 0; 
} 

int dfs2(int root) 
{ 
	if (adj[root].size() == 0) { 

		// for the leaf node subtree_sum 
		// will be it's own value 
		subtree_sum[root] = p[root].first; 
		return p[root].first; 
	} 

	int sum = p[root].first; 

	for (int i = 0; i < adj[root].size(); i++) { 
		if (visit2[adj[root][i]] == 0) { 
			sum += dfs2(adj[root][i]); 
			visit2[adj[root][i]] = 1; 
		} 
	} 

	// calculate the subtree_sum 
	// for the particular root node 
	subtree_sum[root] = sum; 

	return sum; 
} 

// Driver code 
int main() 
{ 

	int nodes = 7, m = 4, qu = 5, b; 
	int a[] = { 0, 1, 2, 2, 2, 1, 2 }; 
	// for root node 
	p.push_back(make_pair(0, 0)); 

	for (int i = 0; i < nodes; i++) { 

		if (a[i] != 0) 
			adj[a[i]].push_back(i + 1); 

		// for every node 
		p.push_back(make_pair(0, 0)); 
	} 

	vector<pair<string, pair<int, int> > > v; 
	v.push_back(make_pair("ADD", make_pair(6, 76))); 
	v.push_back(make_pair("ADDUP", make_pair(1, 49))); 
	v.push_back(make_pair("ADD", make_pair(4, 48))); 
	v.push_back(make_pair("ADDUP", make_pair(2, 59))); 

	for (int i = 0; i < m; i++) { 
		string s = v[i].first; 
		int a = v[i].second.first; 
		int b = v[i].second.second; 
		if (s == "ADD") 
			// adding to it's own value 
			p[a].first += b; 

		else
			// adding to it's addup value 
			p[a].second += b; 
	} 

	// to process the offline queries 
	dfs1(1); 

	// to store the subtree sum for every root node 
	dfs2(1); 

	vector<pair<string, int> > q; 
	q.push_back(make_pair("VALTREE", 1)); 
	q.push_back(make_pair("VALTREE", 5)); 
	q.push_back(make_pair("VAL", 5)); 
	q.push_back(make_pair("VALTREE", 2)); 
	q.push_back(make_pair("VAL", 2)); 
	for (int i = 0; i < qu; i++) { 
		string s = q[i].first; 
		int a = q[i].second; 

		if (s == "VAL") 
			cout << p[a].first << "\n"; 
		else
			cout << subtree_sum[a] << "\n"; 
	} 
} 

