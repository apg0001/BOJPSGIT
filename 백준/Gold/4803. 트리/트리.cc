#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<int> parent;
vector<bool> visited;
vector<vector<int>> graph;

int getParent(int n)
{
    if (n == parent[n])
        return n;
    else
        return getParent(parent[n]);
}

void unionParent(int n1, int n2)
{
    n1 = getParent(n1);
    n2 = getParent(n2);

    if (n1 <= n2)
        parent[n2] = n1;
    else
        parent[n1] = n2;
}

bool isCycle(int n1, int n2)
{
    if (getParent(n1) == getParent(n2))
        return true;
    else
        return false;
}

bool bfs(int u, int n, bool cycle)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    map<pair<int, int>, bool> node;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (isCycle(cur, next) && node.find({cur, next}) == node.end())
                cycle = true;
            if (!visited[next])
            {
                unionParent(cur, next);
                visited[next] = true;
                q.push(next);
                node[{cur, next}] = true;
                node[{next, cur}] = true;
            }
        }
    }
    return cycle;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c = 1;
    do
    {
        int n, m, result = 0;
        cin >> n >> m;
        if (m == 0 && n == 0)
            break;

        // graph 배열 초기화
        graph.resize(n + 1, vector<int>());
        for (int i = 0; i <= n; i++)
            graph[i].clear();

        // visited 배열 초기화
        visited.resize(n + 1);
        fill(visited.begin(), visited.end(), false);

        // parent 배열 초기화
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        // graph 입력
        for (int i = 0; i < m; i++)
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
                bool check = bfs(i, n, false);
                if (!check)
                    result++;
            }
        }

        if (!result)
            cout << "Case " << c << ": No trees." << endl;
        else if (result == 1)
            cout << "Case " << c << ": There is one tree." << endl;
        else
            cout << "Case " << c << ": A forest of " << result << " trees." << endl;
    } while (c++);

    return 0;
}
