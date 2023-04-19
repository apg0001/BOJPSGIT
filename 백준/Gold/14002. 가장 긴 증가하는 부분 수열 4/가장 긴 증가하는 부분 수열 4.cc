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
    vector<int> arr(n + 1, 0);
    vector<int> dp(n + 1, 0);
    stack<int> LIS;
    pair<int, int> result = {0, 0}; // Size of LIS, index

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                if (result.first < dp[i])
                {
                    result.first = dp[i];
                    result.second = i;
                }
            }
        }
    }

    cout << result.first << endl;

    int cur = result.second;
    LIS.push(arr[cur]);

    for (int i = result.second - 1; i > 0; i--)
    {
        if (dp[cur] == dp[i] + 1 && arr[cur] > arr[i])
        {
            LIS.push(arr[i]);
            cur = i;
        }
    }

    while (!LIS.empty())
    {
        cout << LIS.top() << " ";
        LIS.pop();
    }

    return 0;
}
