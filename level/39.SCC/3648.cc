// acmicpc number: 3648
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;

void dfs(int i, int &cnt, const vector<set<int>> &g, vector<pair<int, int>> &ret, vector<bool> &visited)
{
    visited[i] = true;
    for (auto child : g[i])
    {
        if (!visited[child])
            dfs(child, cnt, g, ret, visited);
    }
    ret.push_back({++cnt, i});
}

vector<pair<int, int>> dfs(const vector<set<int>> &g)
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

void solve()
{
    while (cin >> n >> m)
    {
        vector<set<int>> gf(2 * n, set<int>());
        vector<set<int>> gb(2 * n, set<int>());
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
                gf[na].insert(ob);
                gf[nb].insert(oa);

                gb[ob].insert(na);
                gb[oa].insert(nb);
            }
            else if (a > 0 && b < 0)
            {
                gf[na].insert(nb);
                gf[ob].insert(oa);

                gb[nb].insert(na);
                gb[oa].insert(ob);
            }
            else if (a < 0 && b > 0)
            {
                gf[oa].insert(ob);
                gf[nb].insert(na);

                gb[ob].insert(oa);
                gb[na].insert(nb);
            }
            else
            {
                gf[oa].insert(nb);
                gf[ob].insert(na);

                gb[nb].insert(oa);
                gb[na].insert(ob);
            }
        }
        gf[1].insert(0);
        gb[0].insert(1);

        vector<int> scc_g(gf.size());
        int scc_cnt = scc(scc_g, gf, gb);

        bool ret = true;
        for (int i = 0; i < n; i++)
        {
            if (scc_g[2 * i] == scc_g[2 * i + 1])
            {
                ret = false;
                break;
            }
        }
        cout << (ret ? "yes\n" : "no\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}