#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1, 0);
    vector<int> result;
    vector<bool> visited(n + 1, false);
    queue<int> q;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        in_degree[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
        {
            visited[i] = true;
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int root = q.front();
        q.pop();
        result.push_back(root);

        for (int i = 0; i < graph[root].size(); i++)
        {
            in_degree[graph[root][i]]--;
            if (in_degree[graph[root][i]] == 0)
            {
                visited[graph[root][i]] = true;
                q.push(graph[root][i]);
            }
        }
    }

    for (auto r : result)
    {
        cout << r << " ";
    }
    return 0;
}
