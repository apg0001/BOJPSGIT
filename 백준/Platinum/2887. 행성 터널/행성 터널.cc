#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int parent[100001];

struct Edge
{
    int p1;
    int p2;
    int dist;
};

bool cmp(const Edge &e1, const Edge &e2)
{
    return e1.dist < e2.dist;
}

int getParent(int vertex)
{
    if (parent[vertex] == vertex)
        return vertex;
    return getParent(parent[vertex]);
}

void unionParent(int v1, int v2)
{
    v1 = getParent(v1);
    v2 = getParent(v2);
    if (v1 < v2)
        parent[v2] = v1;
    else
        parent[v1] = v2;
}

bool isCycle(int v1, int v2)
{
    v1 = getParent(v1);
    v2 = getParent(v2);

    if (v1 == v2)
        return true;
    else
        return false;
}

int main()
{
    int n, result = 0;
    cin >> n;
    vector<pair<int, int>> x;
    vector<pair<int, int>> y;
    vector<pair<int, int>> z;
    vector<Edge> edges;

    for (int i = 1; i <= n; i++)
    {
        int xx, yy, zz;
        cin >> xx >> yy >> zz;
        x.push_back({xx, i});
        y.push_back({yy, i});
        z.push_back({zz, i});
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for (int i = 1; i < n; i++)
    {
        edges.push_back({x[i].second, x[i - 1].second, x[i].first - x[i - 1].first});
        edges.push_back({y[i].second, y[i - 1].second, y[i].first - y[i - 1].first});
        edges.push_back({z[i].second, z[i - 1].second, z[i].first - z[i - 1].first});
    }

    sort(edges.begin(), edges.end(), cmp);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for (auto iter = edges.begin(); iter != edges.end(); iter++)
    {
        if (!isCycle(iter->p1, iter->p2))
        {
            result += iter->dist;
            unionParent(iter->p1, iter->p2);
        }
    }

    cout << result << endl;

    return 0;
}
