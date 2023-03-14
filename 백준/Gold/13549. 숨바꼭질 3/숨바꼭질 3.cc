#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> dist(200001, 1e9);
    deque<int> bfs;

    bfs.push_back(n);
    dist[n] = 0;

    while (!bfs.empty())
    {
        int cur = bfs.front();
        bfs.pop_front();

        if (cur == k)
        {
            break;
        }

        int warp = 2 * cur;
        int l = cur - 1, r = cur + 1;

        if (warp <= 200000 && dist[cur] < dist[warp])
        {
            dist[warp] = dist[cur];
            bfs.push_front(warp);
        }

        if (l >= 0 && dist[cur] + 1 < dist[l])
        {
            dist[l] = dist[cur] + 1;
            bfs.push_back(l);
        }

        if (r <= 200000 && dist[cur] + 1 < dist[r])
        {
            dist[r] = dist[cur] + 1;
            bfs.push_back(r);
        }
    }

    cout << dist[k] << endl;

    return 0;
}
