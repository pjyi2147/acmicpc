// acmicpc number: 1086
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, k;
ll dp[1 << 15][101];
int tens_rem[51];
int n_rem[15];

int rem(const vector<int> &num)
{
    int tmp = 0;
    for (int j = 0; j < num.size(); j++)
    {
        tmp = (tmp + (num[j] * tens_rem[num.size() - 1 - j])) % k;
    }
    return tmp;
}

ll fact(int t)
{
    ll ret = 1;
    for (int i = 2; i <= t; i++)
    {
        ret *= i;
    }
    return ret;
}

ll gcd(ll x, ll y)
{
    if (x < y)
        swap(x, y);
    while (y != 0)
    {
        ll r = x % y;
        x = y;
        y = r;
    }
    return x;
}

ll solve(const vector<vector<int>> &nums)
{
    for (int i = 0; i < (1 << n) - 1; i++)
    {
        for (int q = 0; q < k; q++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!(i & (1 << j)))
                {
                    int newq = (q * tens_rem[nums[j].size()] + n_rem[j]) % k;
                    dp[i | (1 << j)][newq] += dp[i][q];
                }
            }
        }
    }
    return dp[(1 << n) - 1][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    string str;
    getline(cin, str);
    vector<vector<int>> nums(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        for (int j = 0; j < str.size(); j++)
        {
            nums[i].push_back(str[j] - '0');
        }
    }
    cin >> k;
    tens_rem[0] = 1;
    for (int i = 1; i < 51; i++)
    {
        tens_rem[i] = (tens_rem[i - 1] * 10) % k;
    }
    for (int i = 0; i < n; i++)
    {
        n_rem[i] = rem(nums[i]);
    }
    dp[0][0] = 1;
    ll quo = solve(nums);
    ll div = fact(n);
    ll g = gcd(quo, div);
    cout << (quo / g) << "/" << (div / g);
}