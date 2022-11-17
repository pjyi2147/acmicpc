// acmicpc number: 4803
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;

bool dfs(int i, int p, vector<bool>& visited, const vector<vector<int>>& nodes)
{
    visited[i] = true;
    for (auto ch: nodes[i])
    {
        if (ch == p) continue;
        if (visited[ch])
            return false;
        if (!dfs(ch, i, visited, nodes))
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c = 1;
    while (cin >> n >> m && (n != 0 || m != 0))
    {
        vector<vector<int>> nodes(n);
        vector<bool> visited(n, false);
        for (int i = 0; i < m; i++)
        {
            int s, e;
            cin >> s >> e;
            nodes[s - 1].push_back(e - 1);
            nodes[e - 1].push_back(s - 1);
        }

        int tree = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dfs(i, -1, visited, nodes))
                tree++;
        }
        cout << "Case " << c << ": ";
        if (tree == 0)
            cout << "No trees.\n";
        else if (tree == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << tree << " trees.\n";
        c++;
    }
}