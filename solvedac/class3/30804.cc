// acmicpc number: 30804
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

ll n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<int> cnt(9, 0);
    queue<int> q;
    int mlen = 0;
    FOR(i, n)
    {
        int f;
        cin >> f;
        f -= 1;
        q.push(f);
        cnt[f]++;

        int fcnt = 0;
        FOR (j, 9)
        {
            if (cnt[j] > 0) fcnt++;
        }

        while (fcnt > 2)
        {
            int ff = q.front();
            q.pop();
            cnt[ff]--;

            fcnt = 0;
            FOR (j, 9)
            {
                if (cnt[j] > 0) fcnt++;
            }
        }
        mlen = max(mlen, (int)q.size());
    }
    cout << mlen;
}
