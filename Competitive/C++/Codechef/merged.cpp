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

vector<vector<int>> merge(vector<vector<int>>& intervals) {
       int l=intervals.size(),i,j;
       if (l==1) return intervals;
       int prev_t[l],next_t[l];
       for (i=0;i<l;i++) {
           prev_t[i] = intervals[i][0];
           next_t[i] = intervals[i][1];
       }
        vector<vector<int>> merged(l,vector<int>(2));
        sort (prev_t,prev_t+l);
        sort (next_t,next_t+l);
        j=0;
        if (l == 2) {
            if (next_t[0] >= prev_t[1]) { //there is an overlap
                merged[j][0]=prev_t[0],merged[j][1]=next_t[1];
                j++;
            }
            else {
                merged[j][0]=prev_t[0],merged[j][1]=next_t[0];
                merged[j+1][0]=prev_t[1],merged[j+1][1]=next_t[1];
                j+=2;
            }
            merged.resize(j);
            return merged;
        }
         j=0;
        for (i=0;i<l;i++) {
            if (next_t[i-1] >= prev_t[i]) { //there is an overlap
                merged[j][0]=prev_t[i-1],merged[j][1]=next_t[i];
                j++;
            }
            else {
                 if ((i+1) < l && next_t[i] < prev_t[i+1]){
                 merged[j][0]=prev_t[i],merged[j][1]=next_t[i];
                 j++;
                 }
                 else if (i+1 >= l) {
                 merged[j][0]=prev_t[i],merged[j][1]=next_t[i];
                 j++;
                 }
            }
        }
         
        merged.resize(j);
        return merged;
        
    }

 int main(){
    _cin// for fast I/O
    
     ll t,n,a,b,c,i;
     vector <vector<int>> interval {{1,4},{2,5},{6,8},{8,10},{11,15},{12,13},{17,18}},merged;
     merged = merge(interval);
     for (i=0;i<merged.size();i++) 
         cout << "(" << merged[i][0] << "," << merged[i][1] << "), ";
     
     
   return 0;
 }