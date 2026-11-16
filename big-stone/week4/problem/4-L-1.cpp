//
// Created by 5600G on 2026-11-13.
//
#include <bits/stdc++.h>
using namespace std;

int T, N,x;
string oper,dat;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastIO();
    cin >> T;

    while (T--)
    {
        cin >> oper >> N >> dat;
        deque<int> dq;
        x = 0;

        for (char c : dat)
        {
            if (c == '[' || c == ']') continue;
            else if (c >= '0' && c <='9') x = x * 10 + (c - '0');
            else
            {
                if (x > 0)
                {
                    dq.emplace_back(x);
                }
                x = 0;
            }
        }
        if (x > 0) dq.emplace_back(x);

        bool error = false, rev = false;
        for (char op : oper)
        {
            if (op == 'R') rev = !rev;
            if (op == 'D')
            {
                if (dq.empty())
                {
                    error = true;
                    break;
                }
                if (rev) dq.pop_back();
                else dq.pop_front();
            }
        }

        if (error) cout << "error" << "\n";
        else
        {
            cout << "[";
            // if (rev)
            // {
            //     for (int i=dq.size()-1; i>=0; i--)
            //     {
            //         cout << dq[i];
            //         if (i != 0) cout << ",";
            //     }
            // }
            // else
            // {
            //     for (int i=0; i<dq.size(); i++)
            //     {
            //         cout << dq[i];
            //         if (i != dq.size()-1) cout << ",";
            //     }
            // }
            if (rev) reverse(dq.begin(),dq.end());

            for (int i=0; i<dq.size(); i++)
            {
                cout << dq[i];
                if (i != dq.size() -1) cout << ',';
            }
            cout << "]" << "\n";
        }
    }
    return 0;
}
