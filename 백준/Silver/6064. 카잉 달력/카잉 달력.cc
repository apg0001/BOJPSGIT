#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int M, N, x, y, cnt;
        cin >> M >> N >> x >> y;

        for (cnt = x; cnt <= lcm(M, N); cnt += M)
        {
            if ((cnt - 1) % N + 1 == y)
                break;
        }
        if (cnt > lcm(M, N))
            cout << -1 << endl;
        else
            cout << cnt << endl;
    }
}
