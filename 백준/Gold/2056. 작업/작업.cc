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
    vector<vector<int>> graph(n + 1);
    vector<int> cost(n + 1), in_degree(n + 1, 0), dp(n + 1, 0);
    queue<int> bfs;

    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> cost[i] >> t;

        for (int j = 0; j < t; j++)
        {
            int p;
            cin >> p;
            graph[i].push_back(p);
            in_degree[p]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
        {
            bfs.push(i);
            dp[i] = cost[i];
            result = max(result, cost[i]);
        }
    }

    while (!bfs.empty())
    {
        int cur = bfs.front();
        bfs.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];

            dp[next] = max(dp[next], dp[cur] + cost[next]);
            result = max(result, dp[next]);

            in_degree[next]--;
            if (in_degree[next] == 0)
            {
                bfs.push(next);
            }
        }
    }

    cout << result << endl;

    return 0;
}
