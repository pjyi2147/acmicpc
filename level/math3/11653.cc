// acmicpc number: 11653
#include <bits/stdc++.h>
using namespace std;

int n;
const int MAX_N = 10000000;
bool prime[MAX_N];

void getPrime()
{
    prime[1] = false;
    for (int i = 2; i < MAX_N; i++)
    {
        if (!prime[i]) continue;
        for (int j = i*2; j < MAX_N; j=j+i) prime[j] = false;
    }
}

int getNextPrime(int k)
{
    k++;
    while (k < MAX_N && !prime[k]) k++;
    return k;
}

int main()
{
    cin >> n;
    memset(prime, 1, sizeof(prime));
    getPrime();
    int prime = 2;

    while (n > 1)
    {
        if (n % prime == 0) 
        {
            cout << prime << "\n";
            n /= prime;
        }
        else prime = getNextPrime(prime); 
    }
}