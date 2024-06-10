// acmicpc number: 18110
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

    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    int score[n];
    FOR(i, n)
    {
        cin >> score[i];
    }

    sort(score, score + n);
    float k = (float)n * 0.15;
    k = round(k);

    int newn = n - 2 * k;
    float scoresum = 0;
    for (int i = k; i < n - k; i++)
    {
        scoresum += score[i];
    }
    cout << (int)round(scoresum / newn);
    return 0;
}
