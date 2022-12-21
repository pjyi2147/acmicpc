// acmicpc number: 11281
// acmicpc number: 11280
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;

void dfs(int i, int &cnt, const vector<vector<int>> &g, vector<pair<int, int>> &ret, vector<bool> &visited)
{
    visited[i] = true;
    for (auto child : g[i])
    {
        if (!visited[child])
            dfs(child, cnt, g, ret, visited);
    }
    ret.push_back({++cnt, i});
}

vector<pair<int, int>> dfs(const vector<vector<int>> &g)
{
    vector<pair<int, int>> ret;
    vector<bool> visited(g.size(), false);
    int cnt = 0;
    for (int i = 0; i < g.size(); i++)
    {
        if (visited[i] == false)
        {
            dfs(i, cnt, g, ret, visited);
        }
    }
    return ret;
}

void dfs2(int i, int &cnt, const vector<set<int>> &g, vector<pair<int, int>> &ret, vector<bool> &visited)
{
    visited[i] = true;
    for (auto child : g[i])
    {
        if (!visited[child])
            dfs2(child, cnt, g, ret, visited);
    }
    ret.push_back({++cnt, i});
}

vector<pair<int, int>> dfs2(const vector<set<int>> &g)
{
    vector<pair<int, int>> ret;
    vector<bool> visited(g.size(), false);
    int cnt = 0;
    for (int i = 0; i < g.size(); i++)
    {
        if (visited[i] == false)
        {
            dfs2(i, cnt, g, ret, visited);
        }
    }
    return ret;
}

void sccvisit(int i, vector<int> &ret, int cnt, const vector<vector<int>> &gb, vector<bool> &colour)
{
    colour[i] = true;
    ret[i] = cnt;

    for (auto ch : gb[i])
    {
        if (!colour[ch])
        {
            sccvisit(ch, ret, cnt, gb, colour);
        }
    }
}

int scc(vector<int> &ret, const vector<vector<int>> &gf, const vector<vector<int>> &gb)
{
    auto ff = dfs(gf);

    sort(ff.begin(), ff.end(), greater<pair<int, int>>());
    vector<bool> colour(2 * n, false);

    int cnt = 0;
    for (auto node : ff)
    {
        auto i = node.second;
        if (!colour[i])
        {
            sccvisit(i, ret, cnt, gb, colour);
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
    cin >> n >> m;
    vector<vector<int>> gf(2 * n, vector<int>());
    vector<vector<int>> gb(2 * n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b, oa, ob, na, nb;
        cin >> a >> b;

        oa = (abs(a) - 1) * 2;
        na = oa + 1;

        ob = (abs(b) - 1) * 2;
        nb = ob + 1;

        if (a > 0 && b > 0)
        {
            gf[na].push_back(ob);
            gf[nb].push_back(oa);

            gb[ob].push_back(na);
            gb[oa].push_back(nb);
        }
        else if (a > 0 && b < 0)
        {
            gf[na].push_back(nb);
            gf[ob].push_back(oa);

            gb[nb].push_back(na);
            gb[oa].push_back(ob);
        }
        else if (a < 0 && b > 0)
        {
            gf[oa].push_back(ob);
            gf[nb].push_back(na);

            gb[ob].push_back(oa);
            gb[na].push_back(nb);
        }
        else
        {
            gf[oa].push_back(nb);
            gf[ob].push_back(na);

            gb[nb].push_back(oa);
            gb[na].push_back(ob);
        }
    }

    vector<int> scc_g(2 * n);
    int scc_cnt = scc(scc_g, gf, gb);

    for (int i = 0; i < n; i++)
    {
        if (scc_g[2 * i] == scc_g[2 * i + 1])
        {
            cout << 0 << "\n";
            return 0;
        }
    }

    cout << 1 << "\n";

    vector<set<int>> scc_graph(scc_cnt, set<int>());
    vector<int> sat_sol(n, -1);
    for (int i = 0; i < 2 * n; i++)
    {
        int cur_scc_idx = scc_g[i];
        for (auto ch : gf[i])
        {
            int ch_idx = scc_g[ch];
            if (ch_idx != cur_scc_idx)
            {
                scc_graph[cur_scc_idx].insert(ch_idx);
            }
        }
    }

    auto sccff = dfs2(scc_graph);
    sort(sccff.begin(), sccff.end(), greater<pair<int, int>>());
    for (auto p : sccff)
    {
        int u = p.second;
        for (int i = 0; i < 2 * n; i++)
        {
            if (scc_g[i] == u)
            {
                int idx = i / 2;
                if (sat_sol[idx] == -1)
                {
                    if (i % 2 == 1)
                    {
                        sat_sol[idx] = 1;
                    }
                    else
                    {
                        sat_sol[idx] = 0;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << (sat_sol[i] == -1 ? 0 : sat_sol[i]) << " ";
    }
    cout << "\n";
}