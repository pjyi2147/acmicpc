// acmicpc number: 11053
#include <bits/stdc++.h>
using namespace std;

int n = 0;
vector<int> seq;
int cache[1001];

int solve(int loc)
{
    int& ret = cache[loc+1];
    if (ret != -1) return ret;

    ret = 1;
    for (int next = loc+1; next < n; ++next)
    {
        if (loc == -1 || seq[loc] < seq[next])
        {
            ret = max(ret, 1 + solve(next));
        }
    }
    return ret;
}

int main()
{
    cin >> n;
    memset(cache, -1, sizeof(cache));
    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        seq.push_back(k);
    }
    cout << solve(-1) - 1;
}