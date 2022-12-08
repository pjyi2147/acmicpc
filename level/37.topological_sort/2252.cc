// acmicpc number: 2252
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;

void dfs(int idx, int& cnt, vector<bool>& visited, vector<pair<int, int>>& s, const vector<int>* nodes)
{
    visited[idx] = true;

    for (auto ch : nodes[idx])
    {
        if (!visited[ch])
        {
            dfs(ch, cnt, visited, s, nodes);
        }
    }
    s.push_back({++cnt, idx});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<int> nodes[n + 1];
    vector<bool> visited(n + 1, false);
    vector<pair<int, int>> s;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        nodes[s].push_back(e);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, cnt, visited, s, nodes);
        }
    }

    sort(s.begin(), s.end(), greater<pair<int, int>>());

    for (int i = 0; i < n; i++)
    {
        cout << s[i].second << " ";
    }
}