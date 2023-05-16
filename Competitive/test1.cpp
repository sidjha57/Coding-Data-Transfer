#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(string& s) {
    int num = 0, pow_2=1;
    for (int i=s.size()-1; i>=0; i--) {
        if (s[i] == '1') num += pow_2;
        pow_2 *= 2;
    }
    return num;
}

int largestDeadlyDivisor(int A) {
    string s = "1";
    vector<int> div;
    div.push_back(1);
    while (div.back() <= 100000) {
        s.insert(0,"1");
        s.push_back('0');
        div.push_back(binaryToDecimal(s));
    }
    for (int i=0; i<div.size(); i++) {
        cout << div[i] <<" ";
    }
    cout <<"\n";
    for (int i=div.size()-1; i>=0; i--) {
        if (A%div[i] == 0) {
            return div[i];
        }
    }
    return 1;
}


int braces(string a) {
    stack<pair<char,bool>> st;
    int redundantCnt = 0;
    for (int i=0; i<a.size(); i++) {
        if (a[i] == '(') {
            st.push({'(',0});
        } else if (a[i] == ')') {
            if (st.top().second == 0)  redundantCnt++;
            st.pop();
        } else {
            st.top().second = 1;
        }
    } 
    return redundantCnt;
}

int main() {
    // cout << largestDeadlyDivisor(100000);
    cout << braces("(((a+b)))");
    return 1;
}