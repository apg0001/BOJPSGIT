#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> pq;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pq.push_back(make_pair(x, y));
    }

    sort(pq.begin(), pq.end());
    int rangeX = 0, rangeY = 0, result = 0;

    for (int i = 0; i < n; i++)
    {
        int curX = pq[i].first;
        int curY = pq[i].second;
        if (rangeX <= curX && curX <= rangeY)
        {
            rangeY = max(curY, rangeY);
        }
        else
        {
            result += (rangeY - rangeX);
            rangeX = curX;
            rangeY = curY;
        }
    }

    result += (rangeY - rangeX);

    cout << result << endl;

    return 0;
}
