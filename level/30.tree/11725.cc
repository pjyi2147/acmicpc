// acmicpc number: 11725
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<int> tree[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    vector<int> parent(n + 1, -1);
    parent[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto i : tree[u])
        {
            if (parent[i] == -1)
            {
                parent[i] = u;
                q.push(i);
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << endl;
    }
}