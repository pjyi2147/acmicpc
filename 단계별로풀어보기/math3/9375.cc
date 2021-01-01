// acmicpc number: 9375
#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        map<string, int> closet;
        int clothes = 0;
        cin >> clothes;
        for (int j = 0; j < clothes; j++)
        {
            string name, cate;
            cin >> name >> cate;
            auto it = closet.find(cate);
            if (it == closet.end())
            {
                closet.insert(make_pair(cate, 1));
            }
            else 
            {
                it->second++;
            }
        }
        int sum = 1;
        for (auto& it : closet)
        {
            sum *= (it.second+1);
        }
        cout << sum - 1 << "\n";
    }
}