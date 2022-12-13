// acmicpc number: 13511
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;
vector<pair<int, int>> tree[100000];
int sp_tbl[18][100000];
ll sp_tbl_cost[18][100000];
int dep[100000];

void dfs(int r)
{
    for (auto ch : tree[r])
    {
        if (ch.first ^ sp_tbl[0][r])
        {
            sp_tbl[0][ch.first] = r;
            sp_tbl_cost[0][ch.first] = ch.second;
            dep[ch.first] = dep[r] + 1;
            dfs(ch.first);
        }
    }
}

void build_sparse()
{
    for (int k = 1; k <= 17; k++)
    {
        for (int i = 0; i < n; i++)
        {
            sp_tbl[k][i] = sp_tbl[k - 1][sp_tbl[k - 1][i]];
            sp_tbl_cost[k][i] = (sp_tbl_cost[k - 1][sp_tbl[k - 1][i]] + sp_tbl_cost[k - 1][i]);
        }
    }
}

void query1(int s, int e)
{
    if (dep[s] < dep[e])
        swap(s, e);
    ll ret_cost = 0;
    for (int i = 17; i >= 0; i--)
    {
        if ((dep[s] - dep[e]) & (1 << i))
        {
            ret_cost += sp_tbl_cost[i][s];
            s = sp_tbl[i][s];
        }
    }
    if (s == e)
    {
        cout << ret_cost << "\n";
        return;
    }

    for (int i = 17; i >= 0; i--)
    {
        if (sp_tbl[i][s] ^ sp_tbl[i][e])
        {
            ret_cost += sp_tbl_cost[i][s] + sp_tbl_cost[i][e];
            s = sp_tbl[i][s];
            e = sp_tbl[i][e];
        }
    }
    ret_cost += sp_tbl_cost[0][s] + sp_tbl_cost[0][e];
    cout << ret_cost << '\n';
}

void query2(int s, int e, int k)
{
    int ori_s = s, ori_e = e;
    if (dep[s] < dep[e]) swap(s, e);
    
    for (int i = 17; i >= 0; i--)
    {
        if ((dep[s] - dep[e]) & (1 << i))
        {
            s = sp_tbl[i][s];
        }
    }
    if (s == e)
    {
        int ret;
        if (dep[ori_s] < dep[ori_e])
        {
            ret = ori_e;
            k = (dep[ori_e] - dep[ori_s] + 1 - k);
        }
        else
        {
            ret = ori_s;
            k = k - 1;
        }
        for (int i = 17; i >= 0; i--)
        {
            if (k & (1 << i))
            {
                ret = sp_tbl[i][ret];
            }
        }
        cout << ret + 1 << "\n";
        return;
    }

    for (int i = 17; i >= 0; i--)
    {
        if (sp_tbl[i][s] ^ sp_tbl[i][e])
        {
            s = sp_tbl[i][s];
            e = sp_tbl[i][e];
        }
    }
    int com_root = sp_tbl[0][e];

    int d1 = dep[ori_s] - dep[com_root], d2 = dep[ori_e] - dep[com_root];

    if (d1 + 1 == k)
    {
        cout << com_root + 1 << "\n";
    }
    else if (d1 + 1 < k)
    {
        k = d1 + d2 + 1 - k;
        int ret = ori_e;
        for (int i = 17; i >= 0; i--)
        {
            if (k & (1 << i))
            {
                ret = sp_tbl[i][ret];
            }
        }
        cout << ret + 1 << "\n";
    }
    else
    {
        int ret = ori_s;
        k = k - 1;
        for (int i = 17; i >= 0; i--)
        {
            if (k & (1 << i))
            {
                ret = sp_tbl[i][ret];
            }
        }
        cout << ret + 1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        tree[s - 1].push_back({e - 1, c});
        tree[e - 1].push_back({s - 1, c});
    }
    int cnt = 1;
    dfs(0);
    build_sparse();

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int q, s, e;
        cin >> q >> s >> e;
        if (q == 1)
            query1(s - 1, e - 1);
        else
        {
            int k;
            cin >> k;
            query2(s - 1, e - 1, k);
        }
    }
}