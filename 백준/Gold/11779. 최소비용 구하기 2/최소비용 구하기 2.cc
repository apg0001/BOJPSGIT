#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

struct cmp
{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }
};

auto dijkstra(const vector<vector<pair<int, int>>> graph, int src, int dst, int n)
{
    vector<int> dist(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    vector<int> path(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    dist[src] = 0;
    path[src] = src;
    pq.push({src, 0});

    while (!pq.empty())
    {
        int cur = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if (cur == dst)
        {
            cout << dist[dst] << endl;
            break;
        }

        if (!visited[cur])
        {
            for (int i = 0; i < graph[cur].size(); i++)
            {
                int next = graph[cur][i].first;
                int ncost = cost + graph[cur][i].second;

                if (ncost < dist[next])
                {
                    pq.push({next, ncost});
                    path[next] = cur;
                    dist[next] = ncost;
                }
            }
            visited[cur] = true;
        }
    }

    vector<int> shortest_path;
    int cur = dst;

    while (cur != src)
    {
        shortest_path.push_back(cur);
        cur = path[cur];
    }

    shortest_path.push_back(src);
    reverse(shortest_path.begin(), shortest_path.end());

    return shortest_path;
}

int main()
{
    int n, m, start, goal;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    priority_queue<pair<int, int>> pq;

    while (m--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
    }

    cin >> start >> goal;

    auto path = dijkstra(graph, start, goal, n);
    cout << path.size() << endl;
    for (auto e : path)
    {
        cout << e << " ";
    }

    return 0;
}
