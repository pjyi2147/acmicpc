// acmicpc number: 13549
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    if (n == k)
    {
        cout << 0;
        return 0;
    }
    bool visited[100001];
    memset(visited, 0, sizeof(bool) * 100001);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    visited[n] = true;
    pq.push({0, n});
    while (!pq.empty())
    {
        auto cur = pq.top().second;
        auto t = pq.top().first;
        pq.pop();

        if (cur == k) 
        {
            cout << t << "\n";
            return 0;
        }

        if (cur * 2 < 100001 && !visited[cur * 2])
        {
            visited[cur * 2] = true;
            pq.push({t, cur * 2});
        }

        if (cur + 1 < 100001 && !visited[cur + 1])
        {
            visited[cur + 1] = true;
            pq.push({t + 1, cur + 1});
        }

        if (cur - 1 >= 0 && !visited[cur - 1])
        {
            visited[cur - 1] = true;
            pq.push({t + 1, cur - 1});
        }
    }
}