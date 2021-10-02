#include <bits/stdc++.h>
using namespace std;

// tabulation method
int knapSack(int W, vector<int> &wt, vector<int> &value)
{
    int n = wt.size();
    // making and initializing dp vector
    vector<int> dp(W + 1, 0);

    // dp[i] => maximum value for i as constraint

    for (int i = 1; i < n + 1; i++)
    {
        for (int w = W; w >= 0; w--)
        {

            if (wt[i - 1] <= w)
                // finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + value[i - 1]);
        }
    }
    return dp[W]; // returning the maximum value of knapsack
}
int main()
{
    vector<int> value = {10, 40, 30, 50};
    vector<int> wt = {4, 3, 5, 6};
    int constraint = 10;
    cout << knapSack(constraint, wt, value);
    return 0;
}