// acmicpc number: 1463
#include <bits/stdc++.h>
using namespace std;

int n;
const int INF = 1000002;
const int MAX_N = 1000001;
int cache[MAX_N];

int solve(int n)
{
    if (n == 1) return 0;
    int& ret = cache[n];

    if (ret != -1) return ret;
    ret = INF;
    if (n % 3 == 0) ret = min(ret, 1 + solve(n/3));
    if (n % 2 == 0) ret = min(ret, 1 + solve(n/2));
    return ret = min(ret, 1 + solve(n-1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(cache, -1, sizeof(cache));

    cin >> n;
    cout << solve(n);
}