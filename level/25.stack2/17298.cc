// acmicpc number: 17298
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> num;
stack<int> ind;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int* ans = new int[n];
    memset(ans, -1, sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        num.push_back(k);   
    }

    for (int i = 0; i < n; i++)
    {
        while (!ind.empty())
        {
            if (num[ind.top()] < num[i])
            {
                ans[ind.top()] = num[i];
                ind.pop();
            }
            else break;
        }
        ind.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}