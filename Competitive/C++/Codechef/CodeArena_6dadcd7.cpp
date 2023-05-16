#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> prime{67,71,73,79,83,89,97,101,103,107,109,113};
int main() {
	int t,i,j,n,N;
    cin >> t;
	while (t--) {
		cin >> N;
        char s[N];
        for (i = 0; i < N;i++) cin >> s[i];
		for (i=0;i<N;i++) {
			if (find(prime.begin(),prime.end(),(int)s[i]) == prime.end()) {
               
                n = int (s[i]);
                 int min = n-67,k=0;
				for (j=0;j<7;j++) {
                      if (abs(n-prime[j] )<min) {
                          min = abs(n-prime[j]);
                          k = j;
                      }
                }
				s[i] = char(prime[k]);
			}
		}
        for (i=0;i<N;i++)
		cout << s[i];
        cout <<"\n";
	}
}