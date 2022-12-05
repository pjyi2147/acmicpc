// acmicpc number: 1786
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string T, P;

vector<int> fail()
{
    vector<int> fail_array(P.size(), 0);
    fail_array[0] = 0;
    int j = 1, l = 0;
    while (j < P.size())
    {
        if (P[j] == P[l])
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

void kmp()
{
    int i = 0, j = 0;
    vector<int> fail_array = fail();
    vector<int> idx;
    while (i < T.size())
    {
        if (P[j] == T[i])
        {
            if (j == P.size() - 1)
            {
                idx.push_back(i - j + 1);
                if (j > 0) j = fail_array[j - 1];
                else
                    i++;
            }
            else
            {
                i++;
                j++;
            }
        }
        else
        {
            if (j > 0)
            {
                j = fail_array[j - 1];
            }
            else
                i++;
        }
    }
    cout << idx.size() << '\n';
    for (auto i : idx)
    {
        cout << i << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    getline(cin, T);
    getline(cin, P);
    kmp();
}