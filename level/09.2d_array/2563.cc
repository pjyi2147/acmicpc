// acmicpc number: 2563
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<vector<bool>> white_paper(100, vector<bool>(100, false));

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        for (int a = 0; a < 10; a++)
        {
            for (int b = 0; b < 10; b++)
            {
                white_paper[y + b][x + a] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (white_paper[i][j])
                cnt++;
        }
    }
    cout << cnt;
}