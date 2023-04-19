#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, max_idx = 0;
    cin >> n;
    vector<int> arr(n, 0), dp(n, 1);
    vector<int> v;
    stack<int> LIS;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (i == 0)
        {
            v.push_back(arr[i]);
            continue;
        }

        if (arr[i] > v.back())
        {
            v.push_back(arr[i]);
            dp[i] = v.size();
            max_idx = i;
        }
        else
        {
            auto p = lower_bound(v.begin(), v.end(), arr[i]);
            *p = arr[i];
            dp[i] = p - v.begin() + 1;
        }
    }

    cout << v.size() << endl;

    LIS.push(arr[max_idx]);
    int cur = max_idx;

    for (int i = max_idx - 1; i >= 0; i--)
    {
        if (arr[i] < arr[cur] && dp[i] + 1 == dp[cur])
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
    cout << endl;

    return 0;
}
