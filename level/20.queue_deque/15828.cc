// acmicpc number: 15828
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    queue<int> r;

    int k;
    while (cin >> k && k != -1)
    {
        if (k == 0) r.pop();
        else if (r.size() < n) 
        {
            r.push(k);
        }
    }

    if (r.empty())
    {
        cout << "empty";
        return 0;
    }
    while(!r.empty())
    {
        cout << r.front() << " ";
        r.pop();
    }
}