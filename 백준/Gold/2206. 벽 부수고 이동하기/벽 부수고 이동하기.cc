#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int xx[] = {0, 1, 0, -1};
int yy[] = {1, 0, -1, 0};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(m));
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(2))); // y, x, 뚫고 왔나?(뚫고 왔으면 1, 안 뚫고 왔으면 0)
    queue<pair<pair<int, int>, int>> bfs;                                           // y, x, 이미 뚫었나?(이미 뚫었으면 1, 안 뚫었으면 0)

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &graph[i][j]);
        }
    }

    bfs.push(make_pair(make_pair(0, 0), 0));
    visited[0][0][0] = 1;

    while (!bfs.empty())
    {
        int cy = bfs.front().first.first;
        int cx = bfs.front().first.second;
        bool stat = bfs.front().second;
        bfs.pop();

        if (cy == n - 1 && cx == m - 1)
        {
            cout << visited[n - 1][m - 1][stat] << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + yy[i];
            int nx = cx + xx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            if (graph[ny][nx] == 0 && visited[ny][nx][stat] == 0)
            {
                bfs.push(make_pair(make_pair(ny, nx), stat));
                visited[ny][nx][stat] = visited[cy][cx][stat] + 1;
            }

            else if (graph[ny][nx] == 1 && visited[ny][nx][stat] == 0 && stat == 0)
            {
                bfs.push(make_pair(make_pair(ny, nx), 1));
                visited[ny][nx][1] = visited[cy][cx][stat] + 1;
            }
        }
    }

    cout << -1;
    return 0;
}
