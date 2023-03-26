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

private:
    int Tabulation(string &s1, string &s2, int n1, int n2, vector<vector<int>> &dp)
    {

        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = 0;
        }

        for (int j = 0; j <= n2; j++)
        {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n1; i++)
        {

            for (int j = 1; j <= n2; j++)
            {

                int ans = 0;
                if (s1[i - 1] == s2[j - 1])
                {
                    ans = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    ans = max(dp[i - 1][j], dp[i][j - 1]);
                }

                dp[i][j] = ans;
            }
        }

        return dp[n1][n2];
    }

public:
    string Longest_Commom_Subsequence(string s1, string s2)

    {

        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        Tabulation(s1, s2, n1, n2, dp);

        string ans = "";
        int i = n1;
        int j = n2;
        while (i > 0 && j > 0)
        {

            if (s1[i - 1] == s2[j - 1])
            {
                i--;
                j--;
                ans.push_back(s1[i - 1]);
            }

            else if (dp[i - 1][j] > dp[i][j - 1])
            {

                i--;
            }

            else
            {
                j--;
            }
        }
    

    reverse(ans.begin(), ans.end());
    return ans;
}
};


int main()
{
    IOS;

    string s;
    string t;
    cin >> s >> t;

    Solution obj;
    string ans = obj.Longest_Commom_Subsequence(s, t);

    cout << ans << endl;
    return 0;
}