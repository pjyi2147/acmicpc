// acmicpc number: 2357
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;

int initmax(int idx, int s, int e, vector<int> &maxtree, vector<int> &vec)
{
    if (s == e)
    {
        maxtree[idx] = vec[s];
        return maxtree[idx];
    }

    int mid = (s + e) / 2;
    return maxtree[idx] = max(initmax(idx * 2, s, mid, maxtree, vec), initmax(idx * 2 + 1, mid + 1, e, maxtree, vec));
}

int initmin(int idx, int s, int e, vector<int> &mintree, vector<int> &vec)
{
    if (s == e)
    {
        mintree[idx] = vec[s];
        return mintree[idx];
    }

    int mid = (s + e) / 2;
    return mintree[idx] = min(initmin(idx * 2, s, mid, mintree, vec), initmin(idx * 2 + 1, mid + 1, e, mintree, vec));
}

int querymin(int idx, int s, int e, int qs, int qe, vector<int>& mintree)
{
    if (qe < s || e < qs)
        return INT_MAX;
    
    if (qs <= s && e <= qe)
        return mintree[idx];

    int mid = (s + e) / 2;
    return min(querymin(idx * 2, s, mid, qs, qe, mintree), querymin(idx * 2 + 1, mid + 1, e, qs, qe, mintree));
}

int querymin(int s, int e, vector<int>& mintree)
{
    return querymin(1, 0, n - 1, s, e, mintree);
}

int querymax(int idx, int s, int e, int qs, int qe, vector<int>& maxtree)
{
    if (qe < s || e < qs)
        return 0;
    
    if (qs <= s && e <= qe)
        return maxtree[idx];

    int mid = (s + e) / 2;
    return max(querymax(idx * 2, s, mid, qs, qe, maxtree), querymax(idx * 2 + 1, mid + 1, e, qs, qe, maxtree));
}

int querymax(int s, int e, vector<int>& maxtree)
{
    return querymax(1, 0, n - 1, s, e, maxtree);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    vector<int> vec(n, 0);
    vector<int> mintree(4 * n, 0);
    vector<int> maxtree(4 * n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    initmax(1, 0, n - 1, maxtree, vec);
    initmin(1, 0, n - 1, mintree, vec);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << querymin(a - 1, b - 1, mintree) << " " << querymax(a - 1, b - 1, maxtree) << "\n";
    }
}