// acmicpc number: 3977
// acmicpc number: 2150
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll T, v, e;

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

int scc(vector<int> &scc_g, vector<int> *gf, vector<int> *gb)
{
    vector<pair<int, int>> ff;
    dfs(gf, ff);

    sort(ff.begin(), ff.end(), greater<pair<int, int>>());

    vector<bool> colour(v, false);
    int cnt = 0;
    for (auto i : ff)
    {
        int u = i.second;
        if (!colour[u])
        {
            sccvisit(gb, u, cnt, colour, scc_g);
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> v >> e;

        vector<int> gf[v];
        vector<int> gb[v];

        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            gf[a].push_back(b);
            gb[b].push_back(a);
        }

        vector<int> scc_g(v, 0);
        int cnt = scc(scc_g, gf, gb);
        vector<int> innode(cnt, 0);
        for (int i = 0; i < v; i++)
        {
            for (auto ch : gf[i])
            {
                int scc_s = scc_g[i], scc_e = scc_g[ch];
                if (scc_s != scc_e)
                {
                    innode[scc_e]++;
                }
            }
        }

        vector<int> ans_area;
        vector<int> ans;

        for (int i = 0; i < cnt; i++)
        {
            if (innode[i] == 0)
            {
                ans_area.push_back(i);
            }
        }

        if (ans_area.size() == 1)
        {
            for (int i = 0; i < v; i++)
            {
                if (find(ans_area.begin(), ans_area.end(), scc_g[i]) != ans_area.end())
                {
                    ans.push_back(i);
                }
            }

            sort(ans.begin(), ans.end());

            for (auto i : ans)
            {
                cout << i << "\n";
            }
        }
        else
        {
            cout << "Confused\n";
        }
        cout << "\n";
    }
}