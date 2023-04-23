#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l, cnt = 0;
    cin >> n >> l;

    vector<int> arr(n);
    deque<pair<int, int>> dq;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && dq.front().second < i - l + 1)
        {
            dq.pop_front();
        }
        while (!dq.empty() && dq.back().first > arr[i])
        {
            dq.pop_back();
        }

        dq.push_back({arr[i], i});
        cout << dq.front().first << " ";
    }

    return 0;
}
