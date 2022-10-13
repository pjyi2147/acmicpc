// acmicpc number: 11444
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    
    vector<vector<ll>> a(2, vector<ll>(2, 0));
    a[0][0] = 0;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 1;

    vector<vector<ll>> c(2, vector<ll>(2, 0));
    c[0][0] = 1;
    c[0][1] = 0;
    c[1][0] = 0;
    c[1][1] = 1;

    while (n) 
    {
        if (n % 2) {
            vector<vector<ll>> d(2, vector<ll>(2, 0));
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    for (int l = 0; l < 2; l++) {
                        d[i][j] += c[i][l] * a[l][j];
                    }
                    d[i][j] %= 1000000007;
                }
            }
            c = d;
        }
        vector<vector<ll>> d(2, vector<ll>(2, 0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int l = 0; l < 2; l++) {
                    d[i][j] += a[i][l] * a[l][j];
                }
                d[i][j] %= 1000000007;
            }
        }
        a = d;
        n /= 2;
    }

    cout << c[0][1] << "\n";
}