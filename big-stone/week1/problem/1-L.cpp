#include <bits/stdc++.h>
using namespace std;
int n,m, dat[15001], cnt;

void combi(int idx, vector<int> &v)
{
    if (v.size() == 2)
    {
        int a = v[0], b = v[1];
        if (a+b == m)
        {
            cnt++;
            return;
        }
    }
    for (int i = idx+1; i<n; i++)
    {
        v.emplace_back(dat[i]);
        combi(i,v);
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> dat[i];
    vector<int> v;
    combi(-1,v);
    cout << cnt << "\n";
    return 0;
}
