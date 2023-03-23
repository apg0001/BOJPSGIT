#include <bits/stdc++.h>
#define endl "\n"
#define MAX 111111

using namespace std;

bool visited[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, minTime = INT_MAX, cnt = 0;
    cin >> n >> k;

    fill(visited, visited + MAX, false);

    queue<pair<int, int>> bfs;
    bfs.push({n, 0});

    while (!bfs.empty())
    {
        int curPos = bfs.front().first;
        int curTime = bfs.front().second;
        
        bfs.pop();

        visited[curPos] = true;

        if (curPos == k)
        {
            if (minTime == curTime)
            {
                cnt++;
            }
            else if (minTime > curTime)
            {
                cnt = 1;
                minTime = curTime;
            }
        }

        if (curPos + 1 < MAX && !visited[curPos + 1])
            bfs.push({curPos + 1, curTime + 1});
        if (curPos - 1 >= 0 && !visited[curPos - 1])
            bfs.push({curPos - 1, curTime + 1});
        if (curPos * 2 < MAX && !visited[curPos * 2])
            bfs.push({curPos * 2, curTime + 1});
    }

    cout << minTime << endl;
    cout << cnt << endl;

    return 0;
}
