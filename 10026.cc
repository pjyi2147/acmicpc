// acmicpc number: 10026
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

ll n;
int dx[4] = { 0,  0, 1, -1};
int dy[4] = { 1, -1, 0,  0};

void blind_travel(int x, int y, vii& blind_visited, vector<string>& grid)
{
    FOR(k, 4)
    {
        int newx = x + dx[k];
        int newy = y + dy[k];
        if (newx >= 0 && newx < n && newy >= 0 && newy < n &&
            blind_visited[newy][newx] == 0)
        {
            if ((grid[y][x] == 'R' || grid[y][x] == 'G') &&
                (grid[newy][newx] == 'R' || grid[newy][newx] == 'G'))
            {
                blind_visited[newy][newx] = 1;
                blind_travel(newx, newy, blind_visited, grid);
            }
            else if (grid[y][x] == 'B' && grid[newy][newx] == 'B')
            {
                blind_visited[newy][newx] = 1;
                blind_travel(newx, newy, blind_visited, grid);
            }
        }
    }
}

void travel(int x, int y, vii& visited, vector<string>& grid)
{
    FOR(k, 4)
    {
        int newx = x + dx[k];
        int newy = y + dy[k];
        if (newx >= 0 && newx < n && newy >= 0 && newy < n &&
            grid[y][x] == grid[newy][newx] &&
            visited[newy][newx] == 0)
        {
            visited[newy][newx] = 1;
            travel(newx, newy, visited, grid);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    vector<string> grid(n);
    FOR(i, n) cin >> grid[i];

    vii blind_visited(n, vi(n, 0));
    vii visited(n, vi(n, 0));

    int blind_cnt = 0, cnt = 0;
    FOR(a, n)
    {
        FOR(b, n)
        {
            if (visited[a][b] == 0)
            {
                visited[a][b] = 1;
                travel(b, a, visited, grid);
                cnt++;
            }

            if (blind_visited[a][b] == 0)
            {
                blind_visited[a][b] = 1;
                blind_travel(b, a, blind_visited, grid);
                blind_cnt++;
            }
        }
    }

    cout << cnt << " " << blind_cnt;
}
