#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int result = 0;
int dd[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 북, 동, 남, 서
vector<vector<int>> room;                          //-1: 청소된, 0: 청소 안 된, 1: 벽

bool check2clean(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dd[i][0];
        int nx = x + dd[i][1];

        if (room[ny][nx] == 0)
            return true;
    }
    return false;
}

void clean(int y, int x, int dir)
{
    if (room[y][x] == 0)
    {
        room[y][x] = -1;
        result++;
    }

    if (!check2clean(y, x))
    {
        int yBack = y - dd[dir][0];
        int xBack = x - dd[dir][1];

        if (room[yBack][xBack] != 1)
        {
            clean(yBack, xBack, dir);
        }
        else
            return;
    }
    else
    {
        dir = dir - 1 >= 0 ? dir - 1 : 3;
        int ny = y + dd[dir][0];
        int nx = x + dd[dir][1];

        if (room[ny][nx] == 0)
        {
            clean(ny, nx, dir);
        }
        else
        {
            clean(y, x, dir);
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, r, c, dir; // 행, 열, 처음 행, 처음 열, 방향
    cin >> n >> m >> r >> c >> dir;
    room.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> room[i][j];
        }
    }

    clean(r, c, dir);

    cout << result << endl;

    return 0;
}
