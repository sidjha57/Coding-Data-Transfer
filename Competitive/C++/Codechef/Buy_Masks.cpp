#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll MinimumCost(ll cost[], ll W)
{
    ll i,j,wt[3];
    wt[0]=10,wt[1]=5,wt[2]=1;
	ll min_cost[4][W+1];

	for ( i=0; i<=W; i++) min_cost[0][i] = INT_MAX;
	for ( i=1; i<=3; i++) min_cost[i][0] = 0;

	for ( i=1; i<=3; i++)
	
		for ( j=1; j<=W; j++)
		{
			if (wt[i-1] > j) min_cost[i][j] = min_cost[i-1][j];
			else min_cost[i][j] = min(min_cost[i-1][j],
			min_cost[i][j-wt[i-1]] + cost[i-1]);
		}
	return min_cost[3][W];
}

int main()
{
    ll t,W,cost[3],i;
    cin >> t;
    while (t--) {
        cin >> W;
        for (i=0; i <3;i++) cin >> cost[i];
	    cout << MinimumCost(cost, W) << "\n";
    }
	return 0;
}
