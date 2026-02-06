//
// Created by 5600G on 2026-02-06.
//
/** @see https://www.acmicpc.net/problem/5419
 * 펜윅트리 + 라인 스위핑 (조합찾기) + 좌표 압축
 * 펜윅트리 이용하여 하위 정보 카운트
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> tree, _y;
vector<pair<int,int>> islands;
int n,x,y,t;

void update(int index, int val)
{
    while (index < tree.size())
    {
        tree[index] += val;
        index+=(index & -index);
    }
}

int sum(int index)
{
    int ret = 0;
    while (index >0)
    {
        ret += tree[index];
        index -= (index & -index);
    }
    return ret;
}

int find_index(const vector<int> &compressed_y, int val)
{
    int left = 0, right = compressed_y.size()-1;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (compressed_y[mid] < val) left = mid + 1;
        else if (compressed_y[mid] == val) return mid;
        else right = mid - 1;
    }
}

int main()
{   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        // 초기화
        cin >> n;
        islands.clear(); _y.clear(); tree.clear();
        tree.resize(n+1, 0);

        for (int i=0; i<n; i++)
        {
            cin >> x >> y;
            islands.emplace_back(x,y * -1); // 라인 스위핑을 원활하게 하기 위해 -1을 곱해서 남쪽으로 이동하는 경우를 오름차순으로 정리
            _y.emplace_back(y* -1);
        }
        sort(islands.begin(), islands.end());
        sort(_y.begin(), _y.end()); // 좌표 압축

        ll ret = 0;
        update(find_index(_y,islands[0].second) + 1, 1);
        for (int i=1; i<n; i++)
        {
            int index = find_index(_y, islands[i].second) + 1;
            ret += 1LL * sum(index);
            update(index, 1);
        }
        cout << ret << "\n";
    }
    return 0;
}
