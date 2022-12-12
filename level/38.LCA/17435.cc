// acmicpc number: 17435
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m, q, x;
int sp_tbl[19][200001];

void print()
{
    int d = log2(n);
    int ret = x;
    for (int i = d; i >= 0; i--)
    {
        if (n & (1 << i))
            ret = sp_tbl[i][ret];
    }
    cout << ret << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> sp_tbl[0][i];
    }

    for (int k = 1; k <= 18; k++)
    {
        for (int i = 1; i <= m; i++)
        {
            int tmp = sp_tbl[k - 1][i];
            sp_tbl[k][i] = sp_tbl[k - 1][tmp];
        }
    }

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> n >> x;
        print();
    }
}