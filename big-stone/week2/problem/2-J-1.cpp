//
// Created by 5600G on 2026-08-10.
//
#include <bits/stdc++.h>
using namespace std;

int n,m, arr[101][101];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        cin >> s;
        for (int j=0; j<m; j++)
        {
            if (s[j] == '.') arr[i][j] = -1;
            else arr[i][j] = 0;
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (arr[i][j] == 0)
            {
                int cnt = 1;
                while (arr[i][j+1] == -1)
                {
                    arr[i][j+1] = cnt++;
                    j++;
                }
            }
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
