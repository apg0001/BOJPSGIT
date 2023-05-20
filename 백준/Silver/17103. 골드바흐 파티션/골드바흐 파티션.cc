#include <bits/stdc++.h>
#define endl "\n"
#define MAX 1000000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    vector<bool> v(MAX + 1, false);

    for (int i = 2; i <= MAX; i++)
    {
        v[i] = true;
    }

    for (int i = 2; i <= MAX; i++)
    {
        if (v[i] == false)
            continue;

        for (int j = 2 * i; j <= MAX; j += i)
        {
            v[j] = false;
        }
    }

    for (int i = 0; i < t; i++)
    {
        int k, result = 0;
        cin >> k;

        for (int i = 2; i <= k / 2; i++)
        {
            if (v[i] && v[k - i])
                result++;
        }

        cout << result << endl;
    }

    return 0;
}
