#include <bits/stdc++.h>

using namespace std;

/* there are n people who are going in party each have chance to either 
go in pair or alone find the number of ways they can go to party*/
int party_peps (int n) {
    // base case
    if (n == 1) return 1;
    if (n == 2) return 2;
    // recursive assumption
    int subproblem1 = party_peps (n-1); // if nth person chooses to go alone,
    int subproblem2 = (n-1)*party_peps (n-2); // if nth person chooses to go in pair
    // self work
    return subproblem1+subproblem2; 
}

// give a and b calculate a^b

int power (int a,int b) {
    // base case
    if (b == 0) return 1;
    // recursive assumption
    int subproblem = a*power(a,b-1);
    // self work
    return subproblem;
}


// optimize the above code 
int bin_power (int a, int b) {
    // base case
    if (b == 0) return 1;
    // recursive assumption
    int ans = bin_power(a,(b>>1)); // b = b/2
    // self work
    if (b&1) return a*ans*ans;
    else return ans*ans;
    
}

//print pattern 
void print_star1 (int n,int i) {
    //base case
    if (n == 0) return;
    if (i < n) {
        // print column
        cout << "* "; // self work
        print_star1(n,i+1); // recursion
    } else {
        // we will change the row
        cout << "\n"; // self work
        print_star1(n-1,0); // recursion
    }
}

//print pattern 
void print_star2 (int n,int i) {
    //base case
   if (n == 0) return;

    if (i < n) {
         print_star2 (n,i+1); // recursion
         // print column
         cout << "* "; // self work
    }
    
    else {
        print_star2(n-1,0); // self work
        //change row
        cout << "\n";//self work
    }
}

// print all subsets of an array
void print_subsets (int arr[],int i,int n, string osf) {
    // base case
    if (i == n) {
        // self work
        cout << "{" << osf <<"}\n";
        return;
    }
    // recursion case
    print_subsets (arr,i+1,n, osf + to_string(arr[i]) + ","); // the ith element is included
    print_subsets (arr,i+1,n, osf); // the ith element is not included
}



// print binary strings of length n such that there are no cosecutive 1's
void print_bin_strings (int i,int n, string osf) {
    // base case
    if (n == i) {
        // self work
        cout << "{" << osf <<"}\n";
        return;
    }
    // recursion
    print_bin_strings (i+1,n,osf + "0");

    if (osf[i-1] == '\0' || osf[i-1] == '0') 
        print_bin_strings (i+1,n,osf + "1");
    
   
   
}

int main () {
    //cout << party_peps(3);
    int arr[] = {0,1,2};
    print_subsets (arr,0,3," ");
    //print_bin_strings(0,3,"");
    // print_star2(5,0);
    // print_star1(5,0);
    
}