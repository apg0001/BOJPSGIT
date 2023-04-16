#include <bits/stdc++.h>
#define endl "\n"
#define MAX 1e9

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result = MAX;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(3));
    vector<vector<int>> dp(n, vector<int>(3));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> cost[i][j];
        }
    }

    for (int c = 0; c < 3; c++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i != c)
            {
                dp[0][i] = MAX;
                continue;
            }
            dp[0][i] = cost[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
        }

        for (int i = 0; i < 3; i++)
        {
            if (i == c)
                continue;
            result = min(result, dp[n - 1][i]);
        }
    }

    cout << result << endl;
}
