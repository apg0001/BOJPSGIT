#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int n;
int yy[] = {1, 0, -1, 0};
int xx[] = {0, 1, 0, -1};

vector<vector<int>> v;
vector<vector<bool>> visited;

void search(int y, int x, int d)
{
    queue<pair<int, int>> bfs;
    bfs.push(make_pair(y, x));
    visited[y][x] = true;

    while (!bfs.empty())
    {
        int cy, cx;
        cy = bfs.front().first;
        cx = bfs.front().second;
        bfs.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + yy[i];
            int nx = cx + xx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] || v[ny][nx] <= d)
                continue;

            bfs.push(make_pair(ny, nx));
            visited[ny][nx] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int min_height = INT_MAX, max_height = 0, result = 0;
    cin >> n;
    v.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
            min_height = min(min_height, v[i][j]);
            max_height = max(max_height, v[i][j]);
        }
    }

    for (int depth = min_height - 1; depth < max_height; depth++)
    {
        int temp_result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = false;
            }
        }
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if (!visited[y][x] && v[y][x] > depth)
                {
                    temp_result++;
                    search(y, x, depth);
                }
            }
        }
        result = max(temp_result, result);
//        cout << "depth: " << depth << " area: " << temp_result << endl;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                cout << visited[i][j] << " ";
//            }
//            cout << endl;
//        }
    }
    cout << result << endl;
    return 0;
}
