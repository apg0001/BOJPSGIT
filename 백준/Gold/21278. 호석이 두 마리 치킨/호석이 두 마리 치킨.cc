#include <bits/stdc++.h>
#define endl "\n"
#define INT_MAX 1e9

using namespace std;

struct Result
{
    int b1, b2, time;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));

    Result result = {0, 0, static_cast<int>(INT_MAX)};

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        dist[a][b] = dist[b][a] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (j == k)
                    dist[j][k] = 0;
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int sum = 0;
            for (int k = 1; k <= n; k++)
            {
                sum += min(dist[k][i], dist[k][j]);
            }
            if (sum < result.time)
            {
                result = {i, j, sum};
            }
            if (sum == result.time)
            {
                if (i > result.b1)
                    continue;
                else
                {
                    if (j > result.b2)
                    {
                        result.b2 = j;
                    }
                }
            }
        }
    }
    cout << result.b1 << " " << result.b2 << " " << result.time * 2 << endl;
}
