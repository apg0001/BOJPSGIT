#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> basket(n + 1, 0);

    for (int t = 0; t < m; t++)
    {
        int i, j, k;
        cin >> i >> j >> k;
        for (int s = i; s <= j; s++)
        {
            basket[s] = k;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << basket[i] << " ";
    }

    return 0;
}
