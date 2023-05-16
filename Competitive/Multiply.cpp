#include <bits/stdc++.h>
using namespace std;

int main()
{

	string num1, num2; cin >> num1 >> num2;
    bool isNum1_neg=0, isNum2_neg=0;
    if (num1[0] == '-') {
        isNum1_neg = 1;
        num1 = num1.substr(1);
    }
    if (num2[0] == '-') {
        isNum2_neg = 1;
        num2 = num2.substr(1);
    } 

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	vector<int> mul(num1.length() + num2.length());
	for (int i = 0; i < num1.length(); i++) {
		for (int j = 0; j < num2.length(); j++) {
			mul[i + j]
				= mul[i + j] + (num1[i] - '0') * (num2[j] - '0');
		}
	}

	string product = "";

	for (int i = 0; i < mul.size(); i++) {
		int digit = mul[i] % 10;
		int carry = mul[i] / 10;
		if (i + 1 < mul.size()) {
			mul[i + 1] = mul[i + 1] + carry;
		}
		product = to_string(digit) + product;
	}
	while (product.length() > 1 && product[0] == '0') {
		product = product.substr(1);
	}

	if (isNum1_neg && !isNum2_neg || (!isNum1_neg && isNum2_neg)) 
        cout << "-" << product;
    else 
	    cout << product;
}

