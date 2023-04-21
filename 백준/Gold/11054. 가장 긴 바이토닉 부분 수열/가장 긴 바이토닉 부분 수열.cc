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
    vector<int> arr(n), dp1(n, 1), dp2(n, 1);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j])
            {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << dp1[i] << " ";
    // }
    // cout << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << dp2[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < n; i++)
    {
        result = max(result, dp1[i] + dp2[i] - 1);
    }

    cout << result << endl;

    return 0;
}
