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

    vector<int> in_degree(n + 1, 0), cost(n + 1), dp(n + 1, 0);
    vector<vector<int>> graph(n + 1);
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];

        while (true)
        {
            int p;
            cin >> p;
            if (p == -1)
                break;

            in_degree[i]++;
            graph[p].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
            dp[i] = cost[i];
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];

            in_degree[next]--;
            if (in_degree[next] == 0)
                q.push(next);
            dp[next] = max(dp[next], dp[cur] + cost[next]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << endl;
    }

    return 0;
}
