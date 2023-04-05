#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int parent[500000];

int getParent(int n)
{
    if (n == parent[n])
    {
        return n;
    }
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

bool isCycle(int n1, int n2)
{
    n1 = getParent(n1);
    n2 = getParent(n2);
    if (n1 == n2)
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, result = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if(result==0){
            if (isCycle(a, b))
            {
                result = i;
            }
            unionParent(a, b);
        }
    }

    cout << result << endl;

    return 0;
}
