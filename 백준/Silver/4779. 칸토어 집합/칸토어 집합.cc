#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<char> v;

void recur(int i, int depth)
{
    if (depth == 0)
        return;

    int cnt = pow(3, depth - 1);
    for (int j = 0; j < cnt; j++)
    {
        v[i + j + cnt] = ' ';
    }
    recur(i, depth - 1);
    recur(i + 2 * cnt, depth - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while (cin >> n)
    {
        v.resize(pow(3, n), '-');
        recur(0, n);

        for (auto a : v)
        {
            cout << a;
        }
        cout << endl;
    }

    return 0;
}
