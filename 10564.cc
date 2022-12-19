// acmicpc number: 10564
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll T, n, m;

void solve(const vector<int> &score)
{
    vector<int>* prev = new vector<int>(n + 1, -1);
    vector<int>* cur = new vector<int>(n + 1, -1);
    for (auto s : score)
    {
        if (s <= n) prev->at(s) = s;
    }
    int ret = prev->at(n);
    bool check = false;
    for (int i = 2; i <= 100; i++)
    {
        if ((score[0] * (score[0] - 1)) / 2 > n)
            break;
        for (int j = 1; j <= n; j++)
        {
            if (prev->at(j) == -1)
                continue;
            for (auto s : score)
            {
                int next = i * s + j;
                if (next > n) 
                {
                    break;
                }
                cur->at(next) = max(cur->at(next), prev->at(j) + s);
            }
        }
        ret = max(ret, cur->at(n));
        delete prev;
        prev = cur;
        cur = new vector<int>(n + 1, -1);
    }
    cout << ret << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n >> m;
        vector<int> score;
        for (int i = 0; i < m; i++)
        {
            int s;
            cin >> s;
            score.push_back(s);
        }
        sort(score.begin(), score.end());
        solve(score);
    }
}