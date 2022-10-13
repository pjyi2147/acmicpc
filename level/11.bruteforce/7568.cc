// acmicpc number: 7568
#include <bits/stdc++.h>
using namespace std;

bool compw(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first && a.second < b.second;
}

int main()
{
    vector<pair<int, int>> h;
    vector<int> place;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int w, he;
        cin >> w >> he;
        h.push_back(make_pair(w, he));
    }

    for (int i = 0; i < n; i++)
    {
        auto p = h[i];
        int win = 0, draw = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            auto k = h[j];
            if (compw(k, p)) win++;
            else if (!compw(p, k)) draw++;
        }
        place.push_back(n - win - draw);
    }

    for (auto a : place)
    {
        cout << a << ' ';
    }
    cout << "\n";
}