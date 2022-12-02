// acmicpc number: 2162
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

struct UF
{
    int *parent;
    int *rank;
    int *cnt;
    
    UF(int n)
    {
        parent = new int[n];
        rank = new int[n];
        cnt = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
            cnt[i] = 1;
        }
    }

    int find(int a)
    {
        if (parent[a] != a)
        {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }

    void merge(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b)
            return;

        if (rank[a] > rank[b])
        {
            parent[b] = a;
            cnt[a] += cnt[b];
        }
        else
        {
            parent[a] = b;
            cnt[b] += cnt[a];
        }
        if (rank[a] == rank[b])
            rank[b]++;
    }

    int count(int a)
    {
        if (parent[a] != a) 
            cnt[a] = cnt[find(a)];
        return cnt[a];
    }

    ~UF()
    {
        delete[] parent;
        delete[] rank;
        delete[] cnt;
    }
};

int ccw(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c)
{
    pair<ll, ll> v1 = {b.first - a.first, b.second - a.second};
    pair<ll, ll> v2 = {c.first - b.first, c.second - b.second};

    ll result = v1.first * v2.second - v1.second * v2.first;
    if (result > 0)
        return 1;
    else if (result < 0)
        return -1;
    else
        return 0;
}

bool cross(pair<pair<int, int>, pair<int, int>> &l1, pair<pair<int, int>, pair<int, int>> &l2)
{
    int ccw1 = ccw(l1.first, l1.second, l2.first);
    int ccw2 = ccw(l1.first, l1.second, l2.second);
    int ccw3 = ccw(l2.first, l2.second, l1.first);
    int ccw4 = ccw(l2.first, l2.second, l1.second);

    if (ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0)
    {
        if (l1.first < l2.second && l2.first < l1.second)
        {
            return true;
        }
        return false;
    }
    if (ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<pair<pair<int, int>, pair<int, int>>> lines;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > c)
        {
            swap(a, c);
            swap(b, d);
        }
        lines.push_back({{a, b}, {c, d}});
    }

    auto uf = new UF(n);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (cross(lines[i], lines[j]))
            {
                uf->merge(i, j);
            }
        }
    }
    int cnt = 0;
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        cnt = max(cnt, uf->count(i));
        if (uf->find(i) == i)
            ret++;
    }
    cout << ret << '\n' << cnt;
}