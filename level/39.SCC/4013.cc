// acmicpc number: 4013
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m, s, p;

struct Node
{
    int val;
    bool rest;

    Node(int val, bool rest) : val{val}, rest{rest} {}
};

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
    vector<bool> visited(n, false);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            dfs(i, cnt, g, ret, visited);
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
    vector<bool> colour(n, false);

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

ll solve(int k, vector<ll> &dp, vector<bool> &res, const vector<set<int>> &g, const vector<Node> &nodes)
{
    if (dp[k] != -1)
        return dp[k];

    res[k] = nodes[k].rest;
    ll tmp = 0;
    for (auto ch : g[k])
    {
        ll tmp2 = solve(ch, dp, res, g, nodes);
        if (tmp <= tmp2)
        {
            tmp = tmp2;
            res[k] = res[k] || res[ch];
        }
    }
    if (res[k])
        tmp += nodes[k].val;
    return dp[k] = tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<Node> nodes(n, Node(0, false));
    vector<vector<int>> gf(n, vector<int>());
    vector<vector<int>> gb(n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        gf[a - 1].push_back(b - 1);
        gb[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; i++)
    {
        int money;
        cin >> money;
        nodes[i].val = money;
    }

    int s, p;
    cin >> s >> p;
    s = s - 1;
    for (int i = 0; i < p; i++)
    {
        int k;
        cin >> k;
        nodes[k - 1].rest = true;
    }

    vector<int> scc_g(n, -1);
    int scc_cnt = scc(scc_g, gf, gb);
    vector<Node> new_nodes(scc_cnt, Node(0, false));
    vector<set<int>> new_g(scc_cnt, set<int>());
    int new_s = scc_g[s];

    for (int i = 0; i < n; i++)
    {
        int nidx = scc_g[i];
        new_nodes[nidx].rest = new_nodes[nidx].rest || nodes[i].rest;
        new_nodes[nidx].val += nodes[i].val;

        for (auto ch : gf[i])
        {
            int chidx = scc_g[ch];
            if (chidx != nidx)
                new_g[nidx].insert(chidx);
        }
    }

    vector<ll> dp(scc_cnt, -1);
    vector<bool> res(scc_cnt, false);
    cout << solve(new_s, dp, res, new_g, new_nodes);
}