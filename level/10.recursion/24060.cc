// acmicpc number: 24060
#include <bits/stdc++.h>
using namespace std;

int n;
int k;

void merge(vector<int>& A, int p, int q, int r) {
    int a = p, b = q + 1, c = 0;
    vector<int> B(r - p + 1);
    while (a <= q && b <= r) {
        if (A[a] <= A[b]) {
            B[c++] = A[a++];
        } else {
            B[c++] = A[b++];
        }
    }
    while (a <= q) {
        B[c++] = A[a++];
    }
    while (b <= r) {
        B[c++] = A[b++];
    }
    for (int i = 0; i < c; ++i) {
        A[p + i] = B[i];
        k--;
        if (k == 0) {
            cout << A[p + i] << endl;
        }
    }
}

void merge_sort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    merge_sort(v, 0, n - 1);
    if (k > 0) {
        cout << -1 << endl;
    }
    return 0;
}