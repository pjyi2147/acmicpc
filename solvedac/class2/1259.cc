// acmicpc number: 1259
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

string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> s)
    {
        if (s == "0") return 0;

        int a = 0, b = s.size() - 1;
        bool pal = true;
        while (a < b)
        {
            if (s[a] != s[b])
            {
                pal = false;
                break;
            }
            a++; b--;
        }
        if (pal) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
