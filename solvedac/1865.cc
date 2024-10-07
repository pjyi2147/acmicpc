// acmicpc number: 1865
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

ll tc;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        int n, m, w;
        cin >> n >> m >> w;

        vii dist(n+1, vi(n+1, 1e9));
        for (int j = 0; j < m; j++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            dist[s][e] = min(dist[s][e], t);
            dist[e][s] = min(dist[e][s], t);
        }

        for (int j = 0; j < w; j++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            dist[s][e] = min(dist[s][e], -t);
        }

        vi retdist(n+1, 1e9);
        retdist[1] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n ; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (dist[j][k] == 1e9) continue;
                    if (retdist[k] > retdist[j] + dist[j][k])
                    {
                        retdist[k] = retdist[j] + dist[j][k];
                    }
                }
            }
        }

        bool isPossible = false;
        for (int j = 1; j <= n ; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (dist[j][k] == 1e9) continue;
                if (retdist[k] > retdist[j] + dist[j][k])
                {
                    isPossible = true;
                    break;
                }
            }
            if (isPossible) break;
        }

        if (isPossible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
