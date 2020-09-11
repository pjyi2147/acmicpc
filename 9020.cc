// acmicpc number: 9020 
#include <bits/stdc++.h>
using namespace std;

int getdownp(int down_p, bool* p);
int getupp(int up_p, bool* p);

int main()
{
    int n, MAX = 10000;
    cin >> n;

    bool* p = new bool[MAX+1];
    memset(p,1,sizeof(bool)*(MAX+1));

    p[1] = false;
    for (int i = 2; i*i <= MAX; i++)
    {
        if (p[i] == false) continue;
        for (int j = i*2; j <= MAX; j+=i) p[j] = false;
    }


    for (int i = 0; i < n; i++)
    {
        int k = 0;
        cin >> k;
        int k2 = k/2;
        int down_p = getdownp(k2, p), up_p = getupp(k2, p);
        bool notfound = true;

        while (notfound)
        {
            if (down_p + up_p == k) 
            {
                printf("%d %d\n", down_p, up_p);
                notfound = false;
            }
            else if (down_p + up_p > k)
            {
                up_p = getupp(k2, p);
                down_p = getdownp(down_p-1, p);
            }
            else up_p = getupp(up_p+1, p);
        }
    }
}

int getdownp(int down_p, bool* p)
{
    while (p[down_p] == false) down_p -= 1;
    return down_p;
}

int getupp(int up_p, bool* p)
{
    while(p[up_p] == false) up_p += 1;
    return up_p;
}
    