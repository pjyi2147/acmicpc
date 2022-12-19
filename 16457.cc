// acmicpc number: 16457
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m, k;

ll solve(const vector<bool>& comb, const vector<vector<int>>& q)
{
    ll ret = 0;
    for (int i = 0; i < m; i++)
    {
        bool clear = true;
        for (int j = 0; j < k; j++)
        {
            if (comb[q[i][j] - 1] == 0)
            {
                clear = false;
            }
        }
        if (clear)
        {
            ret++;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    vector<vector<int>> q(m, vector<int>());
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int s;
            cin >> s;
            q[i].push_back(s);
        }
    }

    vector<bool> comb(2 * n, true);
    for (int i = 0; i < n; i++)
    {
        comb[i] = false;
    }

    ll ret = 0;
    do
    {
        ret = max(ret, solve(comb, q));
    } while (next_permutation(comb.begin(), comb.end()));

    cout << ret;
}