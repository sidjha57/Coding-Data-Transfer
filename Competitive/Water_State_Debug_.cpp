#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,t;
    cin >> t;
    while (t--) {
        cin>>n>>k;
        vector<int>arr(n+1);
        for(int a=1;a<=n;a++)
        {
            cin>>arr[a];
        }
        vector<int>front(n+1,0);
        vector<int>back(n+1,0);
        front[k] = arr[k]; 
        front[k+1]= max(arr[k+1],arr[k]+arr[k+1]);
        for(int i=k+2;i<=n;i++)
        {
            front[i] = max(front[i-1],front[i-2]) + arr[i];
        }
        back[1]=arr[1];
        back[2]=max(arr[1],arr[1] + arr[2]);
        for(int i=3;i<=n;i++)
        {
            back[i] = max(back[i-1],back[i-2]) + arr[i];
        }
        int ans = 0;    
        for(int i=k;i<=n;i++)
        {
            ans=max(ans,front[i]+back[i]); 
        }
        cout<<ans<<endl;
    }
return 0;
}