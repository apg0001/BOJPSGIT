#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    int n, m, result = 0;
    cin >> n >> m;
    vector<int> v;
    vector<int> to_pop(m);
    for (int i = 0; i < m; i++)
    {
        cin >> to_pop[i];
    }
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        int tp = to_pop[i];
        int tp_idx = find(v.begin(), v.end(), tp) - v.begin();

        if (tp_idx <= v.size() - tp_idx - 1)
        {
            while (true)
            {
                if (v.front() == tp)
                {
                    v.erase(v.begin());
                    break;
                }
                int f = v.front();
                v.erase(v.begin());
                v.push_back(f);
                result++;
            }
        }
        else
        {
            while (true)
            {
                if (v.front() == tp)
                {
                    v.erase(v.begin());
                    break;
                }
                int b = v.back();
                v.erase(v.end() - 1);
                v.insert(v.begin(), b);
                result++;
            }
        }
    }

    cout << result << endl;
}
