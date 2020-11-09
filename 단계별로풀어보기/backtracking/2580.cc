// acmicpc number: 2580
#include <bits/stdc++.h>
using namespace std;

inline int getsq(int loc)
{
    return (loc / 9 / 3) * 3 + (loc % 9) / 3;
}

void printSudoku(int *sudoku)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i * 9 + j] << " ";
        }
        cout << "\n";
    }
}

bool solve(int *sudoku, int *row, int *col, int *sq, int loc)
{
    if (loc == 81)
    {
        printSudoku(sudoku);
        return true;
    }

    if (sudoku[loc] != 0)
        return solve(sudoku, row, col, sq, loc + 1);

    for (int i = 1; i <= 9; i++)
    {
        if ((row[loc / 9] & (1 << i)) != 0 ||
            (col[loc % 9] & (1 << i)) != 0 ||
            (sq[getsq(loc)] & (1 << i)) != 0)
            continue;

        sudoku[loc] = i;
        row[loc / 9] |= (1 << i);
        col[loc % 9] |= (1 << i);
        sq[getsq(loc)] |= (1 << i);

        bool k = solve(sudoku, row, col, sq, loc + 1);
        if (k)
            return true;

        sudoku[loc] = 0;
        row[loc / 9] &= ~(1 << i);
        col[loc % 9] &= ~(1 << i);
        sq[getsq(loc)] &= ~(1 << i);
    }
    return false;
}

void solve(int *sudoku, int *row, int *col, int *sq)
{
    solve(sudoku, row, col, sq, 0);
}

int main()
{
    int sq[9] = {0};
    int col[9] = {0};
    int row[9] = {0};
    int sudoku[81] = {0};

    for (int i = 0; i < 81; i++)
    {
        int k;
        cin >> k;
        if (k != 0)
        {
            sudoku[i] = k;
            row[i / 9] |= 1 << k;
            col[i % 9] |= 1 << k;
            sq[getsq(i)] |= 1 << k;
        }
    }
    solve(sudoku, row, col, sq);
}