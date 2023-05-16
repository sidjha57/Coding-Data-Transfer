#include <iostream>

using namespace std;

int main() {
    char book_name1, book_name2;
    int price_of_book1, price_of_book2;

    cin >> book_name1 >>price_of_book1 >> book_name2 >> price_of_book2;

    if (price_of_book1 == price_of_book2) {
        if (book_name1 < book_name2) 
            cout << book_name1 << " " << book_name2;
        else
            cout << book_name2 << " " << book_name1;
    }

    else if (price_of_book1 > price_of_book2) 
        cout << book_name1 << " " << book_name2;
    
    else 
        cout << book_name2 << " " << book_name1;
    
    return 0;
}