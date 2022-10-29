// acmicpc number: 1707
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int k, v, e;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k;
    
    for (int t = 0; t < k; t++)
    {
        cin >> v >> e;
        bool bipar = true;
        vector<vector<int>> g(v, vector<int>());
        vector<int> visited(v, -1);
        for (int i = 0; i < e; i++)
        {
            int r, q;
            cin >> r >> q;
            g[r-1].push_back(q-1);
            g[q-1].push_back(r-1);
        }

        for (int i = 0; i < v; i++)
        {
            if (visited[i] == -1)
            {
                queue<int> q;
                visited[i] = 0;
                q.push(i);

                while (!q.empty())
                {
                    auto u = q.front();
                    q.pop();

                    for (auto ch : g[u])
                    {
                        if (visited[ch] == -1) 
                        {
                            visited[ch] = visited[u] + 1;
                            q.push(ch);
                        }
                        else if (visited[ch] % 2 == visited[u] % 2) 
                        {
                            bipar = false;
                            break;
                        }
                    }
                }
            }
            if (!bipar) break;
        }
        bipar ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}