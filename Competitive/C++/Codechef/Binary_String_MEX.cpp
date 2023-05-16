//template
#include <iostream>
#include <string>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
// C Header Files
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>

using namespace std;

#define ull unsigned long long
#define ld long double
#define pb push_back
#define pu pop_up
#define ff first
#define ss second
#define mp make_pair
#define vv vector
#define endl '\n'
#define f(i,n) for(ll i=0;i<n;i++)
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define SET(a) memset( a, -1, sizeof a )
#define CLR(a) memset( a,  0, sizeof a )
#define Pi 3.141592653589793
#define mod 1000000007
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0);

/// TypeDef Start
typedef  long long int       ll;
typedef  map<string,int>     msi;
typedef  map<int,int>	    mii;
typedef  map<ll, ll>         mll;
typedef  map<char,int>       mci;
typedef  map<int,string>     mis;
typedef  pair<int,int>       pii;
typedef  pair<string,int>    psi;
typedef  pair<string,string> pss;
typedef  vector<int> 	    vi;
typedef  vector<string>      vs;
typedef  vector<char>	    vc;
typedef  vector<bool>        vb;
typedef  vector<ll>          vl;
typedef  vector< pii >       vii;

/// Functions Start
template <class T> T amax( T a, T b ) {return ( a > b ? a : b );}
template <class T> T amin( T a, T b ) {return ( a < b ? a : b );}
template <class T> T gcd(T a,T b) {if(b == 0)return a;return gcd(b,a%b);}
template <class T> T lcm(T a, T b ) {return (a*b)/gcd(a,b);}
template <class T> T prime(T n) { if(n%2==0)return 0; else{T count=0; 
for(T i=3;i<sqrt(n)+1;i+=2)
{if(n%i==0)count++;if(count==1)break;}
if(count==1)return 0; else return 1;}} //at max 15812 times for 9 digit long number



 
// Function computes all the subsequence of an string
void subsequence(string str,unordered_set<string>& st)
{
     
    // Iterate over the entire string
    for (int i = 0; i < str.length(); i++)
    {
         
        // Iterate from the end of the string
        // to generate substrings
        for (int j = str.length(); j > i; j--)
        {
            string sub_str = str.substr(i, j);
            if (sub_str[0] == '0') continue;
            
            st.insert(sub_str);
 
            // Drop kth character in the substring
            // and if its not in the set then recur
            for (int k = 1; k < sub_str.length() - 1; k++)
            {
                string sb = sub_str;
 
                // Drop character from the string
                sb.erase(sb.begin() + k);
                subsequence(sb,st);
            }
        }
    }
}
 void decToBinary(int n) {
	// array to store binary number
	int binaryNum[32];

	// counter for binary array
	int i = 0;
	while (n > 0) {

		// storing remainder in binary array
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	// printing binary array in reverse order
	for (int j = i - 1; j >= 0; j--)
		cout << binaryNum[j];
  cout <<"\n";
}
// Driver Code
int main()
{
  ll t,i,j;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    j =0;
    for (i=0; i<s.length(); i++) if (s[i]=='1') j++;
    if (j == s.length()) cout <<"0\n";
    else {
    unordered_set<string> st;
    unordered_map <ll,ll> m;
    subsequence(s,st);
    for (auto i : st)
         m[stoll(i,0,2)] = 1;
    
    for(i=1;m[i]!= 0;i++);
     decToBinary(i);
    }
  }
   return 0;
}

