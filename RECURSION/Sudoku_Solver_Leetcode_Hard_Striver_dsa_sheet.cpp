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
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {

        for (int i = 0; i < 9; i++)
        {

            if (board[i][col] == c)
            {
                return false;
            }

            if (board[row][i] == c)
            {
                return false;
            }

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            {
                return false;
            }
        }
    }

public:
    bool solve(vector<vector<char>> &board)
    {

        for (int i = 0; i < board.size(); i++)
        {

            for (int j = 0; j < board[i].size(); j++)
            {

                if (board[i][j] == '.')
                {

                    for (char c = 1; c < 10; c++)
                    {

                        if (isValid(board, i, j, c))
                        {

                            board[i][j] = c;

                            if (solve(board) == true)
                            {
                                return true;
                            }

                            else
                            {
                                board[i][j] = '.';
                            }
                        }

                        return false;
                    }
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {

        solve(board);
    }
};

int main()
{
    IOS;
}