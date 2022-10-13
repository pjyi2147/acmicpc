// acmicpc number: 2477
#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<int> xs, ys;
    vector<int> v;
    for (int i = 0; i < 6; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(b);
        if (a == 1 || a == 2) {
            xs.push_back(b);
        } else {
            ys.push_back(b);
        }
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    int xmax = xs[2], ymax = ys[2];
    int area = xmax * ymax;

    auto idx = find(v.begin(), v.end(), ymax) - v.begin();
    if (v[(idx + 1) % 6] == xmax) {
        area -= v[(idx + 3) % 6] * v[(idx + 4) % 6];
    } else {
        area -= v[(idx + 2) % 6] * v[(idx + 3) % 6];
    }
    cout << area * n << endl;
    return 0;
}
