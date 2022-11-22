// acmicpc number: 17472
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;
constexpr int INF = 987654321;

void dfs(int i, int j, vector<vector<bool>> &visited, const vector<vector<bool>> &island, vector<vector<int>> &nisland, int cnt)
{
    visited[i][j] = true;
    nisland[i][j] = cnt;
    int xoff[] = {-1, 1, 0, 0};
    int yoff[] = {0, 0, -1, 1};

    for (int off = 0; off < 4; off++)
    {
        int ni = i + xoff[off], nj = j + yoff[off];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m)
            continue;
        if (island[ni][nj] && !visited[ni][nj])
        {
            dfs(ni, nj, visited, island, nisland, cnt);
        }
    }
}

int find_islands(const vector<vector<bool>> &island, vector<vector<int>> &nisland)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (island[i][j] && !visited[i][j])
            {
                dfs(i, j, visited, island, nisland, ++cnt);
            }
        }
    return cnt;
}

void find_bridges(vector<vector<int>> &dist, const vector<vector<int>> &nisland)
{
    for (int i = 0; i < n; i++)
    {
        int d = 0;
        int from_island = 0;
        for (int j = 0; j < m; j++)
        {
            if (from_island == 0 && nisland[i][j] > 0)
            {
                d = 0;
                from_island = nisland[i][j];
            }
            else if (from_island != 0 && nisland[i][j] == 0)
            {
                d++;
            }
            else if (from_island != 0 && nisland[i][j] == from_island)
            {
                d = 0;
            }
            else if (from_island != 0 && nisland[i][j] != from_island)
            {
                int to_island = nisland[i][j];
                if (d > 1)
                {
                    int sm = min(from_island, to_island), lg = max(from_island, to_island);
                    dist[sm - 1][lg - 1] = min(dist[sm - 1][lg - 1], d);
                }
                from_island = to_island;
                d = 0;
            }
        }
    }

    for (int j = 0; j < m; j++)
    {
        int d = 0;
        int from_island = 0;
        for (int i = 0; i < n; i++)
        {
            if (from_island == 0 && nisland[i][j] > 0)
            {
                d = 0;
                from_island = nisland[i][j];
            }
            else if (from_island != 0 && nisland[i][j] == 0)
            {
                d++;
            }
            else if (from_island != 0 && nisland[i][j] == from_island)
            {
                d = 0;
            }
            else if (from_island != 0 && nisland[i][j] != from_island)
            {
                int to_island = nisland[i][j];
                if (d > 1)
                {
                    int sm = min(from_island, to_island), lg = max(from_island, to_island);
                    dist[sm - 1][lg - 1] = min(dist[sm - 1][lg - 1], d);
                }
                from_island = to_island;
                d = 0;
            }
        }
    }
}

struct UF
{
    int *parents;
    int *ranks;
    UF(int k)
    {
        parents = new int[k];
        ranks = new int[k];
        for (int i = 0; i < k; i++)
        {
            parents[i] = i;
            ranks[i] = 1;
        }
    }
    ~UF()
    {
        delete[] parents;
        delete[] ranks;
    }
    int find(int k)
    {
        if (parents[k] != k)
            parents[k] = find(parents[k]);
        return parents[k];
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (ranks[x] > ranks[y])
            parents[y] = x;
        else
            parents[x] = y;
        if (ranks[x] == ranks[y])
            ranks[y]++;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<vector<bool>> island(n, vector<bool>(m, false));
    vector<vector<int>> nisland(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int k;
            cin >> k;
            if (k == 1)
                island[i][j] = true;
        }
    }

    int cnt = find_islands(island, nisland);
    vector<vector<int>> dist(cnt, vector<int>(cnt, INF));

    find_bridges(dist, nisland);
    vector<pair<int, pair<int, int>>> dist_island;
    for (int i = 0; i < cnt; i++)
        for (int j = i + 1; j < cnt; j++)
        {
            if (dist[i][j] < INF)
                dist_island.push_back({dist[i][j], {i, j}});
        }

    auto uf = new UF(cnt);
    ll ret = 0;
    sort(dist_island.begin(), dist_island.end());
    for (auto i : dist_island)
    {
        if (uf->find(i.second.first) != uf->find(i.second.second))
        {
            uf->merge(i.second.first, i.second.second);
            ret += i.first;
        }
    }

    int k = uf->find(0);
    for (int i = 1; i < cnt; i++)
    {
        if (uf->find(i) != k) 
        {
            cout << -1;
            return 0;
        }
    }
    cout << ret;
}