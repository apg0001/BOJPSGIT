#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> base, in_degree(n + 1, 0);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<vector<pair<int, int>>> graph(n + 1);
    queue<int> q;

    for (int i = 0; i < m; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;
        graph[y].push_back(make_pair(x, k));
        in_degree[x]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
            base.push_back(i);
            dp[i][i] = 1;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;

            for (int j = 1; j <= n; j++)
            {
                dp[next][j] += dp[cur][j] * graph[cur][i].second;
            }

            in_degree[next]--;
            if (in_degree[next] == 0)
                q.push(next);
        }
    }

    for (int i = 0; i < base.size(); i++)
    {
        cout << base[i] << " " << dp[n][base[i]] << endl;
    }

    return 0;
}
