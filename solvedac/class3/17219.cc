// acmicpc number: 17219
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    map<string, string> save;

    FOR(i, n)
    {
        string a, b;
        cin >> a >> b;
        save[a] = b;
    }

    FOR(i, m)
    {
        string a;
        cin >> a;
        cout << save[a] << '\n';
    }
    return 0;
}
