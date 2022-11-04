// acmicpc number: 1806
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, k;
const int INF = 987654321;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int s = 0, e = 0;
    int sum = v[0];
    int length = INF;
    while (s <= e && e < n)
    {
        if (sum >= k) 
        {
            length = min(length, e - s + 1);
            if (s == e) break;
            else sum -= v[s++];
        }
        else sum += v[++e];
        
    }
    cout << (length == INF ? 0 : length);
}