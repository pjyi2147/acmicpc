// acmicpc number: 16367
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll k, n;
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

void sccvisit(int i, vector<int> &ret, int cnt, const vector<set<int>> &gb, vector<bool> &colour)
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

int scc(vector<int> &ret, const vector<set<int>> &gf, const vector<set<int>> &gb)
{
    auto ff = dfs2(gf);

    sort(ff.begin(), ff.end(), greater<pair<int, int>>());
    vector<bool> colour(gf.size(), false);

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
    cin >> k >> n;

    vector<set<int>> gf(2 * k, set<int>());
    vector<set<int>> gb(2 * k, set<int>());

    for (int i = 0; i < n; i++)
    {
        char ch[3];
        int idx[3];
        bool bo[3];
        for (int j = 0; j < 3; j++)
        {
            cin >> idx[j] >> ch[j];
            idx[j]--;
            if (ch[j] == 'R')
            {
                bo[j] = true;
            }
            else
            {
                bo[j] = false;
            }
        }

        int oidx[3];
        int nidx[3];
        for (int j = 0; j < 3; j++)
        {
            if (bo[j])
            {
                oidx[j] = 2 * idx[j];
                nidx[j] = 2 * idx[j] + 1;
            }
            else
            {
                oidx[j] = 2 * idx[j] + 1;
                nidx[j] = 2 * idx[j];
            }
        }
        // 0 & 1
        gf[nidx[0]].insert(oidx[1]);
        gf[nidx[1]].insert(oidx[0]);

        gb[oidx[1]].insert(nidx[0]);
        gb[oidx[0]].insert(nidx[1]);

        // 0 & 2
        gf[nidx[0]].insert(oidx[2]);
        gf[nidx[2]].insert(oidx[0]);

        gb[oidx[2]].insert(nidx[0]);
        gb[oidx[0]].insert(nidx[2]);
    
        // 1 & 2
        gf[nidx[1]].insert(oidx[2]);
        gf[nidx[2]].insert(oidx[1]);

        gb[oidx[2]].insert(nidx[1]);
        gb[oidx[1]].insert(nidx[2]);
    }

    vector<int> scc_g(gf.size());
    int scc_cnt = scc(scc_g, gf, gb);

    for (int i = 0; i < k; i++)
    {
        if (scc_g[2 * i] == scc_g[2 * i + 1])
        {
            cout << -1 << "\n";
            return 0;
        }
    }

    vector<set<int>> scc_graph(scc_cnt, set<int>());
    vector<char> sat_sol(k, 'A');
    for (int i = 0; i < scc_g.size(); i++)
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
        for (int i = 0; i < scc_g.size(); i++)
        {
            if (scc_g[i] == u)
            {
                int idx = i / 2;
                if (sat_sol[idx] == 'A')
                {
                    if (i % 2 == 1)
                    {
                        sat_sol[idx] = 'R';
                    }
                    else
                    {
                        sat_sol[idx] = 'B';
                    }
                }
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << (sat_sol[i] == 'A' ? 'B' : sat_sol[i]);
    }
}