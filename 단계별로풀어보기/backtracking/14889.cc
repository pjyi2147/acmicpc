// acmicpc number:
#include <bits/stdc++.h>
using namespace std;

int n;
int ij[20][20];
vector<int> perm;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ij[i][j];
        }
    }
    for (int i = 0; i < n / 2; i++)
    {
        perm.push_back(0);
    }
    for (int i = 0; i < n / 2; i++)
    {
        perm.push_back(1);
    }

    int diff = INT32_MAX;
    do 
    {
        vector<int> team1, team2;
        int team1_s = 0, team2_s = 0;
        for (int i = 0; i < n; i++)
        {
            if (perm[i]) team1.push_back(i);
            else team2.push_back(i);
        }

        for (int i = 0; i < n/2; i++)
        {
            for (int j = i+1; j < n/2; j++)
            {
                team1_s += ij[team1[i]][team1[j]] + ij[team1[j]][team1[i]];
                team2_s += ij[team2[i]][team2[j]] + ij[team2[j]][team2[i]];
            }
        }

        if (abs(team1_s-team2_s) < diff) diff = abs(team1_s-team2_s);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << diff;
}