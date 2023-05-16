#include <iostream>

using namespace std;

void print (int row,int column) {
    for (int i=0; i<=row; i++) {
        for (int j=0; j<i; j++)
            cout <<"*";
        cout << "\n";
    }  
}

int main () {
    int N,M;
    cin >> N >> M;
    print(N,M);
}