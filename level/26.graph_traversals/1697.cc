// acmicpc number: 1697
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, k;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;

    vector<int> visited(100001, -1);
    visited[n] = 0;
    queue<int> q;
    q.push(n);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u * 2 <= 100000 && visited[u*2] == -1)
        {
            visited[u*2] = visited[u] + 1;
            q.push(u*2);
            if (u * 2 == k) break;
        }
        if (u + 1 <= 100000 && visited[u+1] == -1)
        {
            visited[u+1] = visited[u] + 1;
            q.push(u+1);
            if (u + 1 == k) break;
        }
        if (u - 1 >= 0 && visited[u-1] == -1)
        {
            visited[u-1] = visited[u] + 1;
            q.push(u-1);
            if (u - 1 == k) break;
        }
    }
    cout << visited[k];
}