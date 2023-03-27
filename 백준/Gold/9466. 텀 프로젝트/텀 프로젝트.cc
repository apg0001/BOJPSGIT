#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<int> v;
vector<bool> team;
vector<bool> visited;

int cnt = 0;

void dfs(int n)
{
    visited[n] = true;

    int next = v[n];

    if (!visited[next])
    {
        dfs(next);
    }
    else if (!team[next])
    {
        for (int i = next; i != n; i = v[i])
        {
            cnt++;
        }
        cnt++;
    }
    team[n] = true;
    ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        v.resize(n + 1);
        team.resize(n + 1);
        visited.resize(n + 1);

        fill(team.begin(), team.end(), false);
        fill(visited.begin(), visited.end(), false);

        cnt = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
                dfs(i);
        }

        cout << n - cnt << endl;
    }
}
