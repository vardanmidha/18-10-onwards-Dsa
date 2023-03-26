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
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
// Below is conventional method to store array of strings in graph.
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        while (!q.empty())
        {

            auto itr = q.front();
            string word = itr.first;
            int steps = itr.second;

            q.pop();

            if (word == endWord)
            {
                return steps;
            }

            for (int i = 0; i < word.length(); i++)
            {

                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {

                    word[i] = ch;

                    if (st.find(word) != st.end())
                    {

                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                // Passing the original word to loop.
                word[i] = original;
            }
        }

        return 0;
    }
};

int main()
{
    IOS;
}