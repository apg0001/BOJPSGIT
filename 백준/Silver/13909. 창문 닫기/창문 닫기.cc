#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result = 0;
    cin >> n;

    for (int i = 1; i * i <= n; i++)
    {
        result++;
    }

    cout << result << endl;

    return 0;
}
