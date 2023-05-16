#include <iostream>

using namespace std;

int main () {
    int temp,num,a=1234;

    while (a%10 != 0) {
         temp = a % 10;
         a = a/10;
         num = num*10 + temp;
    }
    cout << num;
}