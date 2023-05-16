#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define _sort(x) sort(all(x))
#define __sort(x, y) sort(all(x), y)
#define vi vector<int>
#define vl vector<ll>
#define loop(i, N) for (int i = 0; i < N; i++)
#define _loop(i, x, N) for (int i = x; i < N; i++)
#define __loop(i, x, N, y) for (int i = x; i < N; i += y)
#define mod 1000000007

int main()
{
    int N;
    cin >> N;
    if (N == 0) {
        cout << "E";
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        char ch = (N - 1) % 26 + 'E';
        for (int j = 0; j < i; j++)
        {
            cout << ch-- << ' ';
            if (ch < 'A')
                ch = 'Z';
        }
        for (int j = i; j < N; j++)
            cout << ch << ' ';

        for (int j = i; j < N - 1; j++)
            cout << ch << ' ';

        for (int j = 0; j < i; j++)
        {
            if (ch == 'Z')
                ch = 'A' - 1;
            cout << ++ch << ' ';
        }
        cout << endl;
    }

    for (int i = N - 2; i >= 0; i--)
    {
        char ch = (N - 1) % 26 + 'E';

        for (int j = 0; j < i; j++)
        {
            cout << ch-- << ' ';
            if (ch < 'A')
                ch = 'Z';
        }
        for (int j = i; j < N; j++)
            cout << ch << ' ';

        for (int j = i; j < N - 1; j++)
            cout << ch << ' ';

        for (int j = 0; j < i; j++)
        {
            if (ch == 'Z')
                ch = 'A' - 1;
            cout << ++ch << ' ';
        }
        cout << endl;
    }
}