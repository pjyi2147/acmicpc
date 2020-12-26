// acmicpc number: 9251
#include <bits/stdc++.h>
using namespace std;

string a, b;
int cache[1001][1001];

int lcs(int a_l, int b_l)
{
    if (a_l == a.size() || b_l == b.size()) return 0;

    int& ret = cache[a_l][b_l];
    if (ret != -1) return ret;

    ret = 0; // a[a_l] ?= b[b_l]
    for (int next = b_l; next < b.size(); next++)
    {
        if (a[a_l] == b[next]) 
        {
            ret = 1 + lcs(a_l+1, next+1);
            break;
        }
    }
    ret = max(ret, lcs(a_l+1, b_l));
    return ret;    
}

int main()
{
    cin >> a >> b;
    memset(cache, -1, sizeof(cache));
    cout << lcs(0, 0);
}