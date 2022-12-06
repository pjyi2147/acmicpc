// acmicpc number: 1305
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;
string str;

vector<int> fail()
{
    vector<int> fail_array(str.size(), 0);
    fail_array[0] = 0;
    int j = 1, l = 0;
    while (j < str.size())
    {
        if (str[j] == str[l])
        {
            l++;
            fail_array[j] = l;
            j++;
        }
        else if (l > 0)
        {
            l = fail_array[l - 1];
        }
        else
        {
            fail_array[j] = 0;
            j++;
        }
    }
    return fail_array;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> str;
    vector<int> f;
    f = fail();
    cout << str.size() - f[str.size() - 1];
}
