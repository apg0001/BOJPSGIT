#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

struct Edge
{
    int src;
    int dst;
    int weight;
};

vector<ll> BellmanFord(vector<Edge> edges, int n, int start)
{
    vector<ll> distance(n + 1, 1e9);
    distance[start] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto &e : edges)
        {
            if (distance[e.src] == 1e9)
                continue;

            if (distance[e.dst] > distance[e.src] + e.weight)
                distance[e.dst] = distance[e.src] + e.weight;
        }
    }

    for (auto &e : edges)
    {
        if (distance[e.src] == 1e9)
            continue;
        if (distance[e.dst] > distance[e.src] + e.weight)
            return {};
    }

    return distance;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    vector<Edge> edges;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edges.emplace_back(Edge{a, b, c});
    }

    vector<ll> distance = BellmanFord(edges, n, 1);
    if (distance.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 2; i < distance.size(); i++)
        {
            if (distance[i] == 1e9)
                cout << -1 << endl;
            else
                cout << distance[i] << endl;
        }
    }

    return 0;
}
