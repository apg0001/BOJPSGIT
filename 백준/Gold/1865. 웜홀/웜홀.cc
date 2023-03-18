#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

struct Edge
{
    int src;
    int dst;
    int weight;
};

bool BellmanFord(vector<Edge> edges, int V, int start)
{
    vector<int> distance(V + 1, 1e9);
    distance[start] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (auto &e : edges)
        {
            if (distance[e.dst] > distance[e.src] + e.weight)
            {
                distance[e.dst] = distance[e.src] + e.weight;
            }
        }
    }

    for (auto e : edges)
    {
        if (distance[e.src] == 1e9)
            continue;

        if (distance[e.dst] > distance[e.src] + e.weight)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--)
    {
        int n, m, w;
        vector<Edge> edges;
        cin >> n >> m >> w;

        for (int i = 0; i < m; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }

        for (int i = 0; i < w; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }

        bool result = BellmanFord(edges, n, 1);

        if (result)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
