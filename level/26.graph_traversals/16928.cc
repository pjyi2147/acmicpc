// acmicpc number: 16928
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int lad[101];
    int visited[101];
    memset(lad, -1, sizeof(int)*101);
    memset(visited, -1, sizeof(int)*101);
    cin >> n >> m;
    for (int i = 0; i < n + m; i++)
    {
        int s;
        cin >> s >> lad[s];
    }

    queue<int> q;
    visited[1] = 0;
    q.push(1);
    
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            int tmp = u + i;
            if (visited[tmp] != -1) continue;
            if (tmp == 100) 
            {
                cout << visited[u] + 1;
                return 0;
            }
            if (lad[tmp] > 0) 
            {
                visited[tmp] = visited[u] + 1;
                if (visited[lad[tmp]] != -1) continue;
                visited[lad[tmp]] = visited[tmp];
                q.push(lad[tmp]);
            }
            else 
            {
                visited[tmp] = visited[u] + 1;
                q.push(tmp);
            }
        }
    }
}