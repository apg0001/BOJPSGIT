#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<int> parent;

int get_parent(int n)
{
    if (n == parent[n])
        return n;
    else
        return parent[n] = get_parent(parent[n]);
}

void union_parent(int n1, int n2)
{
    n1 = get_parent(n1);
    n2 = get_parent(n2);
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
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    while (m--)
    {
        int opt, a, b;
        cin >> opt >> a >> b;
        if (opt == 0)
        {
            union_parent(a, b);
        }
        else
        {
            if (get_parent(a) == get_parent(b))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
