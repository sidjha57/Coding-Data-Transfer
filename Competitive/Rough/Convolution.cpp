#include<bits/stdc++.h>
using namespace std;

#define ll                       long long int
#define loop(i,a,b)              for(int i=(a);i<=(b);i++)
#define _fast                    ios_base::sync_with_stdio(0);  cin.tie(0);


void solve() {
    ll n,m,a,b,q,sumA=0,sumB=0; cin >> n >> m;
    loop (i,0,n-1) {
        cin >> a;
        sumA += a;
    }
    loop (i,0,m-1) {
        cin >> b;
        sumB += b;
    }
    cin >> q;
    ll qtype,l,r,x;
    while (q--) {
        cin >> qtype;
        if (qtype == 1) {
            cin >> l >> r >> x;
            sumA += (r-l+1)*x;
        } else if (qtype == 2) {
            cin >> l >> r >> x;
            sumB += (r-l+1)*x;
        } else {
            cout << sumA*sumB << "\n";
        }
    }
}

int main(int argc, char const *argv[]){
    _fast
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}