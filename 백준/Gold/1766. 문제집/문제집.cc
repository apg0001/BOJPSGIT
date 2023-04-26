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
    vector<int> in_degree(n + 1, 0);
    vector<vector<int>> graph(n + 1);
    priority_queue<int, vector<int>, greater<int>> pq;

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
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        cout << cur << " ";
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];

            in_degree[next]--;
            if (in_degree[next] == 0)
            {
                pq.push(next);
            }
        }
    }

    cout << endl;
    return 0;
}
