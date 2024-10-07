// acmicpc number: 14500
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

ll n, m;

vector<pii> cwspin(const vector<pii> &mino)
{
    vector<pii> ret;
    for (auto p : mino)
    {
        ret.push_back({p.second, -p.first});
    }
    return ret;
}

vector<pii> xaxisflip(const vector<pii> &mino)
{
    vector<pii> ret;
    for (auto p : mino)
    {
        ret.push_back({-p.first, p.second});
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    vii num(n, vector<int>(m, 0));

    FOR(i, n)
    {
        FOR(j, m)
        {
            cin >> num[i][j];
        }
    }

    vector<vector<pii>> minos = {
        // blue
        {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
        // yellow
        {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
        // orange
        {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
        // green
        {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
        // purple
        {{0, 0}, {-1, 0}, {1, 0}, {0, 1}}};

    int ret = 0;
    FOR(a, n)
    {
        FOR(b, m)
        {
            for (auto mi : minos)
            {
                FOR(i, 4)
                {
                    int temp_sum = 0;
                    bool val = true;
                    for (auto p : mi)
                    {
                        p.first += a;
                        p.second += b;
                        if (p.first < n && p.first >= 0 && p.second < m && p.second >= 0)
                        {
                            temp_sum += num[p.first][p.second];
                        }
                        else
                        {
                            val = false;
                            break;
                        }
                    }

                    if (val && temp_sum > ret)
                    {
                        ret = temp_sum;
                    }
                    mi = cwspin(mi);
                }

                mi = xaxisflip(mi);

                FOR(i, 4)
                {
                    int temp_sum = 0;
                    bool val = true;
                    for (auto p : mi)
                    {
                        p.first += a;
                        p.second += b;
                        if (p.first < n && p.first >= 0 && p.second < m && p.second >= 0)
                        {
                            temp_sum += num[p.first][p.second];
                        }
                        else
                            val = false;
                    }

                    if (val && temp_sum > ret)
                    {
                        ret = temp_sum;
                    }
                    mi = cwspin(mi);
                }
            }
        }
    }
    cout << ret;
}
