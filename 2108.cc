// acmicpc number: 2108
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, sum = 0;
    int count[8001];
    vector<int> vec;
    memset(count, 0, sizeof(int)*8001);
    scanf("%d\n", &N);
    vec.reserve(N);

    for (int i = 0; i < N; i++)
    {
        int k;
        scanf("%d", &k);
        vec.push_back(k);
        count[k+4000]++;
        sum += k;
    }
    sort(vec.begin(), vec.end());
    int median = vec[N/2];
    int range = vec[N-1] - vec[0];
    float avg = (float)sum / N;
    if (avg > 0 && avg+0.5 >= int(avg)+1) avg += 1;
    if (avg < 0 && avg-0.5 <= int(avg)-1) avg -= 1;
    int avgval = avg;

    int maxcnt = 0;
    vector<int> maxcntvec;
    for (int i = 0; i < 8001; i++)
    {
        if (count[i])
        {
            if (count[i] > maxcnt) maxcnt = count[i];
        }
    }
    for (int i = 0; i < 8001; i++)
    {
        if (count[i] == maxcnt)
        {
            maxcntvec.push_back((i-4000));
        }
    }

    int maxcntval;
    if (maxcntvec.size() > 1)
    {
        sort(maxcntvec.begin(), maxcntvec.end());
        maxcntval = maxcntvec[1];
    }   
    else maxcntval = maxcntvec[0];

    printf("%d\n%d\n%d\n%d\n", avgval, median, maxcntval, range);
}