// acmicpc number: 24445
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m, r;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> r;

    vector<int> visited(n+1, 0);
    vector<priority_queue<int>> node(n+1, priority_queue<int>());

    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        node[s].push(e);
        node[e].push(s);
    }

    int d = 1;
    queue<int> q;
    visited[r] = d++;
    q.push(r);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        while (!node[u].empty())
        {
            int t = node[u].top();
            node[u].pop();
            if (visited[t] == 0)
            {
                visited[t] = d++;
                q.push(t);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << visited[i] << "\n";
    }
}