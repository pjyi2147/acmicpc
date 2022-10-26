// acmicpc number: 2667
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;

struct Compg {
    bool operator()(int a, int b) { return a > b; }
} compg;

int setfire(int x, int y, const vector<vector<bool>>& v, vector<vector<bool>>& visited)
{
    visited[y][x] = true;
    int ret = 1;
    int offx[] = {0, 0, -1, 1};
    int offy[] = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++)
    {
        int px = x + offx[i];
        int py = y + offy[i];
        if (px < 0 || px >= n || py < 0 || py >= n) continue;

        if (v[py][px] && !visited[py][px])
        {
            ret += setfire(px, py, v, visited);
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<vector<bool>> v(n, vector<bool>(n, false));
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c; cin >> c;
            v[i][j] = (c != '0');
        }
    }

    int cnt = 0;
    vector<int> cnt_v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] && !visited[i][j])
            {
                cnt++;
                cnt_v.push_back(setfire(j, i, v, visited));
            }
        }
    }

    cout << cnt << "\n";
    sort(cnt_v.begin(), cnt_v.end());
    for (int i = 0; i < cnt_v.size(); i++)
    {
        cout << cnt_v[i] << "\n";
    }
}