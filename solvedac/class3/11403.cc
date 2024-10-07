// acmicpc number: 11403
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = (a); i < (b); i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<int> vi;
typedef vector<vi> vii;

ll n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vii con(n, vector<int>());
    vii ret(n, vector<int>(n, 0));

    FOR(i, n)
    {
        FOR(j, n)
        {
            int temp;
            cin >> temp;
            if (temp)
            {
                con[i].push_back(j);
                ret[i][j] = 1;
            }
        }
    }

    FOR(m, n)
    {
        FOR(a, n)
        {
            FOR(b, n)
            {
                if (ret[a][m] && ret[m][b])
                {
                    ret[a][b] = 1;
                }
            }
        }
    }

    FOR(a, n)
    {
        FOR(b, n)
        {
            cout << ret[a][b] << " ";
        }
        cout << '\n';
    }
    return 0;
}
