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
    vector<int> arr(n + 1), v;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (v.size() == 0)
        {
            v.push_back(arr[i]);
            continue;
        }
        if (arr[i] > v.back())
        {
            v.push_back(arr[i]);
        }
        else
        {
            auto p = lower_bound(v.begin(), v.end(), arr[i]);
            *p = arr[i];
        }
    }

    cout << n - v.size() << endl;

    return 0;
}