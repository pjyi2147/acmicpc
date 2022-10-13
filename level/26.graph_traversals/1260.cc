// acmicpc number: 1260
#include <bits/stdc++.h>
using namespace std;

int n, m, v;

void bfs(int v, vector<vector<bool>>& a, vector<bool> b) {
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (b[cur]) cout << cur + 1 << " ";
        b[cur] = false;
        for (int i = 0; i < n; i++) {
            if (a[cur][i] && b[i]) {
                q.push(i);
            }
        }
    }
    cout << "\n";
}

void dfs(int v, vector<vector<bool>>& a, vector<bool>& b) {
    b[v] = false;
    cout << v + 1 << " ";
    for (int i = 0; i < n; i++) {
        if (a[v][i] && b[i]) {
            dfs(i, a, b);
        }
    }
}

void dfs_s(int v, vector<vector<bool>>& a, vector<bool> b) {
    dfs(v, a, b);
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> v;
    vector<vector<bool>> a(n, vector<bool>(n, false));
    vector<bool> b(n, true);

    for (int i = 0; i < m; i++)
    {
        int a1, a2;
        cin >> a1 >> a2;
        a[a1 - 1][a2 - 1] = true; 
        a[a2 - 1][a1 - 1] = true;  
    }

    dfs_s(v - 1, a, b);
    bfs(v - 1, a, b);
}