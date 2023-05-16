#include <iostream>

using namespace std;

int main() {
	int t,n;
	cin >> t;
	while(t--){
	    int i,j=0;
	    cin >> n;
	    int a[n];
	    for(i=0;i<n;i++){
	        cin >> a[i];
	    }
        // checking for the array to be palindrome or not
	    for(i=0;i<n/2;i++){
            /* number should be in between 1 to 7, middle number should be 7 and first element 1
            the difference between two consecutive numbers can be either 0 or 1 and lastly we have to also check
            the repeating elements*/
	        if(a[i]<=7 && a[i+1]>=a[i] && a[(n-n/2)-1]==7 &&a[0]==1 && ((a[i+1]-a[i]==0)||(a[i+1]-a[i]==1))){
	            if(a[i]==a[n-(i+1)]) 
	            {
	                j++; // count of every number should be equal
	            }
	        }
	    }
	    if(j==n/2)
	    cout<<"yes\n";
	    else
	    cout<<"no\n";
	}
	return 0;
}

