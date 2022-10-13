// acmicpc number: 2630
#include <bits/stdc++.h>
using namespace std;

int n;

void div_conquer(vector<vector<int>>& v, int xs, int xe, int ys, int ye, int& b, int& w)
{
    if (xs == xe) {
        if (v[xs][ys] == 1) b++;
        else w++;
        return;
    }

    int size = (xe - xs) + 1;

    int fcolor = v[xs][ys];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (v[xs + i][ys + j] != fcolor) {
                int midx = (xs + xe) / 2;
                int midy = (ys + ye) / 2;
                div_conquer(v, xs, midx, ys, midy, b, w);
                div_conquer(v, xs, midx, midy + 1, ye, b, w);
                div_conquer(v, midx + 1, xe, ys, midy, b, w);
                div_conquer(v, midx + 1, xe, midy + 1, ye, b, w);
                return;
            }
        }
    }
    if (v[xs][ys] == 0) w++;
    else b++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int b = 0, w = 0;
    div_conquer(a, 0, n - 1, 0, n - 1, b, w);
    cout << w << '\n' << b << '\n';
}