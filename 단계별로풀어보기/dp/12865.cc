// acmicpc number: 12865
#include <bits/stdc++.h>
using namespace std;

int n, k;
int cache[101][100001];
int v[101], w[101];

int knapsack(int loc, int cap)
{
    if (loc == n) return 0;
    int& ret = cache[loc][cap];
    if (ret != -1) return ret;
    
    ret = knapsack(loc+1, cap);
    if (cap >= w[loc])
        ret = max(v[loc] + knapsack(loc+1, cap-w[loc]), ret);
    return ret;
}

int main()
{
    cin >> n >> k;
    memset(cache, -1, sizeof(cache));
    
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    cout << knapsack(0, k);
}