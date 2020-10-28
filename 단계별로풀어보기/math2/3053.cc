// acmicpc number: 3053
#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int n;
    cin >> n;
    double pi_a = n*n*M_PI;
    double t_a = n*n*2;

    cout << setprecision(6) << fixed << pi_a << "\n" << t_a << "\n";
    return 0;
}