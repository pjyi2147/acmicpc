// acmicpc number: 5525
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
string str;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> str;

    int idx = 0, ioicnt = 0, pncnt = 0;
    while (idx < m)
    {
        if (str[idx] == 'I' && str[idx + 1] == 'O' && str[idx + 2] == 'I')
        {
            idx += 2;
            ioicnt += 1;
        }
        else
        {
            ioicnt = 0;
            idx++;
        }

        if (ioicnt >= n)
        {
            pncnt++;
        }
    }
    cout << pncnt;
}
