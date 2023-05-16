//template
#include <iostream>
#include <string>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
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

struct three_var {
    ll a,b,c;
};

three_var Find_Max_Crossing_Subarray( ll A[], ll low,ll mid,ll high ) {
    three_var max_index;
    ll i,sum = 0;
    ll left_sum= -INT_MAX; //left sum
    for (i = mid; i >= low; i--) { // for i mid to low
          sum += A[i];
          if (sum > left_sum) { // if sum > left sum
               left_sum = sum;
               max_index.a = i;
          } 
    }
    ll right_sum= -INT_MAX; //right sum
    sum = 0;
    for (i = mid +1; i < high; i++) {
        sum += A[i];
        if (sum > right_sum) { // if sum > right sum
              right_sum = sum;
              max_index.b = i;
        }
    }
    max_index.c = left_sum + right_sum;
    return max_index;
}

three_var Find_Max_Subarray (ll A[], ll low , ll high) {
    three_var base_case,left,right,mid;
     if (low == high) {
         base_case.a = low;
         base_case.b = high;
         base_case.c = A[low];
         return base_case;
     }
     else {
         ll middle = floor ((low + high)/2);
         left = Find_Max_Subarray (A,low,middle);
         right = Find_Max_Subarray (A,middle,high);
         mid = Find_Max_Crossing_Subarray (A,low,middle,high);
         if (left.c >= right.c && left.c >= mid.c) 
           return left;
         else if (right.c >= mid.c && right.c >= left.c)
            return right;
         else
            return mid;   
     }

}

 int main(){
     three_var result;
    ll A = (13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7);
    result = Find_Max_Subarray (&A ,0,16);
    cout << result.a << " "<<result.b <<" "<<result.c;
   return 0;
 }