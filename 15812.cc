// acmicpc number: 15812
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;

int solve(vector<vector<bool>> &planet, int ai, int aj, int bi, int bj, int cnt)
{
    int ret = 0;
    vector<vector<bool>> infect(n, vector<bool>(m, false));
    infect[ai][aj] = true;
    infect[bi][bj] = true;
    queue<pair<int, pair<int, int>>> t;
    t.push({0, {ai, aj}});
    t.push({0, {bi, bj}});

    int xoff[] = {0, 0, -1, 1};
    int yoff[] = {-1, 1, 0, 0};

    while (!t.empty())
    {
        auto u = t.front();
        t.pop();
        int nt = u.first + 1;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int ni = u.second.first + yoff[i];
                int nj = u.second.second + xoff[i];
                if (ni >= n || ni < 0 || nj >= m || nj < 0) continue;
                if (!infect[ni][nj])
                {
                    infect[ni][nj] = true;
                    t.push({nt, {ni, nj}});
                    if (planet[ni][nj])
                    {
                        cnt--;
                    }
                    if (cnt == 0)
                    {
                        return nt;
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    int cnt = 0;
    vector<vector<bool>> planet(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '1')
            {
                planet[i][j] = true;
                cnt++;
            }
        }
    }

    int ret = INT_MAX;
    for (int a = 0; a < n * m; a++)
    {
        for (int b = a + 1; b < n * m; b++)
        {
            int ai = a / m, aj = a % m;
            int bi = b / m, bj = b % m;
            if (!planet[ai][aj] && !planet[bi][bj])
            {
                ret = min(ret, solve(planet, ai, aj, bi, bj, cnt));
            }
        }
    }
    cout << ret;
}