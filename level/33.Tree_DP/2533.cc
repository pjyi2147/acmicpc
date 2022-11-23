// acmicpc number: 2533
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;
constexpr int INF = 987654321;

int solve(int r, int p, vector<int> &notadapter, vector<int> &adapter, const vector<vector<int>> &g);

int solven(int r, int p, vector<int>& notadapter, vector<int>& adapter, const vector<vector<int>>& g)
{
    if (notadapter[r] < INF)
        return notadapter[r];

    int temp = 0;
    for (auto ch : g[r])
    {
        if (ch != p)
        {
            temp += solve(ch, r, notadapter, adapter, g);
        }
    }
    return notadapter[r] = temp;
}

int solve(int r, int p, vector<int>& notadapter, vector<int>& adapter, const vector<vector<int>>& g)
{
    if (adapter[r] < INF)
        return adapter[r];

    int temp = 1;
    for (auto ch : g[r])
    {
        if (ch != p)
        {
            temp += min(solve(ch, r, notadapter, adapter, g), solven(ch, r, notadapter, adapter, g));
        }
    }
    return adapter[r] = temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<vector<int>> g(n, vector<int>());

    for (int i = 0; i < n - 1; i++)
    {
        int s, e;
        cin >> s >> e;
        g[s - 1].push_back(e - 1);
        g[e - 1].push_back(s - 1);
    }

    int r = 0;
    vector<int> notadapter(n, INF);
    vector<int> adapter(n, INF);
    solven(r, -1, notadapter, adapter, g);
    solve(r, -1, notadapter, adapter, g);
    cout << min(notadapter[0], adapter[0]);
}