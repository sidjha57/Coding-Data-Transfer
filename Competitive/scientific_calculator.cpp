#include<bits/stdc++.h>
#define pi 3.1415926535897932384626433832795
using namespace std;
class calculator
{
public:
  struct var			//for those operations which will take two variable
  {
    int x, y;
  };
  float radians (float x)	//convert into radians such that in range of 0-360
  {
    int i;
    for (i = 1; i <= 100; i++)
      {
	if (x <= 360 && x >= 0)
	  {
	    break;
	  }
	if (x > 360)
	  {
	    x = x - 360;
	  }
	if (x < 0)
	  {
	    x = x + 360;
	  }
      }
    x = (x * pi) / 180;
    return x;
  }
  int fact (int n)		//get factorial
  {
    if (n == 0)
      {
	return 1;
      }
    else
      {
	return n * fact (n - 1);
      }
  }
  int p (int n)			//prime checker
  {
    int count = 0;
    for (int i = 2; i <= sqrt (n); i++)
      {
	if (n % i == 0)
	  {
	    count++;
	  }
	if (count == 1)
	  {
	    break;
	  }
      }
    return count;
  }
  int g (int i, int j)		//calculation of gcd by using the concept of recursion
  {
    if (j % i == 0)
      {
	return i;
      }
    else
      {
	return g (j % i, i);
      }
  }
  void gcd ()
  {
    cout << "Greatest Common Divisor Selected\n";
    struct var v;
    int a, b;
    cout << "\nEnter first number: ";
    cin >> v.x;
    cout << "Enter second number: ";
    cin >> v.y;
    v.x >= v.y ? a = v.y : b = v.y;	// normal if else statement,to define a as small among 2
    v.y > v.x ? a = v.x : b = v.x;
    cout << "The GCD of the two numbers is: " << g (a, b) << endl;
  }
  void lcm ()			//same as gcd except last step
  {
    cout << "Least Common Multiple Selected\n";
    struct var v;
    int a, b;
    cout << "\nEnter first number: ";
    cin >> v.x;
    cout << "Enter second number: ";
    cin >> v.y;
    v.x >= v.y ? a = v.y : b = v.y;
    v.y > v.x ? a = v.x : b = v.x;
    cout << "The LCM of the two numbers is: " << a * b / g (a, b) << endl;
  }
  void factorial ()
  {
    cout << "Factorial N! of a number Selected\n";
    int n;
    cout << "\nEnter the Number: ";
    cin >> n;
    cout << n << "! = " << fact (n) << endl;
  }
  void Combination ()		//to find nCr
  {
    cout << " Combinations nCr Selected\n";
    struct var v;
    cout << "\nEnter the value of n: ";
    cin >> v.x;
    cout << "Enter the value of r: ";
    cin >> v.y;
    cout << "The total number of Combinations are: " << fact (v.x) /
      (fact (v.x - v.y) * fact (v.y)) << endl;
  }
  void permutation ()		//to find nPr
  {
    cout << " Permutations nPr Selected\n";
    struct var v;
    cout << "\nEnter the value of n: ";
    cin >> v.x;
    cout << "Enter the value of r: ";
    cin >> v.y;
    cout << "The total number of Permutations are: " << fact (v.x) /
      fact (v.x - v.y);
  }
  void prime ()
  {
    cout << " Prime Checker Selected\n";
    int n;
    cout << "\nEnter the Number: ";
    cin >> n;
    if (n == 1)
      {
	cout << "The number is neither Prime nor Composite.";
      }
    else if (p (n) == 0)
      {
	cout << "\nThe Number is Prime.";
      }
    else
      {
	cout << "\nThe Number is Composite. \n";
      }
  }
  void coprime ()		//if gcd is 1, then the numbers are co-prime
  {
    cout << " Co-Prime Checker Selected\n";
    struct var v;
    cout << "\nEnter first number: ";
    cin >> v.x;
    cout << "Enter second number: ";
    cin >> v.y;
    if (g (v.x, v.y) == 1)
      {
	cout << "\nThe numbers are Co-Prime.";
      }
    else
      {
	cout << "\nThe numbers are't Co-Prime.";
      }
  }
  void siminterest ()
  {
    cout << " Simple Interest Selected\n";
    int p, n, r;
    float si;
    cout << "\nEnter Principal Amount: ";
    cin >> p;
    cout << "Enter Rate of Interest: ";
    cin >> r;
    cout << "Enter Number of Years: ";
    cin >> n;
    si = (p * r * n / 100);	//p*n*r/100
    cout << "The Simple Interest is:  " << si << endl;
  }
  void cominterest ()
  {
    cout << " Compound Interest Selected\n";
    float ci, p, n, r;
    cout << "Enter Principal Amount: ";
    cin >> p;
    cout << "Enter Rate of Interest: ";
    cin >> r;
    cout << "Enter Number of Years: ";
    cin >> n;
    ci = p * pow ((1 + r / 100), n) - p;	// a=p*(1+r/100)^n   ci=a-p
    cout << "The Compound Interest is:  " << ci;
  }
  float cos (int x)
  {
    int i = 1;
    float r, sum = 1, t0 = 1, t1, R;
    r = radians (x);
    do
      {
	R = -(r * r) / ((2 * i - 1) * (2 * i));
	t1 = R * t0;		//First term is 1, then -x^2/(2*1) and this would be multiplied again and again with the i increment
	sum = sum + t1;
	t0 = t1;
	i++;
      }
    while (abs (t1 / sum) > 0.00001);	//it gets a ratio between n and n-1 term and as the terms increase it gets closer to 0
    if (x % 90 == 0)		//as cos will be 0 at 90,270,450...
      {
	if (x % 180 != 0)
	  {
	    return 0;
	  }
	else
	  {
	    return sum;
	  }
      }
    return sum;
  }
  float sin (int x)
  {
    if (x % 180 == 0)		//0 at 0,180,360...
      {
	return 0;
      }
    int i = 2;
    float r, sum, t1, t2, R;
    r = radians (x);
    sum = r;
    t1 = r;
    do
      {
	R = -(r * r) / ((2 * i - 1) * (2 * i - 2));
	t2 = R * t1;
	sum = sum + t2;		//first term would be x-x3/3! than follow the same logic as cos
	t1 = t2;
	i++;
      }
    while (abs (t2 / sum) > 0.00001);	//used this so that output is in user readable format
    return sum;
  }
  void cos ()
  {
    cout << " Cosx Selected\n";
    int x;
    cout << "\nEnter the Angle (in Degrees): ";
    cin >> x;
    cout << "The value of Cos " << x << " is: " << cos (x) << endl;
  }
  void sec ()
  {
    cout << " Secx Selected\n";
    int x;
    cout << "\nEnter the Angle (in Degrees): ";
    cin >> x;
    if (cos (x) == 0)
      {
	cout << "The Sec function is undefined at x = " << x << "! " << endl;
      }
    else
      {
	cout << "The value of Sec " << x << " is: " << (1 / cos (x)) << endl;
      }
  }
  void sin ()
  {
    cout << " Sinx Selected\n";
    int x;
    cout << "\nEnter the Angle (in Degrees): ";
    cin >> x;
    cout << "The Value of Sin " << x << " is: " << sin (x) << endl;

  }
  void cosec ()
  {
    cout << " Cosecx Selected\n";
    int x;
    cout << "\nEnter the Angle (in Degrees): ";
    cin >> x;
    if (sin (x) == 0)
      {
	cout << "The Cosec function is undefined at x = " << x << "! " <<
	  endl;
      }
    else
      {
	cout << "The value of Cosec " << x << " is " << (1 / sin (x)) << endl;
      }
  }
  void tan ()
  {
    cout << " Tanx Selected\n";
    int x;
    cout << "\nEnter the Angle (in Degrees): ";
    cin >> x;
    if (x % 90 == 0)		//values where the Tan function is undefined and is equal to zero.
      {
	if (sin (x) == 0)
	  {
	    cout << "The value of Tan " << x << " is: 0" << endl;
	  }
	else
	  {
	    cout << "The Tan function is undefined at x = " << x << "! " <<
	      endl;
	  }
      }
    else
      {
	cout << "The value of Tan " << x << " is: " << (sin (x) /
							cos (x)) << endl;
      }
  }
  void cot ()
  {
    cout << " Cotx Selected\n";
    int x;
    cout << "\nEnter the Angle (in Degrees): ";
    cin >> x;
    if (x % 90 == 0)
      {
	if (cos (x) == 0)
	  {
	    cout << "The value of Cot " << x << " is: 0" << endl;
	  }
	else
	  {
	    cout << "The Cot function is undefined at x = " << x << "! " <<
	      endl;
	  }
      }
    else
      {
	cout << "The value of Cot " << x << " is: " << (cos (x) /
							sin (x)) << endl;
      }
  }
  float ex (float x)
  {
    int i = 1;
    float sum = 1, t1 = 1, t2, R;

    do
      {
	R = x / i;
	t2 = R * t1;
	sum = sum + t2;
	t1 = t2;
	i++;
      }
    while (abs (t2 / sum) > 0.0001);
    return sum;

  }
  float logx (float x)
  {
    if (x < 2)
      {
	int i = 2;
	float sum = x - 1, t1 = x - 1, t2, R;
	do
	  {
	    R = -(x - 1) / i;
	    t2 = R * t1;
	    sum = sum + t2;
	    t1 = t2;
	    t1 = t1 * i;	//as the denominator we get is factorial
	    i++;
	  }
	while (abs (t2 / sum) > 0.000001);
	return sum;
      }
    else
      {
	int i = 2;
	float sum = (x - 1) / x, t1 = (x - 1) / x, t2, R;
	do
	  {
	    R = (x - 1) / (x * i);
	    t2 = R * t1;
	    sum = sum + t2;
	    t1 = t2;
	    t1 = t1 * i;	//as the denominator we get is factorial
	    i++;
	  }
	while (abs (t2 / sum) > 0.000001);
	return sum;
      }

  }
  void lnx ()
  {
    cout << " Natural log ln x Selected\n";
    float x;
    cout << "\nEnter the Number: ";
    cin >> x;
    if (x > 0)
      {
	cout << "The Value of ln" << x << " is: " << logx (x) << endl;
      }
    else
      {
	cout << "The Logarithmic function is not defined at x = " << x <<
	  " !!" << endl;
      }
  }
  void log10x ()
  {
    cout << " Common log log10 x Selected\n";
    float x;
    cout << "\nEnter the Number: ";
    cin >> x;
    if (x > 0)
      {
	cout << "The Value of log" << x << " is: " << logx (x) /
	  logx (10) << endl;
      }
    else
      {
	cout << "The Logarithmic function is not defined at x = " << x <<
	  " !!" << endl;
      }
  }
  void logbx ()
  {
    cout << "  log base y logy x Selected\n";
    float x, b;
    cout << "\nEnter the Number: ";
    cin >> x;
    cout << "Enter the Base: ";
    cin >> b;
    if (x > 0 && b > 0 && b != 1)
      {
	cout << "The Value of log" << x << " base " << b << " is: " <<
	  logx (x) / logx (b) << endl;
      }
    else
      {
	cout << "The Logarithmic function is not defined at x = " << x <<
	  " !!" << endl;
      }
  }
  void ex ()
  {
    cout << " Exponential e^x Selected\n";
    float x;
    cout << "\nEnter the Power: " << endl;
    cin >> x;
    cout << "The Value of e^" << x << " is: " << ex (x) << endl;
  }
  void ax ()
  {
    cout << " Exponential a^x Selected\n";
    int x, a;
    float product = 1;
    cout << "\nEnter the Number: ";
    cin >> a;
    cout <<
      "Enter the Exponent(Please Enter exponents which are greater than 1): ";
    cin >> x;
    for (int i = 1; i <= x; i++)
      {
	product = product * a;
      }
    cout << "The Value of " << a << "^" << x << " is: " << product << endl;
  }
  void quad ()
  {
    cout << " Quadratic function ax^2 + bx +c = 0 type Selected\n";
    float a, b, c;
    float discriminant, realPart, imaginaryPart;
    cout << "\nEnter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    if (a == 0 && b == 0)
      {
	cout << "Not a valid quadratic equation.";
      }
    if (a == 0 && b != 0)
      {
	cout <<
	  "The equation is a linear equation in one variable and it's solution is: "
	  << c / b;
      }
    else
      {
	discriminant = (b * b) - (4 * a * c);
	if (discriminant > 0)
	  {
	    cout << "Roots are real and different." << endl;
	    cout << "Root 1 = " << (-b +
				    (sqrt (discriminant))) / (2 * a) << endl;
	    cout << "Root 2 = " << (-b -
				    (sqrt (discriminant))) / (2 * a) << endl;
	  }
	if (discriminant == 0)
	  {
	    cout << "Roots are real and same." << endl;
	    cout << "Root 1 = Root 2 =" << (-b +
					    (sqrt (discriminant))) / (2 *
								      a) <<
	      endl;
	  }
	if (discriminant < 0)
	  {
	    realPart = -b / (2 * a);
	    imaginaryPart = sqrt (-discriminant) / (2 * a);
	    cout << "Roots are complex and different." << endl;
	    cout << "Root 1 = " << realPart << " + " << imaginaryPart << " i"
	      << endl;
	    cout << "Root 2 = " << realPart << " - " << imaginaryPart << " i"
	      << endl;
	  }
      }
  }
  void matrix ()
  {
    cout << " Matrices Operations Selected\n";
    int M1[10][10], M2[10][10], operation[10][10];
    int r1, c1, r2, c2, i, j, k, choice;
    cout << "\nEnter Number of Rows in the First Matrix: ";
    cin >> r1;
    cout << "Enter Number of Columns in the First Matrix: ";
    cin >> c1;
    cout << "Enter Number of Rows in the Second Matrix: ";
    cin >> r2;
    cout << "Enter Number of Columns in the Second Matrix: ";
    cin >> c2;
    cout << "\nFor the First Matrix," << endl;
    for (i = 0; i < r1; i++)
      {
	for (j = 0; j < c1; j++)
	  {
	    cout << "Enter element a" << i + 1 << j + 1 << ": ";
	    cin >> M1[i][j];
	  }
      }
    cout << "\nFor the Second Matrix," << endl;
    for (i = 0; i < r2; i++)
      {
	for (j = 0; j < c2; j++)
	  {
	    cout << "Enter element b" << i + 1 << j + 1 << ": ";
	    cin >> M2[i][j];
	  }
      }
    cout << "\nThe Matrix A is: " << endl;
    for (i = 0; i < r1; i++)
      {
	for (j = 0; j < c1; j++)
	  {
	    cout << M1[i][j] << " ";
	  }
	cout << endl;
      }
    cout << "\nThe Matrix B is: " << endl;
    for (i = 0; i < r2; i++)
      {
	for (j = 0; j < c2; j++)
	  {
	    cout << M2[i][j] << " ";
	  }
	cout << endl;
      }
    cout << "\nYour Choices: " << endl;
    cout << "1 Add the two matrices." << endl;
    cout << "2 Subtract the second matrix from the first matrix." << endl;
    cout << "3 Subtract the first matrix from the second matrix." << endl;
    cout << "4 Multiply the two matrices (A*B)." << endl;
    cout << "5 Multiply the two matrices (B*A)." << endl;

    cout << "Enter choice: " << endl;
    cin >> choice;
    switch (choice)
      {
	// system ("clear");
      case 1:
	cout << " Addtion of two Matrices Selected" << endl;
	if (r1 != r2 || c1 != c2)
	  {
	    cout << "\nAddition can't be performed!!" << endl;
	    break;
	  }
	for (i = 0; i < r1; i++)
	  {
	    for (j = 0; j < c1; j++)
	      {
		operation[i][j] = M1[i][j] + M2[i][j];
	      }
	  }
	cout << "\nThe resultant matrix is: " << endl;
	for (i = 0; i < r1; i++)
	  {
	    for (j = 0; j < c1; j++)
	      {
		cout << operation[i][j] << " ";
	      }
	    cout << endl;
	  }
	break;
      case 2:
	cout <<
	  "Subtraction the second Matrix from the first Matrix Selected." <<
	  endl;
	if (r1 != r2 || c1 != c2)
	  {
	    cout << "\nSubtraction can't be performed!!" << endl;
	    break;
	  }
	for (i = 0; i < r1; i++)
	  {
	    for (j = 0; j < c1; j++)
	      {
		operation[i][j] = M1[i][j] - M2[i][j];
	      }
	  }
	cout << "\nThe resultant matrix is: " << endl;
	for (i = 0; i < r1; i++)
	  {
	    for (j = 0; j < c1; j++)
	      {
		cout << operation[i][j] << " ";
	      }
	    cout << endl;
	  }
	break;
      case 3:
	cout <<
	  " Subtraction the first Matrix from the second Matrix Selected." <<
	  endl;
	if (r1 != r2 || c1 != c2)
	  {
	    cout << "\nSubtraction can't be performed!!" << endl;
	    break;
	  }
	for (i = 0; i < r1; i++)
	  {
	    for (j = 0; j < c1; j++)
	      {
		operation[i][j] = M2[i][j] - M1[i][j];
	      }
	  }
	cout << "\nThe resultant matrix is: " << endl;
	for (i = 0; i < r1; i++)
	  {
	    for (j = 0; j < c1; j++)
	      {
		cout << operation[i][j] << " ";
	      }
	    cout << endl;
	  }
	break;
      case 4:
	cout << "Multiplication of the two matrices (A*B) Selected." << endl;
	if (c1 != r2)
	  {
	    cout << "\nInvalid matrix multiplication operation!!!";
	    break;
	  }
	for (i = 0; i < r1; i++)
	  {
	    for (j = 0; j < c2; j++)
	      {
		operation[i][j] = 0;
		for (k = 0; k < c1; k++)
		  {
		    operation[i][j] += M1[i][k] * M2[k][j];	//where, += is the add and assign operator i.e it adds RHS and LHS and then assigns it to LHS
		  }
	      }
	  }
	cout << "\nThe resultant matrix is: " << endl;
	for (i = 0; i < r1; i++)
	  {
	    for (j = 0; j < c2; j++)
	      {
		cout << operation[i][j] << " ";
	      }
	    cout << endl;
	  }
	break;
      case 5:
	cout << "Multiplication of the two matrices (B*A) Selected." << endl;
	if (c2 != r1)
	  {
	    cout << "\nInvalid matrix multiplication operation!!!";
	    break;
	  }
	for (i = 0; i < r2; i++)
	  {
	    for (j = 0; j < c1; j++)
	      {
		operation[i][j] = 0;
		for (k = 0; k < c2; k++)
		  {
		    operation[i][j] += M2[i][k] * M1[k][j];
		  }
	      }
	  }
	cout << "\nThe resultant matrix is: " << endl;
	for (i = 0; i < r2; i++)
	  {
	    for (j = 0; j < c1; j++)
	      {
		cout << operation[i][j] << " ";
	      }
	    cout << endl;
	  }
	break;

      default:
	cout << "Entered choice is invalid!! Please try again." << endl;
	break;
      }
  }
  struct complex_number
  {
  public:float x, y;
  };
  void complex ()
  {
    cout << " Complex Numbers a+bi Operations Selected\n";
    int choice;
    struct complex_number N1, N2, operation;
    //getting the value of first complex number from user
    cout << "\nEnter the real part of the first complex number: ";
    cin >> N1.x;
    cout << "Enter the imaginary part of the first complex number: ";
    cin >> N1.y;
    //displaying the first complex number
    if (N1.y >= 0)
      cout << "\nThe first complex number is: " << N1.x << " + " << N1.
	y << "i" << endl;
    else
      cout << "\nThe first complex number is: " << N1.x << " " << N1.
	y << "i" << endl;
    //getting the value of second complex number from user
    cout << "\nEnter the real part of the second complex number: ";
    cin >> N2.x;
    cout << "Enter the imaginary part of the second complex number: ";
    cin >> N2.y;
    //displaying the second complex number
    if (N2.y >= 0)
      cout << "\nThe second complex number is: " << N2.x << " + " << N2.
	y << "i" << endl;
    else
      cout << "\nThe second complex number is: " << N2.x << " " << N2.
	y << "i" << endl;

    cout << " Add the two complex numbers, PRESS 1" << endl;
    cout << " Subtract the second complex number from the first, PRESS 2" <<
      endl;
    cout << " Subtract the first complex number from the second, PRESS 3" <<
      endl;
    cout << " Multiply the two complex numbers, PRESS 4" << endl;
    cout << " Divide the first complex number by the second, PRESS 5" << endl;
    cout << " Divide the second complex number by the first, PRESS 6" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    switch (choice)
      {
	// system ("clear");
      case 1:
	cout << " Addtion of the two complex numbers Selected." << endl;	//displaying the sum of complex numbers
	operation.x = N1.x + N2.x;
	operation.y = N1.y + N2.y;
	if (operation.y >= 0)
	  cout << "\nSum of the two complex numbers is: " << operation.x <<
	    " + " << operation.y << "i" << endl;
	else
	  cout << "\nSum of the two complex numbers is: " << operation.x <<
	    " - " << operation.y << "i" << endl;
	break;
      case 2:
	cout << " Subtraction of the second complex number from the first." << endl;	//displaying the difference between the complex numbers
	operation.x = N1.x - N2.x;
	operation.y = N1.y - N2.y;
	if (operation.y >= 0)
	  cout << "\nDifference of the two complex numbers is: " <<
	    operation.x << " + " << operation.y << "i" << endl;
	else
	  cout << "\nDifference of the two complex numbers is: " <<
	    operation.x << " " << operation.y << "i" << endl;
	break;
      case 3:
	cout << " Subtraction of the first complex number from the second Selected." << endl;	//displaying the difference between the complex numbers
	operation.x = N2.x - N1.x;
	operation.y = N2.y - N1.y;
	if (operation.y >= 0)
	  cout << "\nDifference of the two complex numbers is: " <<
	    operation.x << " + " << operation.y << "i" << endl;
	else
	  cout << "\nDifference of the two complex numbers is: " <<
	    operation.x << " " << operation.y << "i" << endl;
	break;
      case 4:
	cout << "Multiplication the two complex numbers Selected." << endl;	//displaying the product of the two complex numbers
	operation.x = (N1.x) * (N2.x) - (N1.y) * (N2.y);
	operation.y = (N1.x) * (N2.y) + (N1.y) * (N2.x);
	if (operation.y >= 0)
	  cout << "\nProduct of the two complex numbers is: " << operation.x
	    << " + " << operation.y << "i" << endl;
	else
	  cout << "\nProduct of the two complex numbers is: " << operation.x
	    << " " << operation.y << "i" << endl;
	break;
      case 5:
	cout << " Division OF the first complex number by the second Selected" << endl;	//displaying the quotient when the first complex number is divided by the second
	operation.x =
	  ((N1.x) * (N2.x)) + ((N1.y) * (N2.y)) / (pow (N2.x, 2) +
						   pow (N2.y, 2));
	operation.y =
	  ((N2.x) * (N1.y)) - ((N1.x) * (N2.y)) / (pow (N2.x, 2) +
						   pow (N2.y, 2));
	if (operation.y >= 0)
	  cout <<
	    "\nDivision of the first complex number by the second gives: " <<
	    operation.x << " + " << operation.y << "i" << endl;
	else
	  cout <<
	    "\nDivision of the first complex number by the second gives: " <<
	    operation.x << " " << operation.y << "i" << endl;
	break;
      case 6:
	cout << " Division of the second complex number by the first Selected" << endl;	//displaying the quotient when the second complex number is divided by the first
	operation.x =
	  ((N1.x) * (N2.x)) +
	  ((N1.y) * (N2.y)) / float ((pow (N1.x, 2) + pow (N1.y, 2)));
	operation.y =
	  ((N2.x * N1.y) - (N1.x * N2.y)) / (pow (N1.x, 2) + pow (N1.y, 2));
	if (operation.y >= 0)
	  cout <<
	    "\nDivision of the second complex number by the first gives: " <<
	    operation.x << " + " << operation.y << "i" << endl;
	else
	  cout <<
	    "\nDivision of the second complex number by the first gives: " <<
	    operation.x << " " << operation.y << "i" << endl;
	break;
      default:
	cout << "\nInvalid Option Entered!!!" << endl;
	break;
      }
  }
  void linear ()
  {
    cout << " linear equations of n variables ax1+bx2+cx3...=y Selected\n";
    int i, j, k, n;
    char f;
    cout <<
      "\nEnter the number of variables (Please note that the calculator only supports equations with unique solutions right now!): ";
    cin >> n;
    float a[n][n + 1], c, x[n];
    for (i = 1; i <= n; i++)
      {
	f = 'a';
	cout << "\nEnter the constants of " << " equation " << i << ":" <<
	  endl;
	for (j = 1; j <= (n + 1); j++)
	  {
	    cout << f << i << " = ";
	    cin >> a[i][j];
	    f++;
	  }
      }
    // Now finding the elements of diagonal matrix
    for (j = 1; j <= n; j++)	//subtracting rows from each other
      {
	for (i = 1; i <= n; i++)
	  {
	    if (i != j)
	      {
		c = a[i][j] / a[j][j];
		for (k = 1; k <= n + 1; k++)
		  {
		    a[i][k] = a[i][k] - c * a[j][k];
		  }
	      }
	  }
      }
    cout << "\nThe solutions are:\n";
    for (i = 1; i <= n; i++)
      {
	x[i] = a[i][n + 1] / a[i][i];
	cout << "x" << i << " = " << x[i] << endl;
      }
  }
void determinant ()
  {
    cout << "Evaluation of N order Determinants Selected " << endl;
    int i, k, n, j, count;
    static int l = 0;
    bool flag1 = false;
    char f = 'a';
    cout << "\nEnter the order of Determinant: ";
    cin >> n;
    float a[n][n], c, d = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << "Enter element " << f << i << j << " = ";
            cin >> a[i][j];
        }
    }
    cout << "\nThe Determinant entered is: \n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    // Now finding the elements of diagonal matrix
    for (j = 1; j <= n; j++)	//subtracting rows from each other
    {
        for (i = 1; i <= n; i++)
        {
            count = 0;
            if (i != j)
            {
                c = a[i][j] / a[j][j];
                for (k = 1; k <= n; k++)
                {
                    a[i][k] = a[i][k] - c * a[j][k];
                }

                for (k = 1; k <= n; k++)
                {
                    if (a[i][k] == 0)
                    {
                    count++;
                    }
                    if (count == n)
                    {
                    cout << "\nThe solution is:  0 ";
                    flag1 = true;
                    break;
                    }
                }
            }
            
            if (flag1)
            {
                break;
            }
        }
	    if (flag1)
        {
            break;
        }

    }

    if (j == n + 1)
    {
        for (i = 1; i <= n; i++)
        {
            d = d * a[i][i];
        }
        cout << "The solution is: " << d << endl;
    }
}
  void arithmetic ()
  {
    cout << " Basic Arithmetic Operations Selected" << endl;
    static float ans = 1;
    float a, b;
    static char o;
    cout <<
      "\nPress Enter after each operation and if you want to terminate the program, PRESS 0 TWICE (performs ' + ',' - ',' / ',' * '):\n";
    cin >> a;
    cin >> o;
    switch (o)
      {
      case '/':
	cin >> b;
	ans = a / b;
	break;
      case '*':
	cin >> b;
	ans = a * b;
	break;
      case '+':
	cin >> b;
	ans = a + b;
	break;
      case '-':
	cin >> b;
	ans = a - b;
	break;
      }
    cout << ans;
    cin >> o;
    while (o)
      {
	switch (o)
	  {
	  case '/':
	    cin >> b;
	    ans = ans / b;
	    cout << ans;
	    break;
	  case '*':
	    cin >> b;
	    ans = ans * b;
	    cout << ans;
	    break;
	  case '+':
	    cin >> b;
	    ans = ans + b;
	    cout << ans;
	    break;
	  case '-':
	    cin >> b;
	    ans = ans - b;
	    cout << ans;
	    break;
	  }
	cin >> o;
	if (o == '0')
	  {
	    break;
	  }
      }
    cout << "\nThe Final Answer is : " << ans;
  }
};

