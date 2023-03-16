#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int yy[] = {1, 0, -1, 0};
int xx[] = {0, 1, 0, -1};

int main()
{
    int n, m, result = 0;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(m));
    vector<pair<int, int>> empty_place;
    vector<pair<int, int>> virus;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 0)
                empty_place.push_back({i, j});
            if (graph[i][j] == 2)
                virus.push_back({i, j});
        }
    }

    for (int i = 0; i < empty_place.size() - 2; i++)
    {
        graph[empty_place[i].first][empty_place[i].second] = 1;
        for (int j = i + 1; j < empty_place.size() - 1; j++)
        {
            graph[empty_place[j].first][empty_place[j].second] = 1;
            for (int k = j + 1; k < empty_place.size(); k++)
            {
                graph[empty_place[k].first][empty_place[k].second] = 1;

                int cnt = 0;
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                queue<pair<int, int>> bfs;

                for (int l = 0; l < virus.size(); l++)
                {
                    int y = virus[l].first;
                    int x = virus[l].second;

                    bfs.push({y, x});
                    visited[y][x] = true;
                }

                while (!bfs.empty())
                {
                    int cy = bfs.front().first;
                    int cx = bfs.front().second;
                    bfs.pop();

                    for (int l = 0; l < 4; l++)
                    {
                        int ny = cy + yy[l];
                        int nx = cx + xx[l];

                        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                            continue;

                        if (graph[ny][nx] == 0 && !visited[ny][nx])
                        {
                            cnt++;
                            visited[ny][nx] = true;
                            bfs.push({ny, nx});
                        }
                    }
                }

                result = max(result, static_cast<int>(empty_place.size() - 3 - cnt));
                vector<vector<bool>>().swap(visited);
                graph[empty_place[k].first][empty_place[k].second] = 0;
            }
            graph[empty_place[j].first][empty_place[j].second] = 0;
        }
        graph[empty_place[i].first][empty_place[i].second] = 0;
    }

    cout << result << endl;

    return 0;
}
