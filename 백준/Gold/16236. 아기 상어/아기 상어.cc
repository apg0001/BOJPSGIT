#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

struct baby_shark
{
    int size;
    int cnt_eat;
    int x, y;
    int time;
};

baby_shark shark = {2, 0, 0, 0, 0};

int n;
vector<vector<int>> graph;

bool cmp(const pair<pair<int, int>, int> &p1, const pair<pair<int, int>, int> &p2)
{
    if (p1.first.first == p2.first.first)
        return p1.first.second < p2.first.second;
    return p1.first.first < p2.first.first;
}

pair<int, int> next_fish(int y, int x)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<pair<pair<int, int>, int>> fish;
    int xx[] = {0, -1, 1, 0};
    int yy[] = {-1, 0, 0, 1};

    queue<pair<pair<int, int>, int>> bfs;
    bfs.push({{y, x}, 0});
    visited[y][x] = true;

    while (!bfs.empty())
    {

        int cy = bfs.front().first.first;
        int cx = bfs.front().first.second;
        int ct = bfs.front().second;
        bfs.pop();

        if (graph[cy][cx] != 0 && graph[cy][cx] < shark.size)
        {
            if (fish.size() == 0 || ct <= fish.front().second)
                fish.push_back({{cy, cx}, ct});
            else if (ct > fish.front().second)
                break;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + yy[i];
            int nx = cx + xx[i];
            int nt = ct + 1;

            if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] || graph[ny][nx] > shark.size)
                continue;

            bfs.push({{ny, nx}, nt});
            visited[ny][nx] = true;
        }
    }
    if (fish.size() == 0)
        return {-1, -1};
    else
    {
        sort(fish.begin(), fish.end(), cmp);
        shark.time += fish.front().second;
        shark.cnt_eat++;
        shark.y = fish.front().first.first;
        shark.x = fish.front().first.second;
        graph[shark.y][shark.x] = 0;
        if (shark.cnt_eat >= shark.size)
        {
            shark.size++;
            shark.cnt_eat = 0;
        }
        return {shark.y, shark.x};
    }
}

int main()
{
    cin >> n;
    graph.resize(n);

    for (int i = 0; i < n; i++)
    {
        graph[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 9)
            {
                shark.y = i;
                shark.x = j;
                graph[i][j] = 0;
            }
        }
    }

    while (true)
    {
        pair<int, int> next = next_fish(shark.y, shark.x);
        if (next.first == -1 && next.second == -1)
            break;
    }

    cout << shark.time << endl;

    return 0;
}
