// acmicpc number: 4307
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

ll T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    FOR(i, T)
    {
        int n, l;
        cin >> l >> n;
        int loc[n];
        FOR(j, n)
        {
            cin >> loc[j];
        }

        int h = l / 2 + 1;
        int tmax = 0, tmin = 0;
        FOR(j, n)
        {
            if (loc[j] < h)
            {
                tmin = max(tmin, loc[j]);
                tmax = max(tmax, l - loc[j]);
            }
            else
            {
                tmin = max(tmin, l - loc[j]);
                tmax = max(tmax, loc[j]);
            }
        }
        cout << tmin << " " << tmax << endl;
    }
}
