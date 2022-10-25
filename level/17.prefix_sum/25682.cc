// acmicpc number: 25682
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    vector<vector<int>> st_sum(n, vector<int>(m, 0));

    // assume first cell is white
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == 'W') 
            {
                if ((i+j)%2==1) st_sum[i][j] = 1;
            }
            else 
            {
                if ((i+j)%2==0) st_sum[i][j] = 1;
            }
            if (j > 0) st_sum[i][j] += st_sum[i][j-1];
            if (i > 0) st_sum[i][j] += st_sum[i-1][j];
            if (i > 0 && j > 0) st_sum[i][j] -= st_sum[i-1][j-1];
        }
    }

    int px = m - k + 1;
    int py = n - k + 1;

    int ret = k*k;
    for (int i = 0; i < py; i++)
    {
        for (int j = 0; j < px; j++)
        {
            int tmp = st_sum[i+k-1][j+k-1];
            if (i > 0) tmp -= st_sum[i-1][j+k-1];
            if (j > 0) tmp -= st_sum[i+k-1][j-1];
            if (i > 0 && j > 0) tmp += st_sum[i-1][j-1];
            if (tmp > k*k/2) tmp = k*k - tmp;
            ret = min(ret, tmp);
        }
    }
    cout << ret;
}