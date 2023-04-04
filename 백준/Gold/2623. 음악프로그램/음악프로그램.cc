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
    vector<vector<int>> graph(n + 1);
    vector<int> degree(n + 1, 0);
    vector<int> result;
    queue<int> q;

    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        vector<int> singer(k);

        for (int j = 0; j < k; j++)
        {
            cin >> singer[j];
        }

        for (int j = 0; j < k - 1; j++)
        {
            graph[singer[j]].push_back(singer[j + 1]);
            degree[singer[j + 1]]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int root = q.front();
        q.pop();
        result.push_back(root);

        for (int i = 0; i < graph[root].size(); i++)
        {
            degree[graph[root][i]]--;
            if (degree[graph[root][i]] == 0)
            {
                q.push(graph[root][i]);
            }
        }
    }

    if (result.size() != n)
    {
        cout << 0 << endl;
    }
    else
    {
        for (auto r : result)
        {
            cout << r << endl;
        }
    }

    return 0;
}
