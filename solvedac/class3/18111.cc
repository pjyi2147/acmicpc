// acmicpc number: 18111
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

ll n, m, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> b;
    int heights[257] = {0, }, ht[257], t = INT32_MAX;
    memset(heights, 0, sizeof(int) * 256);
    FOR(i, n * m)
    {
        int temp;
        cin >> temp;
        heights[temp]++;
    }

    int minh = 256, maxh = 0;
    FOR(i, 257)
    {
        ht[i] = INT32_MAX;
        if (heights[i] > 0)
        {
            maxh = max(maxh, i);
            if (i <= maxh) minh = min(minh, i);
        }
    }

    FOR(tgt, 257)
    {
        int req = 0, rem = 0;
        FOR(i, 257)
        {
            if (tgt > i)
            {
                req += (tgt - i) * heights[i];
            }
            else if (tgt < i)
            {
                rem += (i - tgt) * heights[i];
            }
        }

        if (req <= rem + b)
        {
            ht[tgt] = req + 2 * rem;
        }
    }

    int th = 0;
    FOR(i, 257)
    {
        if (ht[i] <= t)
        {
            t = ht[i];
            th = max(th, i);
        }
    }

    cout << t << " " << th;
}
