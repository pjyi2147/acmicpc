// acmicpc number: 9019
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, T;
constexpr int INF = 987654321;

int D(int k)
{
    return (2 * k) % 10000;
}

int S(int k)
{
    return (k == 0) ? 9999 : k - 1;
}

int L(int k)
{
    return (k * 10) % 10000 + k / 1000;
}

int R(int k)
{
    return (k / 10) + (k % 10) * 1000;
}

int RevD1(int k)
{
    return ((k / 2) % 10000);
}

int RevD2(int k)
{
    return ((k + 10000) / 2) % 10000;
}

int RevS(int k)
{
    return (k == 9999) ? 0 : k + 1;
}

void print(int idx, const vector<int>& dist)
{
    if (dist[R(idx)] + 1 == dist[idx])
    {
        print(R(idx), dist);
        cout << 'L';
        return;
    }
    if (dist[L(idx)] + 1 == dist[idx])
    {
        print(L(idx), dist);
        cout << 'R';
        return;
    }
    if (dist[RevS(idx)] + 1 == dist[idx])
    {
        print(RevS(idx), dist);
        cout << 'S';
        return;
    }
    if (idx % 2 == 0 && dist[RevD1(idx)] + 1 == dist[idx])
    {
        print(RevD1(idx), dist);
        cout << 'D';
        return;
    }
    if (idx % 2 == 0 && dist[RevD2(idx)] + 1 == dist[idx])
    {
        print(RevD2(idx), dist);
        cout << 'D';
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int a, b;
        cin >> a >> b;

        vector<int> dist(10001, INF);
        dist[a] = 0;

        queue<int> pq;
        pq.push(a);

        while (!pq.empty())
        {
            auto u = pq.front();
            pq.pop();
            if (u == b)
                break;
            if (dist[D(u)] == INF)
            {
                dist[D(u)] = dist[u] + 1;
                pq.push(D(u));
            }
            if (dist[S(u)] == INF)
            {
                dist[S(u)] = dist[u] + 1;
                pq.push(S(u));
            }
            if (dist[L(u)] == INF)
            {
                dist[L(u)] = dist[u] + 1;
                pq.push(L(u));
            }
            if (dist[R(u)] == INF)
            {
                dist[R(u)] = dist[u] + 1;
                pq.push(R(u));
            }
        }

        print(b, dist);
        cout << '\n';
    }
}