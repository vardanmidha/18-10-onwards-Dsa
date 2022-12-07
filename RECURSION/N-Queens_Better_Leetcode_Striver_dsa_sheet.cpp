#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vl vector<long long>
#define v1 vector<int>
#define v2 vector<vector<int>>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

class Solution
{

public:
public:
    void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans, vector<int> lDiagonal, vector<int> lrow, vector<int> uDiagonal)
    {

        if (col >= n)
        {
            ans.push_back(board);

            return;
        }

        for (int row = 0; row < n; row++)
        {

            if (lrow[row] == 0 && lDiagonal[row + col] == 0 && uDiagonal[n - 1 + col - row] == 0)
            {

                board[row][col] = 'Q';
                lrow[row] = 1;
                lDiagonal[row + col] = 1;
                uDiagonal[n - 1 + col - row] = 1;

                solve(col + 1, n, board, ans, lDiagonal, lrow, uDiagonal);
                lrow[row] = 0;
                lDiagonal[row + col] = 0;
                uDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {

        vector<vector<string>> ans;

        vector<string> board(n);

        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        vector<int> lDiagonal(2 * n - 1, 0);
        vector<int> lrow(n, 0);
        vector<int> uDiagonal(2 * n - 1, 0);
        solve(0, n, board, ans, lDiagonal, lrow, uDiagonal);

        return ans;
    }
};

int main()
{
    IOS;
}