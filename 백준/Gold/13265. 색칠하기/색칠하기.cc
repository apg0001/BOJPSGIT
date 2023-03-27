#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<vector<int>> graph;
vector<int> color;
bool flag = false;

void dfs(int n)
{
    if (flag)
        return;
    for (int i = 0; i < graph[n].size(); i++)
    {
        int next = graph[n][i];

        if (color[next] == -1)
        {
            color[next] = 1 - color[n];
            dfs(next);
        }
        if (color[next] == color[n])
        {
            flag = true;
            return;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;

        flag = false;
        graph.clear();
        color.clear();
        graph.resize(n + 1);
        color.resize(n + 1, -1);

        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        for (int i = 1; i <= n; i++)
        {
            if (color[i] == -1)
            {
                color[1] = 0;
                dfs(i);
            }
        }

        if (flag)
            cout << "impossible" << endl;
        else
            cout << "possible" << endl;
    }

    return 0;
}
