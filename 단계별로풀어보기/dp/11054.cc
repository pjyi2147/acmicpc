// acmicpc number: 11054
#include <bits/stdc++.h>
using namespace std;

int n = 0;
int seq[1000];
int rlis[1000];
int llis[1000];

int R_lis(int loc)
{
    int& ret = rlis[loc];
    if (ret != -1) return ret;

    ret = 1;
    for (int next = loc+1; next < n; next++)
    {
        if (seq[loc] > seq[next]) 
        {
            ret = max(ret, 1 + R_lis(next));
        }
    }
    return ret;
}

int L_lis(int loc)
{
    int& ret = llis[loc];
    if (ret != -1) return ret;

    ret = 1;
    for (int next = loc-1; next >= 0; next--)
    {
        if (seq[loc] > seq[next]) 
        {
            ret = max(ret, 1 + L_lis(next));
        }
    }
    return ret;
}

int main()
{
    cin >> n;
    memset(rlis, -1, sizeof(rlis));
    memset(llis, -1, sizeof(llis));
    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
    }
    for (int i = 0; i < n; i++)
    {
        R_lis(i);
        L_lis(i);
    }

    int ret = -1;
    for (int i = 0; i < n; i++)
    {
        ret = max(ret, rlis[i]+llis[i]-1);
    }
    cout << ret;
}