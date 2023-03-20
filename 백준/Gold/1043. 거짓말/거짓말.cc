#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int parent[51];

int getParent(int n)
{
    if (n == -1)
        return n;
    else if (n == parent[n])
        return n;
    else
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
    int n, m, k, result = 0;
    cin >> n >> m >> k;
    vector<vector<int>> graph(m);
    vector<int> know;

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    while (k--)
    {
        int t;
        cin >> t;
        know.push_back(t);
    }

    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            int s;
            cin >> s;
            graph[i].push_back(s);
        }
    }

    // for (int t = 0; t < m; t++)
    //{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < graph[i].size() - 1; j++)
        {
            for (int k = j + 1; k < graph[i].size(); k++)
            {
                unionParent(graph[i][j], graph[i][k]);
            }
        }
    }
    //}

    for (auto &v : graph)
    {
        bool flag = false;
        for (auto &e : v)
        {
            for (auto &p : know)
            {
                if (getParent(e) == getParent(p))
                {
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
        {
            result++;
        }
    }
    cout << result << endl;
    return 0;
}
