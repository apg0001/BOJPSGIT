#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<int> parent;

int getParent(int n)
{
    if (n == parent[n])
        return n;
    return getParent(parent[n]);
}

void unionParent(int n1, int n2)
{
    n1 = getParent(n1);
    n2 = getParent(n2);

    if (n1 < n2)
        parent[n2] = n1;
    else
        parent[n1] = n2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int t;
            cin >> t;
            if (t == 1)
            {
                unionParent(i, j);
//                cout << "union " << i << ", " << j << endl;
//                for (auto p : parent)
//                {
//                    cout << p << " ";
//                }
//                cout << endl;
            }
        }
    }

    int first;
    cin >> first;
    first = getParent(first);
    bool flag = true;
    for (int i = 1; i < m; i++)
    {
        int t;
        cin >> t;
        if (getParent(first) != getParent(t))
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
