// acmicpc number: 2738
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int tmp;
            cin >> tmp;
            a[i][j] += tmp;
        }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}