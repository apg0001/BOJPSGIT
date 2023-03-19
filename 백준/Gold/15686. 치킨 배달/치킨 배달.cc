#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<vector<int>> combs;

void generateCombinations(int n, int c, vector<int> path, int start)
{
    if (path.size() == c)
    { // c개의 요소를 모두 뽑았을 때
        combs.push_back(path);
        return;
    }
    for (int i = start; i < n; i++)
    {
        path.push_back(i);                       // i번째 수를 선택
        generateCombinations(n, c, path, i + 1); // i + 1부터 다음 요소 선택
        path.pop_back();                         // 선택한 요소 제거
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, result = INT_MAX;
    cin >> n >> m;
    vector<pair<int, int>> house;
    vector<pair<int, int>> chicken;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;

            if (temp == 0)
            {
                continue;
            }
            if (temp == 1)
            {
                house.push_back({i, j});
            }
            if (temp == 2)
            {
                chicken.push_back({i, j});
            }
        }
    }

    vector<int> nums;
    for (int i = 0; i < chicken.size(); i++)
    {
        nums.push_back(i);
    }

    generateCombinations(chicken.size(), m, {}, 0);

    for (int i = 0; i < combs.size(); i++)
    {
        int sum_chicken_dist = 0;
        for (int j = 0; j < house.size(); j++)
        {
            int chicken_dist = INT_MAX;
            for (int k = 0; k < m; k++)
            {
                chicken_dist = min(chicken_dist, abs(chicken[combs[i][k]].first - house[j].first) + abs(chicken[combs[i][k]].second - house[j].second));
            }
            sum_chicken_dist += chicken_dist;
        }
        result = min(result, sum_chicken_dist);
    }

    cout << result << endl;

    return 0;
}
