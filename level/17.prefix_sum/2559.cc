// acmicpc number: 2559
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<int> v(n);
    vector<int> s(n - m + 1);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i < m) {
            s[0] += v[i];
        } else {
            s[i - m + 1] = s[i - m] + v[i] - v[i - m];
        }
    }
    cout << *max_element(s.begin(), s.end()) << '\n';
}
