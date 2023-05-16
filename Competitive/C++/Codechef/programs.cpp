#include <iostream>

using namespace std;


int main() {

    for (int i = 1; i <= 5; i++) {
        for (int j =1; j <= 9; j++) 
            (j>= (6-i) &&j <= (4+i)) ? cout <<"*" : cout <<" ";
            
        cout << endl;
    }

}

