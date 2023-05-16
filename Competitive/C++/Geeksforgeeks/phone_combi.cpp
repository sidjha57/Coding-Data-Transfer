#include <bits/stdc++.h>
using namespace std;

//phone number
vector<string> solve(string digits) {
    string letters[9] = {"1","abc",  "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};    
    vector<string> list;
    queue<string> q;
    q.push("");
 
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        if (s.size() == digits.size())
            list.push_back(s);
        else
            for (auto alpha : letters[digits[s.size()] - '1'])
                q.push(s + alpha);
    }
    return list;
}

// phone number
map<int,string > m;
void generate(int pos, string s,string& digits, vector<string>& ans)
{
    if(pos==digits.size())
    {
        ans.push_back(s);
        return;
    }
    int cd = digits[pos] - '0';
    for(int i=0;i<m[cd].size();i++)
    {
        if(pos!=0 and s.size()==0) return;
        s+=m[cd][i]; 
        generate(pos+1,s,digits,ans); 
        s.pop_back(); 
        //handle extra answers getting pushed
    }
}

vector<string> solve(string digits) {
    vector<string> ans;
    string s;
    
    int cc = 0;
    for(int i=2;i<=9;i++)
    {
        for(int j=0;j<3;j++,cc++)
        {
            m[i].push_back('a'+cc);
            if(i==7 and j==2) {cc++;m[i].push_back('a'+cc);}
        }
            
    }
    m[9].push_back('z');
    generate(0,s,digits,ans);
    // for(auto st:a) ans.push_back(st);
    return ans;
}   

// largest rectangle area
int find_ans(vector <int> nums)
{
    int n = nums.size();
    vector <int> nse(n,n);
    vector <int> pse(n,-1);
    stack <int> s;
    s.push(n-1);


// [2,0,1,1]
// [2,0,2,2]

    for(int i = n-2; i >= 0; i--)
    {
        while(!s.empty() && nums[i] <= nums[s.top()])
        {
            s.pop();
        }
        if(!s.empty())
        {
            nse[i] = s.top();
        }
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    
    s.push(0);
    for(int i = 1; i < n; i++)
    {
        while(!s.empty() && nums[i] <= nums[s.top()])
        {
            s.pop();
        }
        if(!s.empty())
        {
            pse[i] = s.top();
        }
        s.push(i);
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, (nse[i] - pse[i] -1)*nums[i]);
    }
    return ans;

}

int solve(vector<vector<int>>& matrix) {
    int n = matrix.size(); 
    int m = matrix[0].size();
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        vector <int> v = matrix[i];
        ans = max(ans,find_ans(v));
        
        if(i +1< n)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] != 0 && matrix[i+1][j] != 0)
                {
                    matrix[i+1][j] += matrix[i][j];
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<string> list;
    list = solve("23");
    for (auto word : list) 
        cout << word << " ";
    return 0;
}


