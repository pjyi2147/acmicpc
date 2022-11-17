// acmicpc number: 5639
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void printpost(int s, int e, const vector<int>& pre)
{
    if (s > e)
        return;
    int root = pre[s];
    int it = e + 1;
    for (int i = s + 1; i <= e; i++)
    {
        if (pre[i] > root)
        {
            it = i;
            break;
        }
    }
    printpost(s + 1, it - 1, pre);
    printpost(it, e, pre);
    cout << root << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> pre;
    int k;
    while (cin >> k)
    {
        pre.push_back(k);
    }

    printpost(0, pre.size() - 1, pre);
}