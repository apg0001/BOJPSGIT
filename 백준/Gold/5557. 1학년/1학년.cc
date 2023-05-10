#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<ll>> dp(n, vector<ll>(21, 0));

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    dp[0][v[0]] = 1;

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (dp[i - 1][j] != 0)
            {
                int nextPlus = j + v[i];
                int nextMinus = j - v[i];

                if (nextPlus <= 20)
                    dp[i][nextPlus] += dp[i - 1][j];
                if (nextMinus >= 0)
                    dp[i][nextMinus] += dp[i - 1][j];
            }
        }
    }

    cout << dp[n - 2][v[n - 1]] << endl;
    return 0;
}
