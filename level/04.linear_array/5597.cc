// acmicpc number: 5597
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<bool> check(30, false);
    for (int i = 0; i < 30; i++)
    {
        int k;
        cin >> k;
        check[k - 1] = true;
    }

    for (int i = 0; i < 30; i++)
    {
        if (check[i] == false)
            cout << i + 1 << "\n";
    }
}