// acmicpc number: 11657
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m;
ll INF = 9223372036854775;
struct pt {
    int u, v, c;
    pt(int u, int v, int c): u{u}, v{v}, c{c} {}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    vector<pt> node;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        node.push_back(pt(a - 1, b - 1, c));
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (const auto k : node)
        {
            if (dist[k.u] == INF) continue;
            if (dist[k.u] + k.c < dist[k.v])
            {
                dist[k.v] = dist[k.u] + k.c;
            }
        }
    }

    for (const auto k : node)
    {
        if (dist[k.u] == INF) continue;
        if (dist[k.u] + k.c < dist[k.v])
        {
            cout << -1;
            return 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        cout << ((dist[i] == INF) ? -1 : dist[i]) << '\n';
    }
    
    return 0;
}