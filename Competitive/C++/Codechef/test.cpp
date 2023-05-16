#include<iostream>
#include<stack>
#include<string>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack <char> s1;
        long int i;
        for (i=0;i<s.length();i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                s1.push (s[i]);
            }
            else if (!s1.empty()) 
            {
             if (s[i] == ')') {

             
                if (s1.top() == '(') s1.pop();
                
                else return false;
            }
             else if (s[i] == ']') {

               
                if (s1.top() == '[') s1.pop();
                
                
                else return false;
            }
             else if (s[i] == '}') {

                
                if (s1.top() == '{') s1.pop();
                
                
                else return false;
            }
        }
            else return false;
        }
        if (s1.empty())
        return true;

        else return false;
    }
};

int main () {
    Solution s2;
    cout << s2.isValid("]");

}