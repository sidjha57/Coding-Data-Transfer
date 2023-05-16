// C++ program to find prime factorization of a
// number n in O(Log n) time with precomputation
// allowed.
#include "bits/stdc++.h"
#define ll long long
using namespace std;

#define MAXN 100001

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
	spf[1] = 1;
	for (int i=2; i<MAXN; i++)

		// marking smallest prime factor for every
		// number to be itself.
		spf[i] = i;

	// separately marking spf for every even
	// number as 2
	for (int i=4; i<MAXN; i+=2)
		spf[i] = 2;

	for (int i=3; i*i<MAXN; i++)
	{
		// checking if i is prime
		if (spf[i] == i)
		{
			// marking SPF for all numbers divisible by i
			for (int j=i*i; j<MAXN; j+=i)

				// marking spf[j] if it is not
				// previously marked
				if (spf[j]==j)
					spf[j] = i;
		}
	}
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
ll getFactorization(ll x,ll y)
{
	unordered_map<ll,ll> map;
    ll product=1;
	while (x != 1)
	{
        if (y%spf[x]==0)
		map[spf[x]]++;
      
		x = x / spf[x];
	}
    for (auto x: map) {
        product *= (x.second+1);
    }
	return product;
}

// driver program for above function
int main()
{
	// precalculating Smallest Prime Factor
	sieve();
	int x = 0,y=80;
	ll p = getFactorization(x,y);

	cout << p;
	return 0;
}
