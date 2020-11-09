// acmicpc number: 14888
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> lst, int* op, int val, int* ma, int* mi, int step)
{
    if (step == lst.size()) 
    {
        if (*ma < val) *ma = val;
        if (*mi > val) *mi = val;
        return;
    }

    if (op[0] > 0) 
    {
        op[0]--;
        solve(lst, op, val+lst[step], ma, mi, step+1);
        op[0]++;
    }
    if (op[1] > 0) 
    {
        op[1]--;
        solve(lst, op, val-lst[step], ma, mi, step+1);
        op[1]++;
    }
    if (op[2] > 0) 
    {
        op[2]--;
        solve(lst, op, val*lst[step], ma, mi, step+1);
        op[2]++;
    }
    if (op[3] > 0) 
    {
        op[3]--;
        solve(lst, op, val/lst[step], ma, mi, step+1);
        op[3]++;
    }
}

void solve(vector<int> lst, int* op)
{
    int ma = INT32_MIN, mi = INT32_MAX;
    solve(lst, op, lst[0], &ma, &mi, 1);
    cout << ma << "\n" << mi;
}

int main()
{
    int n;
    int op[4] = {0};
    vector<int> lst;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        lst.push_back(k);
    }
    cin >> op[0] >> op[1] >> op[2] >> op[3];

    solve(lst, op);
}