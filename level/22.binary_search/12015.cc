// acmicpc number: 12015
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    vector<int> LIS;
    vector<int> v(n);
    LIS.push_back(0);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (LIS.back() < v[i]) LIS.push_back(v[i]);
        else {
            int l = 0, r = LIS.size() - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (LIS[m] < v[i]) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            LIS[l] = v[i];
        }
    }
    cout << LIS.size() - 1; 
}