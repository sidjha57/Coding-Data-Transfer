#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)

    {

        int n,x,y,k;

        cin>>n>>x>>y>>k;

        set<int> A;

        set<int> arr;

        for(int i=0;i<n;++i)

        {

            int c;

            cin>>c;

            if(c>=x && c<=y)

                A.insert(c);

            arr.insert(c);

        }

        int colour_choice = y-x+1-A.size();

        int distincts = n-arr.size();

        int changes = min(k,distincts);

        int ans = arr.size() + min(changes,colour_choice);

        cout<<ans<<"\n";

    }

    return 0;

}