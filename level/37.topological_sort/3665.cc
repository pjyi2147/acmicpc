// acmicpc number: 3665
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll T, n, m;

void dfs(const vector<vector<bool>>& ly, vector<int>& ideg)
{
    queue<int> pq;

    for (int i = 1; i <= n; i++)
    {
        if (ideg[i] == 0) pq.push(i);
    }

    vector<int> ret;
    bool v = true;
    while (!pq.empty())
    {
        if (pq.size() > 1) v = false;

        auto u = pq.front();
        pq.pop();
        ret.push_back(u);
        for (int i = 1; i <= n; i++)
        {
            if (ly[u][i])
            {
                ideg[i]--;
                if (ideg[i] == 0)
                    pq.push(i);
            }
        }
    }

    if (ret.size() != n)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    else if (!v)
    {
        cout << "?\n";
        return;
    }

    for (auto i : ret)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n;
        vector<vector<bool>> ly(n + 1, vector<bool>(n + 1, false));
        vector<int> ideg(n + 1, 0);
        vector<int> ord;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            for (auto i : ord)
            {
                ly[i][k] = true;
                ideg[k]++;
            }
            ord.push_back(k);
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int s, e;
            cin >> s >> e;
            if (ly[s][e])
            {
                ly[s][e] = false;
                ly[e][s] = true;
                ideg[e]--;
                ideg[s]++;
            }
            else
            {
                ly[e][s] = false;
                ly[s][e] = true;
                ideg[s]--;
                ideg[e]++;
            }
        }

        dfs(ly, ideg);
    }
}