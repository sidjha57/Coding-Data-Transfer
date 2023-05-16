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

// class heap {
//     public:
//      ll size,root;
//      ll a[200010];

//     heap(ll n) {
//         size=0,root=1;
//     }

//     void push (ll val) {
//         ll node = ++size;
//         a[size] = val;
//         while (node != root) {
//             if (a[node] > a[parent(node)]) break;
//             swap(a[node],a[parent(node)]);
//             node = parent(node);
//         }
//     } 

//     ll top () {
//          if(isEmpty()){
//             cout<<"Empty Heap :(\n";
//             return -1;
//         }
//         return a[root];
//     } 

//     void pop () {
//          if(isEmpty()){
//             cout<<"Empty Heap :(\n";
//             return;
//         }
//         swap(a[root],a[size--]);
//         heapify(root);
        
//     }
//     void remove (ll val) {
//         for (ll i=1; i<=size; i++) {
//             if (a[i] == val) {
//                 swap (a[i],a[size--]);
//                 heapify(i);
//                 break;
//             }
//         }
//     }

//     void heapify (ll node) {
//         ll largest = node;
//         if (left_child(node) <=size && a[largest] > a[left_child(node)]) largest = left_child(node);
//         if (right_child(node) <= size && a[largest] > a[right_child(node)]) largest = right_child(node);

//         if (largest != node) {
//             swap (a[largest],a[node]);
//             heapify(largest);
//         }
//         return;
//     }
    
//     bool isEmpty () {
//         if (size == 0) return true;
//         return false;
//     }
    
//     ll getsize () {
//         return size;
//     }

//     ll parent (ll node) {
//         return node/2;
//     }

//     ll left_child (ll node) {
//          return node*2;
//     }

//     ll right_child (ll node) {
//         return node*2+1;
//     }

//     void print () {
//         for (ll i = 1; i <= size; i++) 
//             cout << a[i] << " ";
//         cout<<"\n";
//     }

// };

//  int main(){
//     _cin// for fast I/O
    
//       ll n,num,i;
//       cin>>n;
//       vl price(n),front(n),back(n);
//       unordered_map <ll,pair<ll,ll>> m;
//       f (i,n) cin >> price[i];
//       f (i,n) cin >> front[i];
//       f (i,n) cin >> back[i];
//       cin >> num;
//       vl customer(num);
//       f (i,num) cin >> customer[i];
//       f (i,n)  
//           m.insert({price[i],{front[i],back[i]}});
//       heap pq(n);

//       for (ll i=0;i<n;i++) {
//           pq.push(price[i]);
//       }
      
//       for (ll j=0;j<num;j++) {
//           if (pq.isEmpty()) {
//               cout << "-1 ";
//           }

//           for ( i=1;i<=pq.size;i++) {
//               ll fr= m[pq.a[i]].first,bk=m[pq.a[i]].second;
//               if (m[pq.a[i]].first == customer[j] || m[pq.a[i]].second == customer[j]) {
//                   cout << pq.a[i] <<" ";
//                   ll val = pq.a[i];
//                   pq.remove(val);
//                   break;
//               }
//               if (i==pq.size) cout <<"-1 ";
//           }

          

//       }
//    return 0;
//  }

#include <bits/stdc++.h>

#define ll long long
#define pp pair<ll,ll>
#define f(n) for (ll i=0; i<n;i++)

using namespace std;

class cmp {
    public:
    bool operator()(pp a, pp b) {
        return a.first > b.first;
        } 
};

priority_queue <pp,vector<pp>,cmp> pq[4];

int main () {
    ll n,cn;
    cin >> n;
    vector<ll> price(n),front(n),back(n),taken(n+1,0);
    f(n) cin >> price[i];
    f(n) cin >> front[i];
    f(n) cin >> back[i];
    cin >> cn;
    vector<ll> customer(cn);
    f(n) { 
        pq[front[i]].push({price[i],i+1});
        pq[back[i]].push({price[i],i+1});
    }
    ll fav,x;
    while (cn--) {
        cin >> fav;
        x = -1;
        while (!(pq[fav].empty())) {
            pp u=pq[fav].top(); pq[fav].pop();
            if(taken[u.second])
                continue;

            taken[u.second]=1;
            x=u.first;
            break;
             
        }
        cout << x <<" ";
    }

    return 0;
}