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
    ll result = 0;
    vector<ll> dist(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> cost;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> dist[i];
    }

    for (int i = 0; i < n; i++)
    {
        ll c;
        cin >> c;
        cost.push({c, i});
    }

    int end = n - 1;
    while (end > 0)
    {
        pair<ll, int> min_cost = cost.top();
        cost.pop();

        if (min_cost.second >= end)
            continue;

        result += min_cost.first * accumulate(dist.begin() + min_cost.second, dist.begin() + end, 0ll);
        end = min_cost.second;
    }

    cout << result << endl;

    return 0;
}
