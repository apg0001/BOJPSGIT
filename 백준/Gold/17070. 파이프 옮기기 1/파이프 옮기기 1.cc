#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int n;
vector<vector<int>> house;
vector<vector<int>> visited;

void dfs(int y, int x, int dir)
{
    visited[y][x]++;
    if (y == n - 1 && x == n - 1)
        return;
    
    if (dir == 0)
    {
        if (x + 1 < n && !house[y][x + 1])
            dfs(y, x + 1, 0);
        if (y + 1 < n && x + 1 < n && !house[y + 1][x] && !house[y][x + 1] && !house[y + 1][x + 1])
            dfs(y + 1, x + 1, 2);
    }
    if (dir == 1)
    {
        if (y + 1 < n && !house[y + 1][x])
            dfs(y + 1, x, 1);
        if (y + 1 < n && x + 1 < n && !house[y + 1][x] && !house[y][x + 1] && !house[y + 1][x + 1])
            dfs(y + 1, x + 1, 2);
    }
    if(dir==2)
    {
        if (x + 1 < n && !house[y][x + 1])
            dfs(y, x + 1, 0);
        if (y + 1 < n && !house[y + 1][x])
            dfs(y + 1, x, 1);
        if (y + 1 < n && x + 1 < n && !house[y + 1][x] && !house[y][x + 1] && !house[y + 1][x + 1])
            dfs(y + 1, x + 1, 2);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    house.resize(n, vector<int>(n));
    visited.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> house[i][j];
        }
    }

    dfs(0, 1, 0);
    cout << visited[n - 1][n - 1]<<endl;

    return 0;
}
