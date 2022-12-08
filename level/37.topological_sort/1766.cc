// acmicpc number: 1766
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;

void dfs(const vector<int>* nodes, vector<int>& inbound)
{
    priority_queue<int> pq;

    for (int i = 1; i <= n; i++)
    {
        if (inbound[i] == 0) pq.push(-i);
    }

    while (!pq.empty())
    {
        int cur = -pq.top();
        pq.pop();

        cout << cur << " ";
        for (int i = 0; i < nodes[cur].size(); i++)
        {
            int next = nodes[cur][i];
            inbound[next]--;

            if (inbound[next] == 0)
                pq.push(-next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<int> nodes[n + 1];
    vector<int> inbound(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        nodes[s].push_back(e);
        inbound[e]++;
    }

    dfs(nodes, inbound);
}