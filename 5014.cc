// acmicpc number: 5014
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

ll f, s, g, u, d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> f >> s >> g >> u >> d;

    vi dist(f + 1, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == g) break;

        if (cur + u <= f && dist[cur + u] == -1) {
            dist[cur + u] = dist[cur] + 1;
            q.push(cur + u);
        }

        if (cur - d >= 1 && dist[cur - d] == -1) {
            dist[cur - d] = dist[cur] + 1;
            q.push(cur - d);
        }
    }

    if (dist[g] == -1) cout << "use the stairs" << endl;
    else cout << dist[g] << endl;

    return 0;
}
