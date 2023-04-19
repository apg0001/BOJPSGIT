#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result = 0;
    cin >> n;

    map<int, int> m;
    vector<int> arr;
    vector<int> dp(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        m[a] = b;
    }

    arr.push_back(0);
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        arr.push_back(iter->second);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                result = max(result, dp[i]);
            }
        }
    }
    
    cout << n - result << endl;

    return 0;
}
