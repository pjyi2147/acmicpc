// acmicpc number: 2618
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, w;
constexpr int INF = 987654321;

int caldist(int a, int b, bool p2, const vector<pair<int, int>> &incl)
{
    if (a == -1 && !p2)
    {
        return abs(incl[b].first - 1) + abs(incl[b].second - 1);
    }
    else if (a == -1 && p2)
    {
        return abs(incl[b].first - n) + abs(incl[b].second - n);
    }
    else
    {
        return abs(incl[b].first - incl[a].first) + abs(incl[b].second - incl[a].second);
    }
}

int solve(int p1, int p2, vector<vector<int>> &min_dist, const vector<pair<int, int>> &incl)
{
    if (p1 == w || p2 == w)
        return 0;
    if (min_dist[p1][p2] != -1)
        return min_dist[p1][p2];
    int next = max(p1, p2) + 1;
    int dist1 = caldist(p1 - 1, next - 1, false, incl), dist2 = caldist(p2 - 1, next - 1, true, incl);

    int r1 = dist1 + solve(next, p2, min_dist, incl);
    int r2 = dist2 + solve(p1, next, min_dist, incl);
    return min_dist[p1][p2] = min(r1, r2);
}

void print(int p1, int p2, vector<vector<int>> &min_dist, const vector<pair<int, int>> &incl)
{
    if (p1 == w || p2 == w)
        return;

    int next = max(p1, p2) + 1;
    int dist1 = caldist(p1 - 1, next - 1, false, incl), dist2 = caldist(p2 - 1, next - 1, true, incl);

    if (next == w && (dist1 < dist2))
    {
        cout << 1 << "\n";
    }
    else if (next == w)
    {
        cout << 2 << "\n";
    }
    else if (min_dist[next][p2] + dist1 < min_dist[p1][next] + dist2)
    {
        cout << 1 << "\n";
        print(next, p2, min_dist, incl);
    }
    else
    {
        cout << 2 << "\n";
        print(p1, next, min_dist, incl);
    }
}

void solve(const vector<pair<int, int>> &incl)
{
    vector<vector<int>> mindist(w, vector<int>(w, -1));
    cout << solve(0, 0, mindist, incl) << "\n";
    print(0, 0, mindist, incl);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> w;
    vector<pair<int, int>> inci(w, {-1, -1});
    for (int i = 0; i < w; i++)
    {
        cin >> inci[i].first >> inci[i].second;
    }
    solve(inci);
}