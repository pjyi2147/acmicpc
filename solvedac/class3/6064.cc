// acmicpc number: 6064
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

ll t, n, m, x, y;

int gcd(int a, int b)
{
    if (a < b)
    {
        swap(a, b);
    }

    while (b != 0)
    {
        int n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    FOR(rep, t)
    {
        cin >> m >> n >> x >> y;
        int maxlcm = lcm(m, n);
        int ret = 0;
        bool suc = false;

        ret += x;
        while (ret <= maxlcm)
        {
            if (ret % n == (y % n))
            {
                suc = true;
                break;
            }
            ret += m;
        }
        if (suc)
            cout << ret << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}
