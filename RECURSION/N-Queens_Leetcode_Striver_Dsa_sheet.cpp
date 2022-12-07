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
    bool isSafe(int row, int col, int n, vector<string> &board)
    {

        int drow = row;
        int dcol = col;

        while (row >= 0 && col >= 0)
        {

            if (board[row][col] == 1)
            {
                return false;
            }

            col--;
            row--;
        }

        row = drow;
        col = dcol;

        while (col >= 0 && row >= 0)
        {

            if (board[row][col] == 1)
            {
                return false;
            }
            col--;
        }

        row = drow;
        col = dcol;

        while (row < n && col >= 0)
        {

            if (board[row][col] == 1)
            {
                return false;
            }

            row++;
            col--;
        }

        return true;
    }

public:
    void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans)
    {

        if (col >= n)
        {
            ans.push_back(board);

            return;
        }

        for (int row = 0; row < n; row++)
        {

            if (isSafe(row, col, n, board))
            {

                board[row][col] = 'Q';

                solve(col + 1, n, board, ans);

                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {

        vector<vector<string>> ans;

        vector<string> board(n);

        string s = ".";

        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        solve(0, n, board, ans);

        return ans;
    }
};

int main()
{
    IOS;
}