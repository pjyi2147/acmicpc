// acmicpc number: 28702
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i=(a); i < (b); i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<int> vi;
typedef vector<vi> vii;

string a, b, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;

    if (a[0] >= '1' && a[0] <= '9')
    {
        int k = stoi(a) + 3;
        if (k % 3 == 0)
        {
            if (k % 5 == 0) cout << "FizzBuzz";
            else cout << "Fizz";
        }
        else if (k % 5 == 0) cout << "Buzz";
        else cout << k;
        return 0;
    }
    else if (b[0] >= '1' && b[0] <= '9')
    {
        int k = stoi(b) + 2;
        if (k % 3 == 0)
        {
            if (k % 5 == 0) cout << "FizzBuzz";
            else cout << "Fizz";
        }
        else if (k % 5 == 0) cout << "Buzz";
        else cout << k;
        return 0;
    }

    int k = stoi(c) + 1;
    if (k % 3 == 0)
    {
        if (k % 5 == 0) cout << "FizzBuzz";
        else cout << "Fizz";
    }
    else if (k % 5 == 0) cout << "Buzz";
    else cout << k;
    return 0;
}
