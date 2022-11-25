// acmicpc number: 2213
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

int solven(int r, int p, vector<int> &sn, vector<int> &s, const vector<vector<int>> &tree, const vector<int> &w);

int solve(int r, int p, vector<int> &sn, vector<int> &s, const vector<vector<int>> &tree, const vector<int> &w)
{
    if (s[r] > -1)
        return s[r];

    int tmp = w[r];
    for (auto ch : tree[r])
    {
        if (ch != p)
        {
            tmp += solven(ch, r, sn, s, tree, w);
        }
    }
    return s[r] = tmp;
}

int solven(int r, int p, vector<int> &sn, vector<int> &s, const vector<vector<int>> &tree, const vector<int> &w)
{
    if (sn[r] > -1)
        return sn[r];

    int tmp = 0;
    for (auto ch : tree[r])
    {
        if (ch != p)
        {
            tmp += max(solven(ch, r, sn, s, tree, w), solve(ch, r, sn, s, tree, w));
        }
    }
    return sn[r] = tmp;
}

void getans(int r, int p, bool in, const vector<int>& ns, const vector<int>& s, const vector<vector<int>>& tree, vector<int>& ret)
{
    if (in)
    {
        ret.push_back(r);

        for (auto ch : tree[r])
        {
            if (ch != p)
            {
                getans(ch, r, false, ns, s, tree, ret);
            }
        }
    }
    else 
    {
        for (auto ch : tree[r])
        {
            if (ch != p)
            {
                in = ns[ch] < s[ch];
                getans(ch, r, in, ns, s, tree, ret);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<int> w(n, -1);
    vector<vector<int>> tree(n, vector<int>());

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int s, e;
        cin >> s >> e;
        tree[s - 1].push_back(e - 1);
        tree[e - 1].push_back(s - 1);
    }
    vector<int> ns(n, -1);
    vector<int> s(n, -1);

    solve(0, -1, ns, s, tree, w);
    solven(0, -1, ns, s, tree, w);

    vector<int> ret;
    bool in = ns[0] < s[0];
    getans(0, -1, in, ns, s, tree, ret);

    cout << (in ? s[0] : ns[0]) << "\n";
    sort(ret.begin(), ret.end());
    for (auto ch : ret)
    {
        cout << ch + 1 << " ";
    }
}