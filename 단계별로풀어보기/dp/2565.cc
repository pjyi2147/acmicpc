// acmicpc number: 2565
#include <bits/stdc++.h>
using namespace std;

const int MAX_ = 500;
int n;
int seq[500];
int pline[100];
int cache[101];

int solve(int loc)
{
    int& ret = cache[loc+1];
    if (ret != -1) return ret;

    ret = 1;
    for (int next = loc+1; next < n; next++)
    {
        if (loc == -1 || pline[loc] < pline[next])
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
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        seq[a-1] = b;
    }

    int loc = 0;
    for (int i = 0; i < MAX_; i++)
    {
        if (seq[i] != 0)
        {
            pline[loc] = seq[i];
            loc++;
        }
    }
    cout << n - (solve(-1) -1);
}