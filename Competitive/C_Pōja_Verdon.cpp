#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]){
    long long int n,sum=0,a; cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a; 
        sum += a;
    } 
    cout << sum;
  return 0;
}