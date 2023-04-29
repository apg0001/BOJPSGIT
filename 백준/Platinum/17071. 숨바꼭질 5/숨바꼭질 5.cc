#include <bits/stdc++.h>
#define endl "\n"
#define MAX 500001

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> visited(MAX, vector<int>(2, -1));
    queue<pair<int, int>> bfs;

    bfs.push(make_pair(n, 0));

    while (!bfs.empty())
    {
        int curPos = bfs.front().first;
        int curTime = bfs.front().second;
        bfs.pop();

        if (curPos < 0 || curPos >= MAX)
            continue;
        if (visited[curPos][curTime % 2] != -1)
            continue;

        visited[curPos][curTime % 2] = curTime;

        bfs.push(make_pair(curPos + 1, curTime + 1));
        bfs.push(make_pair(curPos - 1, curTime + 1));
        bfs.push(make_pair(curPos * 2, curTime + 1));
    }

    int t = k;
    for (int i = 0; i < MAX; i++)
    {
        t += i;
        if (t >= MAX)
            break;

        if (visited[t][i % 2] != -1 && visited[t][i % 2] <= i)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}