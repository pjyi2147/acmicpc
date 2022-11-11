// acmicpc number: 13913
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, k;
constexpr int INF = 987654321;

void print(vector<int> &hop, int p)
{
    if (p % 2 == 0 && hop[p / 2] + 1 == hop[p])
        print(hop, p / 2);
    else if (p > 0 && hop[p - 1] + 1 == hop[p])
        print(hop, p - 1);
    else if (p < 100000 && hop[p + 1] + 1 == hop[p])
        print(hop, p + 1);
    cout << p << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    vector<int> hop(100001, INF);

    hop[n] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, n});
    while (!pq.empty())
    {
        auto u = pq.top().second;
        auto c = pq.top().first;
        pq.pop();
        if (hop[u] < c)
            continue;

        if (u == k)
        {
            cout << c << '\n';
            break;
        }

        if (2 * u <= 100000 && hop[2 * u] > hop[u] + 1)
        {
            hop[u * 2] = hop[u] + 1;
            pq.push({hop[u * 2], u * 2});
        }
        if (u < 100000 && hop[u + 1] > hop[u] + 1)
        {
            hop[u + 1] = hop[u] + 1;
            pq.push({hop[u + 1], u + 1});
        }
        if (u > 0 && hop[u - 1] > hop[u] + 1)
        {
            hop[u - 1] = hop[u] + 1;
            pq.push({hop[u - 1], u - 1});
        }
    }

    print(hop, k);
}