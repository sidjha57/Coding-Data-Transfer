// including policy based data structures
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 


#include <bits/stdc++.h>
#define ll long long int
#define loop(i,a,b) for(ll i=(a);i<=(b);i++)

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    ll n,x,t;
    cin >> t;
    while (t--) {
        cin >> n; 
        pbds array;
        ll inversionCount=0;
        loop (i,0,n-1) {
            cin >> x;
            if (i == 0) {
                array.insert(x);
                continue;
            }
            inversionCount += (array.size() - array.order_of_key(x));
            array.insert(x);
            
        }
        cout << inversionCount << "\n";
  }
    
}