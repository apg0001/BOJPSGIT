#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int V, E;
vector<vector<int>> adj, re_adj;

bool cmp(vector<int> &v1, vector<int> &v2)
{
    return v1.front() < v2.front();
}

void input()
{
    cin >> V >> E;
    adj.resize(V + 1);
    re_adj.resize(V + 1);

    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        re_adj[b].push_back(a);
    }
}

void FillStack(int node, vector<bool> &visited, stack<int> &stack)
{
    visited[node] = true;

    for (auto next : adj[node])
    {
        if (!visited[next])
        {
            FillStack(next, visited, stack);
        }
    }
    stack.push(node);
}

void CollectConnectedComponents(int node, vector<bool> &visited, vector<int> &component)
{
    visited[node] = true;
    component.push_back(node);

    for (auto next : re_adj[node])
    {
        if (!visited[next])
        {
            CollectConnectedComponents(next, visited, component);
        }
    }
}

vector<vector<int>> Kosaraju()
{
    vector<bool> visited(V + 1, false);
    stack<int> stack;

    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
        {
            FillStack(i, visited, stack);
        }
    }

    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> connectedComponents;

    while (!stack.empty())
    {
        int node = stack.top();
        stack.pop();

        if (!visited[node])
        {
            vector<int> component;

            CollectConnectedComponents(node, visited, component);

            sort(component.begin(), component.end());
            connectedComponents.push_back(component);
        }
    }

    return connectedComponents;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    vector<vector<int>> connectedComponents = Kosaraju();
    cout << connectedComponents.size() << endl;

    sort(connectedComponents.begin(), connectedComponents.end(), cmp);

    for (int i = 0; i < connectedComponents.size(); i++)
    {
        for (auto node : connectedComponents[i])
        {
            cout << node << " ";
        }
        cout << -1 << endl;
    }

    return 0;
}
