// acmicpc number: 9252
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void LCS(vector<vector<int>> &sol, vector<vector<int>> &tra, const string &a, const string &b)
{
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                sol[i][j] = sol[i - 1][j - 1] + 1;
                tra[i][j] = 1;
            }
            else if (sol[i - 1][j] > sol[i][j - 1])
            {
                sol[i][j] = sol[i - 1][j];
                tra[i][j] = 2;
            }
            else
            {
                sol[i][j] = sol[i][j - 1];
                tra[i][j] = 0;
            }
        }
    }
}

void printLCS(const vector<vector<int>> &tra, string &a)
{
    int i = tra.size() - 1, j = tra[0].size() - 1;
    string ret = "";
    while (i > 0 && j > 0)
    {
        if (tra[i][j] == 1)
        {
            ret = a[i - 1] + ret;
            i--;
            j--;
        }
        else if (tra[i][j] == 2)
        {
            i--;
        }
        else if (tra[i][j] == 0)
        {
            j--;
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;
    getline(cin, a);
    getline(cin, b);
    vector<vector<int>> sol(a.size() + 1, vector<int>(b.size() + 1, 0));
    vector<vector<int>> tra(a.size() + 1, vector<int>(b.size() + 1, -1));
    LCS(sol, tra, a, b);
    cout << sol[a.size()][b.size()] << '\n';
    if (sol[a.size() - 1][b.size() - 1] > 0)
    {
        printLCS(tra, a);
    }
}