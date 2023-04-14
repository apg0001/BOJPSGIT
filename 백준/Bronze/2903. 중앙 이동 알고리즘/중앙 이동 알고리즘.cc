#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 2;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] * 2 - 1;
    }

    cout << dp[n] * dp[n] << endl;

    return 0;
}