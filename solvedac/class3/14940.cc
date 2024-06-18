// acmicpc number: 14940
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i=(a); i < (b); i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<int> vi;
typedef vector<vi> vii;

ll n, m, a, b;
queue<pair<pair<int, int>, int>> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int loc[n][m], t[n][m];
    FOR (i, n)
    {
        FOR (j, m)
        {
            cin >> loc[i][j];

            if (loc[i][j] == 2)
            {
                a = i;
                b = j;
            }
        }
    }
    memset(t, 0, sizeof(t));

    q.push({{a, b}, 0});
    int cnt = 0;
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int x = p.first.second, y = p.first.first;
        if (t[y][x] != 0) continue;

        t[y][x] = p.second;
        int dx[4] = {-1, 1, 0, 0}, dy[4] = { 0, 0, -1, 1};

        FOR (i, 4)
        {
            int ny = p.first.first + dy[i], nx = p.first.second + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && t[ny][nx] == 0 && loc[ny][nx] == 1)
            {
                q.push({{ny, nx}, p.second + 1});
            }
        }
    }

    FOR (i, n)
    {
        FOR (j, m)
        {
            if (t[i][j] == 0 && loc[i][j] == 1)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << t[i][j] << " ";
            }
        }
        cout << "\n";
    }
}
