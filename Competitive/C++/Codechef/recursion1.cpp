#include <bits/stdc++.h>
#define mod 100000007
#define ll long long int
using namespace std;

//----------------------------------------------------------------
//party problem numbers of ways in which n people can go in party if they choose to either go alone or in a pair of two
// vector<long long int> dp(10000,0);
// long long int  par (long long int n) {
    
//     if (n == 1 || n == 0) return 1;
//      op1 = par(n-1) (if A choses to go alone then rest n-1 people will be only counted)
//     op2 = (n-1)par(n-2) if A choses to go in pair total number of pairs he can make will be n-1 and 
//           corresponding to each pair there will be par(n-2) ways
//     return ((par(n-1)+(n-1)*par(n-2))%mod);
// }

// long long int par (long long int n) {
//     if (dp[n] != 0) return dp[n];
//     dp[n] = (par(n-1)+(n-1)*par(n-2))%mod;

//     return dp[n];
// }

// int main () {
//     dp[0] = 1;dp[1] =1;
//     int n = 50;
//     cout << par(n);
// }
//--------------------------------------------------------------------------



//--------------------------------------------------------------------------

//power funtion

// ll power (ll a,ll b) {
//     ll res =1;
//     if (b == 0) return 1;
//      res = power(a,b/2);
//     if ((b&1) == 1) return res*res*a;
//     else return res*res;
//     //return a*power(a,b-1);
// }

// int main () {
//     ll a=2,b=4;
//     cout << power(a,b);
// }

//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
//to print pattern 1  
//****
//***
//**
//*
// void print_pattern (int n, int i) {
//        if ( n == 0) return;
//        if (i < n) { 
//            //print column
//            cout << "* "; //self work
//            print_pattern(n, i+1);
//        }
       
//        else {
//            cout << "\n";//change row
//            print_pattern(n-1,0); 
//        }
       
// } 

// int main () {
//     print_pattern(3,0); 
// }

// ------------------------------------------------------


//----------------------------------------------------------------
// print pattern 2
//*
//**
//***
//****

// void print_pattern (int n, int i) {
//     if (n == 0) return;

//     if (i < n) {
//          print_pattern (n,i+1);
//          cout << "* ";
//     }
    
//     else {
//         print_pattern(n-1,0);
//         cout << "\n";//change row
//     }
//     // for (int i = 0; i <n; i++) 
//     //     cout << "* ";
//     // cout << "\n";
// }

// int main () {
//     print_pattern(4,0);
// }

//-------------------------------------------------------



// ------------------------------------------------------
// print subsets of a string 

// void printSubsets (int *arr,int n, int i, string osf) {
//     if (i == n) {
//         cout << "["<<osf<<"]\n";
//         return;
//     }
//     //when we choose the element to be included
//     if (arr[i] != '0')
//     printSubsets (arr,n,i+1, osf + to_string(arr[i])+ " ");
//     //when we choose the element to be not included
//     printSubsets (arr,n,i+1,osf);

// }

// int main (){
//     int arr[]={1,0,0,1,0,1,1};//1001011
//     printSubsets (arr,7,0," ");
//     return 0;
// }

//----------------------------------------------------------------



//----------------------------------------------------------------
//print binary strings of length n with no consecutive one's not completed

// void printBinaryStrings(int n, string osf) {
//     if (n == 0) {
//         cout << "["<<osf<<"]\n";
//         return;
//     }
//     if (!(osf[n]))
//     printBinaryStrings (n-1,osf+ "0 ");
//     if (!(osf[n-1]))
//     printBinaryStrings (n-1,osf+ "1 ");
   
// }

// int main () {
//     printBinaryStrings(3,"");
// }

//----------------------------------------------------------------------



//----------------------------------------------------------------------
//find number of ways to traverse from 1,1 to n,n in a matrix only by moving to right or down


// int totalPath = 0;
// void traverse(int i,int j,int n,int m,string osf) {
//     //base cases
//     if (i == n-1 && j == n-1) {
//         totalPath += 1;
//         cout << osf << endl;
//         return;
//     }
//     if (i >=n || j >= m) return; 
//     // self work and recursion
//     traverse(i,j+1,n,m,osf + "R"); //rightward
//     traverse(i+1,j,n,m,osf + "D"); //downward
//     //traverse(i+1,j+1,n,m,osf + "->"); // diagonaly
// }

// int main () {
//    traverse (0,0,3,3,"");
//    cout << totalPath;
// }


//-----------------------------------------------------------------------



//-----------------------------------------------------------------------
//total number of ways to traverse an array with the jump of the numbers on a dice 
// int totalWays = 0;
// void jump (int i, int n, string osf ) {
//     //base cases
//     if (i == n - 1) {
//         totalWays += 1;
//         cout << osf << endl;
//     }
//     if (i >= n) return;
//     //self work and recursion
//     for (int j = 1; j <=6 && i+j < n; j++)
//          jump (i+j,n,osf +to_string(j));
//     // jump (i+2,n,osf +"2");
//     // jump (i+3,n,osf +"3");
//     // jump (i+4,n,osf +"4");
//     // jump (i+5,n,osf +"5");
//     // jump (i+6,n,osf +"6");
// }

// int main () {
//     jump (0,5,"");
//     cout <<"Total ways = " << totalWays;
// }
//--------------------------------------------------------------------------



//--------------------------------------------------------------------------
//given n print the numbers in lexiographical order *very important

// void lexiographicalOrder (int i,int n) {
//     if (i > n) return;
//     cout <<i <<endl;

//     for (int j = (i == 0)? 1:0; j<=9; j++)
//       lexiographicalOrder(i*10+j,n);
// }

// int main () {
//     lexiographicalOrder(0,1000);
// }

//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
//print all the permutations of a string with unique charecters

// void permutations(string str,string prem) {
//   if (str.size() == 0) {
//       cout << prem << endl;
//       return;
//   }
//   for (int i = 0; i < str.size(); i++) {
//       char ch = str[i];
//       string ros = str.substr(0,i) + str.substr(i+1);
//       permutations(ros,prem+ch);
//   }
// }

// int main () {
//     permutations("ABC","");
// }

//--------------------------------------------------------------------------------



//--------------------------------------------------------------------------------
//print all the permutations of a string with or without unique charecters

// void permutations(string str,string prem) {
//   if (str.size() == 0) {
//       cout << prem << endl;
//       return;
//   }
//   unordered_set <char> s;
//   for (int i = 0; i < str.size(); i++) {
//       char ch = str[i];
//       if (s.count(ch) == 0) {
//       string ros = str.substr(0,i) + str.substr(i+1);
//       s.insert(ch);
//       permutations(ros,prem+ch);
//       }
//   }
// }

// int main () {
//     permutations("AAC","");
// }



//------------------------------------------------------------------------------