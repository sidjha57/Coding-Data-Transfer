#include <bits/stdc++.h>

using namespace std;

/* you are given a 2d matrix of dimension n*m,you will start from top left cell and you 
have to go to bottom right you can either go right or down print and count all possible paths*/
int cnt=0;
void print_paths (int i, int j,int n, int m, string osf) {
    // base case
    if (i == n && j == m) {
        cout << osf << "\n"; // self work
        cnt++;
    }
    if (j > m || i > n) return; 
    
    // recursive case
    print_paths(i,j+1,n,m,osf + "R"); // right move
    print_paths(i+1,j,n,m,osf + "D"); // downward move
    //print_paths(i+1,j+1,n,m,osf + "I"); // diogonal move
    
}

/* There are n cells arranged in linear fashion. you have a dice with six faces [1,2,3,4,5,6] 
you are standing at the 0th and want to reach the n-1th cell at each cell you can have 6 possible 
jumps to make in how many ways you can reach n-1th cell print the ways */
int total_ways = 0;
void print_num_ways (int i,int n, string osf) {
    // base case 
    if (i == n) {
        cout << osf << "\n"; // self work
        total_ways ++;
        return;
    }
    for (int jumps = 1;jumps <=6;jumps++) {
        if (i > n) return;
        print_num_ways(jumps+i,n,osf + to_string(jumps) + " ");
    } 
}

/* you will be given n, print the first n+1 whole numbers in lexiographical order */

void lexiographical_order (int i,int n) {
   // base case
   if (i > n) return;
   // self work
    cout << i << "\n";
   // recursive call
    for (int j = (i == 0)?1:0; j <= 9; j++)
     lexiographical_order(10*i+j,n);
   
}


/* given an unique string print its all permutations */
void permutations (string str,string prem,int& cn) {
   // base case
    if (str.length() == 0) {
        cout << prem << "\n";
        cn++;
        return;
    }
    unordered_set<char> s;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i]; // current character
        if (s.count(ch) == 0) { // if there are repeations we use set
            string ros = str.substr(0,i) + str.substr(i+1); // rest of string
            s.insert(ch);
            permutations (ros,prem + ch,cn);
        }
    }
}

// void permutations (string s, string osf) {
//     if (s.size() == 0) {
//         cout << osf << "\n";
//         return;
//     }
//     bitset<26> vis;
//     for (int i = 0; i < s.size(); i++) {
//         char ch = s[i];
//         if (vis[s[i] - 'a'] == 0) {
//             string ros = s.substr(0,i) + s.substr(i+1);
//             vis[ch -'a'] = 1;
//             permutations(ros,osf+ch); 
//         }
//     }
// }

int main () {
    // print_paths(1,1,3,3,"");
    // cout << cnt;
    // print_num_ways (1,3,"");
    // cout << total_ways << endl;
    // lexiographical_order (0,13);
    // permutations("12345678","",2);
    // cout << cnt;
    int cn = 0;
    permutations("123","",cn);
    cout << cn << endl;
}