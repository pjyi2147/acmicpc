// acmicpc number: 2150
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll v, e;

void dfs(int i, vector<int> *g, vector<pair<int, int>> &f, int &c, vector<bool> &visited)
{
    visited[i] = true;
    for (auto ch : g[i])
    {
        if (!visited[ch])
            dfs(ch, g, f, c, visited);
    }
    f.push_back({c++, i});
}

void dfs(vector<int> *g, vector<pair<int, int>> &f)
{
    int c = 1;
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            dfs(i, g, f, c, visited);
        }
    }
}

void sccvisit(vector<int> *gb, int u, int cnt, vector<bool> &colour, vector<int> &comp)
{
    colour[u] = true;
    comp[u] = cnt;

    for (auto ch : gb[u])
    {
        if (!colour[ch])
            sccvisit(gb, ch, cnt, colour, comp);
    }
}

void scc(vector<int> *gf, vector<int> *gb)
{
    vector<pair<int, int>> ff;
    dfs(gf, ff);

    sort(ff.begin(), ff.end(), greater<pair<int, int>>());

    vector<bool> colour(v, false);
    int cnt = 0;
    vector<int> comp(v, 0);
    for (auto i : ff)
    {
        int u = i.second;
        if (!colour[u])
        {
            cnt++;
            sccvisit(gb, u, cnt, colour, comp);
        }
    }

    cout << cnt << '\n';
    vector<bool> p(v, false);
    for (int it = 1; it <= cnt; it++)
    {
        int cur;
        bool found = false;
        for (int i = 0; i < v; i++)
        {
            if (!p[i])
            {
                if (!found)
                {
                    found = true;
                    p[i] = true;
                    cur = comp[i];
                    cout << i + 1 << " ";
                }
                else if (cur == comp[i])
                {
                    cout << i + 1 << " ";
                    p[i] = true;
                }
            }
        }
        cout << "-1\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v >> e;

    vector<int> gf[v];
    vector<int> gb[v];

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        gf[a - 1].push_back(b - 1);
        gb[b - 1].push_back(a - 1);
    }

    scc(gf, gb);
}