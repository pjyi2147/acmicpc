// acmicpc number: 1107
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
vi broken;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    broken.resize(m);
    FOR(i, m) cin >> broken[i];

    ll ans = abs(n - 100);

    FOR(i, 1000000)
    {
        string s = to_string(i);
        bool flag = false;
        FOR(j, s.size())
        {
            FOR(k, m)
            {
                if (s[j] == broken[k] + '0')
                {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag)
        {
            ans = min(ans, (ll)s.size() + abs(n - i));
        }
    }

    cout << ans << '\n';
}
