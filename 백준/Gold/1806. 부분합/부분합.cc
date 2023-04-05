#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s, sum = 0, result = INT_MAX;
    int start = 0, end = 0;
    cin >> n >> s;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while (start <= end)
    {
        if (sum >= s)
        {
            result = min(result, end - start);
            sum -= arr[start++];
        }
        else if (end == n)
        {
            break;
        }
        else
        {
            sum += arr[end++];
        }
    }

    if (result == INT_MAX)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << result << endl;
    }

    return 0;
}
