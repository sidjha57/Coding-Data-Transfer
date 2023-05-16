#include<iostream>
#include<stack>
#include<string>
#include<string.h>

using namespace std;

string reverseWordsOfSentence(string sentence) {
    string str1;
    char str2[sentence.length()];
    stack <char> s1,s2;
    str1 = sentence;
    int i;

    for (i=0; i<sentence.length(); i++)
    s1.push(str1[i]);
    i=0;
    while (!s1.empty()) {
        if (s1.top() != ' ') {
            s2.push (s1.top());
            s1.pop();
            }
        else {
            s1.pop();
            while ( !s2.empty() ) {
                str2[i] = s2.top();
                s2.pop();
                i++;
            }
            str2[i++] = ' ';
        }

    }
    while ( !s2.empty() ) {
                str2[i] = s2.top();
                s2.pop();
                i++;
            }
            
    return str2;
}

int main () {
   cout << reverseWordsOfSentence("My name is Siddharth");
}

