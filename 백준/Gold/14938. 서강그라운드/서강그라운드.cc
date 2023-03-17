#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    int n, m, r, result = 0;
    cin >> n >> m >> r;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));
    vector<int> item(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> item[i];
    }

    for (int i = 0; i < r; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
        dist[u][v] = c;
        dist[v][u] = c;
    }

    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (j == k)
                    continue;
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] <= m)
            {
                sum += item[j];
            }
        }
        result = max(result, sum);
    }

    cout << result << endl;

    return 0;
}
