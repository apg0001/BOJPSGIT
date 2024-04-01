#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);

    dp[1] = 0;
    dp[0] = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i / 2; j++)
        {
            dp[i] = dp[i] > (i - j) * j + dp[i - j] + dp[j] ? dp[i] : (i - j) * j + dp[i - j] + dp[j];
        }
    }
    cout << dp[n] << endl;
}
