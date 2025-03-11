#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int u)
{
    // cout << "visited " << u << " !!" << endl;
    for (auto iter = graph[u].begin(); iter != graph[u].end(); iter++)
    {
        if (!visited[*iter])
        {
            visited[*iter] = true;
            dfs(*iter);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, result = 0;
    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1, false);

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            result++;
            dfs(i);
        }
    }

    cout << result << endl;

    return 0;
}