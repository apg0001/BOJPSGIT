#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    for (int x = -999; x <= 999; x++)
    {
        for (int y = -999; y <= 999; y++)
        {
            if (a * x + b * y == c && d * x + e * y == f)
            {
                cout << x << " " << y << endl;
                return 0;
            }
        }
    }

    return 0;
}
