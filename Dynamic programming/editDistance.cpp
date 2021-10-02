// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

//     - Insert a character
//     - Delete a character
//     - Replace a character

#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2)
{
    int len1 = word1.length(), len2 = word2.length();

    // make a dp table
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

    dp[0][0] = 0; // both strings are empty

    // when word2 is empty.
    // minimum modification will be deleting all characters in word1, i.e length of word1
    for (int i = 1; i < len1; i++)
    {
        dp[i][0] = i;
    }

    // when word1 is empty.
    for (int i = 1; i < len2; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            // if last char is same. dist will be same as without last char.
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }

            // dp[i][j-1] => insert
            // dp[i-1][j] => remove
            // dp[i-1][j-1] => modify
            else
            {
                dp[i][j] = 1 + min(dp[i][j - 1],
                                   min(dp[i - 1][j],
                                       dp[i - 1][j - 1]));
            }
        }
    }
    return dp[len1][len2]; // return min edit distance
}

int main()
{
    string s1, s2;
    s1 = "intention", s2 = "execution";
    cout << minDistance(s1, s2);
    return 0;
}