int
main ()
{
  calculator s;
  static int w;
  cout <<
    "Hello Dear User! We welcome you to our Scientific Calculator and we encourage you \n to explore all the components this Calculator has to offer."
    << endl;
  cout << "\n1.  To Perform basic Arithmetical operations, PRESS 1\n" <<
    "2.  To Calculate GCD or LCM, PRESS 2\n" <<
    "3.  To Calculate Combinatorial functions, PRESS 3\n" <<
    "4.  To Check if numbers are Prime/Co-Prime, PRESS 4\n" <<
    "5.  To Find Interest (Both Simple and Compound), PRESS 5\n" <<
    "6.  To Calculate Trigonometric functions, PRESS 6 \n" <<
    "7.  To Calculate Exponential functions, PRESS 7 \n" <<
    "8.  To Calculate Logarithmic functions, PRESS 8\n" <<
    "9.  To Solve Quadratic Equations, PRESS 9\n" <<
    "10. To Solve Linear Equations, PRESS 10\n" <<
    "11. To Perform operations on Matrices, PRESS 11 \n" <<
    "12. To Find the value of a Determinant, PRESS 12\n" <<
    "13. To Perform operations on Complex Numbers, PRESS 13\n" <<
    "14.  To Exit, PRESS 0\n";

  cin >> w;
  while (w)
    {


      switch (w)
	{
	case 1:
	  system ("clear screen");
	  s.arithmetic ();
	  break;
	case 2:
	  system ("clear screen");
	  cout << "\n1. To Calculate GCD, PRESS 1\n" <<
	    "2. To Calculate LCM, PRESS 2\n";
	  cin >> w;
	  system ("clear screen");
	  switch (w)
	    {
	    case 1:
	      s.gcd ();
	      break;
	    case 2:
	      s.lcm ();
	      break;
	    default:
	      cout << "Invalid Choice Entered!!!" << endl;
	      break;
	    }
	  break;
	case 3:
	  system ("clear screen");
	  cout << "\n1. To Calculate the Factorial of a number, PRESS 1" <<
	    "\n2. To Calculate the number of Combinations, PRESS 2" <<
	    "\n3. To Calculate the number of Permutations, PRESS 3" << endl;
	  cin >> w;
	  system ("clear screen");
	  switch (w)
	    {
	    case 1:
	      s.factorial ();
	      break;
	    case 2:
	      s.Combination ();
	      break;
	    case 3:
	      s.permutation ();
	      break;
	    default:
	      cout << "Invalid Choice Entered!!!" << endl;
	      break;
	    }
	  break;
	case 4:
	  system ("clear screen");
	  cout << "\n1. To Check if a number is Prime, PRESS 1" <<
	    "\n2. To Check if 2 numbers are Co-Prime, PRESS 2" << endl;
	  cin >> w;
	  system ("clear screen");
	  switch (w)
	    {
	    case 1:
	      s.prime ();
	      break;
	    case 2:
	      s.coprime ();
	      break;
	    default:
	      cout << "Invalid Choice Entered!!!" << endl;
	      break;
	    }
	  break;
	case 5:
	  system ("clear screen");
	  cout << "\n1. To Calculate the Simple Interest, PRESS 1" <<
	    "\n2. To Calculate the Compound Interest, PRESS 2" << endl;
	  cin >> w;
	  system ("clear screen");
	  switch (w)
	    {
	    case 1:
	      s.siminterest ();
	      break;
	    case 2:
	      s.cominterest ();
	      break;
	    default:
	      cout << "Invalid Choice Entered!!!" << endl;
	      break;
	    }
	  break;
	case 6:
	  system ("clear screen");
	  cout << "\n1. To Calculate Sin x, PRESS 1\n" <<
	    "2. To Calculate Cos x, PRESS 2\n" <<
	    "3. To Calculate Tan x, PRESS 3\n" <<
	    "4. To Calculate Cot x, PRESS 4\n" <<
	    "5. To Calculate Cosec x, PRESS 5\n" <<
	    "6. To Calculate Sec x, PRESS 6\n";
	  cin >> w;
	  system ("clear screen");
	  switch (w)
	    {
	    case 1:
	      s.sin ();
	      break;
	    case 2:
	      s.cos ();
	      break;
	    case 3:
	      s.tan ();
	      break;
	    case 4:
	      s.cot ();
	      break;
	    case 5:
	      s.cosec ();
	      break;
	    case 6:
	      s.sec ();
	      break;
	    default:
	      cout << "Invalid Choice Entered!!!" << endl;
	      break;
	    }
	  break;
	case 7:
	  system ("clear screen");
	  cout << "\n1. To Calculate e^x, PRESS 1\n" <<
	    "2. To Calculate a^x, PRESS 2\n";
	  cin >> w;
	  system ("clear screen");
	  switch (w)
	    {
	    case 1:
	      s.ex ();
	      break;
	    case 2:
	      s.ax ();
	      break;
	    default:
	      cout << "Invalid Choice Entered!!!" << endl;
	      break;
	    }
	  break;
	case 8:
	  system ("clear screen");
	  cout << "\n1. To Calculate Natural Logarithm(base e), PRESS 1" <<
	    "\n2. To Calculate Common Logarithm(base 10), PRESS 2" <<
	    "\n3. To calculate Logarithm for a base of your choice, PRESS 3\n";
	  cin >> w;
	  system ("clear screen");
	  switch (w)
	    {
	    case 1:
	      s.lnx ();
	      break;
	    case 2:
	      s.log10x ();
	      break;
	    case 3:
	      s.logbx ();
	      break;
	    default:
	      cout << "Invalid Choice Entered!!!" << endl;
	      break;
	    }
	  break;
	case 9:
	  system ("clear screen");
	  s.quad ();
	  break;
	case 10:
	  system ("clear screen");
	  s.linear ();
	  break;
	case 11:
	  system ("clear screen");
	  s.matrix ();
	  break;
	case 12:
	  system ("clear screen");
	  s.determinant ();
	  break;
	case 13:
	  system ("clear screen");
	  s.complex ();
	  break;
	default:
	  cout << "Invalid Choice Entered!!!" << endl;
	  break;
	}

      cout << "\n1.  To Perform basic Arithmetical operations, PRESS 1\n" <<
	"2.  To Calculate GCD or LCM, PRESS 2\n" <<
	"3.  To Calculate Combinatorial functions, PRESS 3\n" <<
	"4.  To Check if numbers are Prime/Co-Prime, PRESS 4\n" <<
	"5.  To Find Interest (Both Simple and Compound), PRESS 5\n" <<
	"6.  To Calculate Trigonometric functions, PRESS 6 \n" <<
	"7.  To Calculate Exponential functions, PRESS 7 \n" <<
	"8.  To Calculate Logarithmic functions, PRESS 8\n" <<
	"9.  To Solve Quadratic Equations, PRESS 9\n" <<
	"10. To Solve Linear Equations, PRESS 10\n" <<
	"11. To Perform operations on Matrices, PRESS 11 \n" <<
	"12. To Find the value of a Determinant, PRESS 12\n" <<
	"13. To Perform operations on Complex Numbers, PRESS 13\n" <<
	"14.  To Exit, PRESS 0\n";
      cin >> w;
    }
  cout <<
    "\nThank you for using our calculator!! We hope you enjoyed the experience!!";
}
