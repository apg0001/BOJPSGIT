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
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int start = 0, end = k, temp = 0, result = 0;

    for (int i = start; i < end; i++)
    {
        temp += v[i];
    }

    result = temp;

    while (end < n)
    {
        temp -= v[start++];
        temp += v[end++];

        result = max(result, temp);
    }

    cout << result << endl;
}
