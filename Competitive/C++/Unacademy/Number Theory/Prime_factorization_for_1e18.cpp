
// C++ program to count distinct divisors
// of a given number n
#include <bits/stdc++.h>
#define  ll long long int 
using namespace std;

 
void SieveOfEratosthenes(ll n, bool prime[],
                         bool primesquare[], ll a[])
{
     
    //For more details check out: https://www.geeksforgeeks.org/sieve-of-eratosthenes/
     
    // Create a boolean array "prime[0..n]" and
    // initialize all entries it as true. A value
    // in prime[i] will finally be false if i is
    // Not a prime, else true.
    for (ll i = 2; i <= n; i++)
        prime[i] = true;
 
    // Create a boolean array "primesquare[0..n*n+1]"
    // and initialize all entries it as false. A value
    // in squareprime[i] will finally be true if i is
    // square of prime, else false.
    for (ll i = 0; i <= (n * n + 1); i++)
        primesquare[i] = false;
 
    // 1 is not a prime number
    prime[1] = false;
 
    for (ll p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then
        // it is a prime
        if (prime[p] == true) {
            // Update all multiples of p starting from p * p
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    ll j = 0;
    for (ll p = 2; p <= n; p++) {
        if (prime[p]) {
            // Storing primes in an array
            a[j] = p;
 
            // Update value in primesquare[p*p],
            // if p is prime.
            primesquare[p * p] = true;
            j++;
        }
    }
}
 
// Function to count divisors
ll countDivisors(ll n)
{
    // If number is 1, then it will have only 1
    // as a factor. So, total factors will be 1.
    if (n == 1)
        return 1;
 
    bool prime[n + 1], primesquare[n * n + 1];
 
    ll a[n]; // for storing primes upto n
 
    // Calling SieveOfEratosthenes to store prime
    // factors of n and to store square of prime
    // factors of n
    SieveOfEratosthenes(n, prime, primesquare, a);
 
    // ans will contain total number of distinct
    // divisors
    ll ans = 1;
 
    // Loop for counting factors of n
    for (ll i = 0;; i++) {
        // a[i] is not less than cube root n
        if (a[i] * a[i] * a[i] > n)
            break;
 
        // Calculating power of a[i] in n.
        ll cnt = 1; // cnt is power of prime a[i] in n.
        while (n % a[i] == 0) // if a[i] is a factor of n
        {
            n = n / a[i];
            cnt = cnt + 1; // incrementing power
        }
 
        // Calculating the number of divisors
        // If n = a^p * b^q then total divisors of n
        // are (p+1)*(q+1)
        ans = ans * cnt;
    }
 
    // if a[i] is greater than cube root of n
 
    // First case
    if (prime[n])
        ans = ans * 2;
 
    // Second case
    else if (primesquare[n])
        ans = ans * 3;
 
    // Third case
    else if (n != 1)
        ans = ans * 4;
 
    return ans; // Total divisors
}
 
// Driver Program
int main()
{
    cout << "Total distinct divisors of 4606061759128693 are : "
         << countDivisors(4606061759128693) << endl;
    return 0;
}