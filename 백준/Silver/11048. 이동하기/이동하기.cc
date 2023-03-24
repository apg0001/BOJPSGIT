#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<vector<int>> miro, dp;

int main()
{
    int n, m;
    cin >> n >> m;
    miro.resize(n, vector<int>(m));
    dp.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> miro[i][j];
            if (i == 0 || j == 0)
                dp[i][j] = miro[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                continue;
            else if (i == 0)
                dp[i][j] = dp[i][j - 1] + miro[i][j];
            else if (j == 0)
                dp[i][j] = dp[i - 1][j] + miro[i][j];
            else
                dp[i][j] = miro[i][j] + max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1]));
        }
    }

    cout << dp[n - 1][m - 1] << endl;

    return 0;
}
