// acmicpc number: 11438
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;
vector<int> tree[100000];
int sp_tbl[18][100000];
int dep[100000];

void dfs(int r)
{
    for (auto ch : tree[r])
    {
        if (ch ^ sp_tbl[0][r])
        {
            sp_tbl[0][ch] = r;
            dep[ch] = dep[r] + 1;
            dfs(ch);
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
        }
    }
}

void query(int s, int e)
{
    if (dep[s] < dep[e])
        swap(s, e);

    for (int i = 17; i >= 0; i--)
    {
        if ((dep[s] - dep[e]) & (1 << i))
        {
            s = sp_tbl[i][s];
        }
    }
    if (s == e)
    {
        cout << s + 1 << "\n";
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
    cout << sp_tbl[0][e] + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int s, e;
        cin >> s >> e;
        tree[s - 1].push_back(e - 1);
        tree[e - 1].push_back(s - 1);
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