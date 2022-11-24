// acmicpc number: 1949
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

int solven(int r, int p, vector<int> &cntn, vector<int> &cnt, const vector<vector<int>> &tree, const vector<int> &res);

int solve(int r, int p, vector<int> &cntn, vector<int> &cnt, const vector<vector<int>> &tree, const vector<int> &res)
{
    if (cnt[r] >= 0)
        return cnt[r];

    int tmp = res[r];
    for (auto ch : tree[r])
    {
        if (ch != p)
        {
            tmp += solven(ch, r, cntn, cnt, tree, res);
        }
    }
    return cnt[r] = tmp;
}

int solven(int r, int p, vector<int> &cntn, vector<int> &cnt, const vector<vector<int>> &tree, const vector<int> &res)
{
    if (cntn[r] >= 0)
        return cntn[r];

    int tmp = 0;
    for (auto ch : tree[r])
    {
        if (ch != p)
        {
            tmp += max(solve(ch, r, cntn, cnt, tree, res), solven(ch, r, cntn, cnt, tree, res));
        }
    }
    return cntn[r] = tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<int> res(n, -1);
    vector<vector<int>> tree(n, vector<int>());

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> res[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int s, e;
        cin >> s >> e;
        tree[s - 1].push_back(e - 1);
        tree[e - 1].push_back(s - 1);
    }

    vector<int> cntn(n, -1);
    vector<int> cnt(n, -1);
    solven(0, -1, cntn, cnt, tree, res);
    solve(0, -1, cntn, cnt, tree, res);

    cout << max(cntn[0], cnt[0]);
}