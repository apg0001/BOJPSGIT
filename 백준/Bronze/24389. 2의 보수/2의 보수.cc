#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, result = 0;
    cin >> n;
    m = (~n);
    m++;

    for (int i = 0; i < 32; i++)
    {
        if ((n & (1 << i)) != (m & (1 << i)))
        {
            result++;
        }
    }

    cout << result << endl;
    return 0;
}
