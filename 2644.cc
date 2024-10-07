// acmicpc number: 2644
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

ll n, m;
int a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> a >> b >> m;

    vii adj(n + 1, vi());
    FOR(i, m)
    {
        int c, d;
        cin >> c >> d;
        adj[c].push_back(d);
        adj[d].push_back(c);
    }

    vi dist(n + 1, -1);
    queue<int> q;
    q.push(a);
    dist[a] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur])
        {
            if (dist[next] != -1) continue;
            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }

    cout << dist[b] << endl;
    return 0;
}
