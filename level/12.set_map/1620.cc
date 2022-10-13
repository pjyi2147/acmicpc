// acmicpc number: 1620
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    map<string, string> mapis;
    map<string, string> mapsi;
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        mapis[to_string(i + 1)] = x;
        mapsi[x] = to_string(i + 1);
    }
    for (int i = 0; i < m; ++i) {
        string x;
        cin >> x;
        if (isdigit(x[0])) {
            cout << mapis[x] << "\n";
        } else {
            cout << mapsi[x] << "\n";
        }
    }
}