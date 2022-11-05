// acmicpc number: 1644
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

constexpr int MAX = 4000001;
int n;
bool prime[MAX];

void net()
{
    memset(prime, false, MAX);
    prime[2] = true;
    prime[3] = true;

    for (int i = 5; i <= MAX; i += 6)
        prime[i] = true;
    for (int i = 7; i <= MAX; i += 6)
        prime[i] = true;

    for (int i = 5; i <= MAX; i += 2)
    {
        if (!prime[i]) continue;

        for (int j = 1; (2 * j + 1) * i <= MAX; j++)
            prime[(2 * j + 1) * i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    net();
    vector<int> pv;

    for (int i = 2; i <= MAX; i++)
    {
        if (prime[i])
        {
            pv.push_back(i);
        }
    }

    int ret = 0, left = 0, right = 0, sum = 2;
    while (left <= right && right < pv.size())
    {
        if (sum == n)
        {
            ret += 1;
            sum -= pv[left++];
        }
        else if (sum < n)
            sum += pv[++right];
        else
            sum -= pv[left++];
    }
    cout << ret;
}