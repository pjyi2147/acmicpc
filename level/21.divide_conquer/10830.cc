// acmicpc number: 10830
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> b;

    vector<vector<ll>> a(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> c(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
    {
        c[i][i] = 1;
    }

    while (b)
    {
        if (b % 2)
        {
            vector<vector<ll>> d(n, vector<ll>(n, 0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int l = 0; l < n; l++)
                    {
                        d[i][j] += c[i][l] * a[l][j];
                    }
                    d[i][j] %= 1000;
                }
            }
            c = d;
        }
        vector<vector<ll>> d(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int l = 0; l < n; l++)
                {
                    d[i][j] += a[i][l] * a[l][j];
                }
                d[i][j] %= 1000;
            }
        }
        a = d;
        b /= 2;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
}