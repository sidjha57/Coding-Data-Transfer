#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
void print (ll m) {
    for (ll x=3;x<m;x++) 
        for (ll y=3;y<m;y++) 
            for (ll z=3;z<m;z++)
                for (ll d=m-1;d>=3;d--) 
                if ((binpow(x,d,m) + binpow(y,d,m) - binpow(z,d,m))%m == 0) {
                    cout << x << " " << y << " " << z << " " << d ;
                    return;
                }
}
ll m = 1e9+7;
int main () {
    vector<ll> arr  {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
    101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
    	211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 
        307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 
         401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};

    vector<ll> a {
        44119,	44123,	44129,	44131,	44159,	44171,	44179,	44189,	44201,	44203,
44207,	44221,	44249,	44257,	44263,	44267,	44269,	44273,	44279,	44281,
50527,	50539,	50543,	50549,	50551,	50581,	50587,	50591,	50593,	50599,
    };

    for (auto p : a) {
        cout << p << " : ";
        print (p);
        cout << "\n";
    }
    // print(19);
}

// #include <bits/stdc++.h>
// #define ll long long int
// using namespace std; 

// int main(){ 
// ios_base::sync_with_stdio(0);cin.tie(0);
// cout.tie(0);
//     ll t,k,i,j,l=0;
//     cin>>t;
//     while(t--){
//         cin>>k;
//         ll a[k],n=0;
//     for(i=0;i<k;i++) cin>>a[i];

//     for(j=0;j<k-1;j++)
//         for(i=1+j;i<k;i++)
//             if(a[j]==a[i]){
//                 n++;
//                 break;
//             }
      
  
//     if(n>0)
//         cout<<"NO\n";
//     else 
//         cout<<"YES\n";
      
//     return 0;
// }