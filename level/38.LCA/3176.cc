// acmicpc number: 3176
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;
vector<pair<int, int>> tree[100000];
int sp_tbl[18][100000];
int sp_tbl_min[18][100000];
int sp_tbl_cost[18][100000];
int dep[100000];

void dfs(int r)
{
    for (auto ch : tree[r])
    {
        if (ch.first ^ sp_tbl[0][r])
        {
            sp_tbl[0][ch.first] = r;
            sp_tbl_min[0][ch.first] = ch.second;
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
            sp_tbl_min[k][i] = min(sp_tbl_min[k - 1][sp_tbl[k - 1][i]], sp_tbl_min[k - 1][i]);
            sp_tbl_cost[k][i] = max(sp_tbl_cost[k - 1][sp_tbl[k - 1][i]], sp_tbl_cost[k - 1][i]);
        }
    }
}

void query(int s, int e)
{
    if (dep[s] < dep[e])
        swap(s, e);
    int ret_max = -1, ret_min = 1000001;
    for (int i = 17; i >= 0; i--)
    {
        if ((dep[s] - dep[e]) & (1 << i))
        {
            ret_max = max(ret_max, sp_tbl_cost[i][s]);
            ret_min = min(ret_min, sp_tbl_min[i][s]);
            s = sp_tbl[i][s];
        }
    }
    if (s == e)
    {
        cout << ret_min << " " << ret_max << "\n";
        return;
    }

    for (int i = 17; i >= 0; i--)
    {
        if (sp_tbl[i][s] ^ sp_tbl[i][e])
        {
            ret_min = min(ret_min, min(sp_tbl_min[i][s], sp_tbl_min[i][e]));
            ret_max = max(ret_max, max(sp_tbl_cost[i][s], sp_tbl_cost[i][e]));
            s = sp_tbl[i][s];
            e = sp_tbl[i][e];
        }
    }
    ret_min = min(ret_min, min(sp_tbl_min[0][s], sp_tbl_min[0][e]));
    ret_max = max(ret_max, max(sp_tbl_cost[0][s], sp_tbl_cost[0][e]));
    cout << ret_min << " " << ret_max << '\n';
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
        int s, e;
        cin >> s >> e;
        query(s - 1, e - 1);
    }
}