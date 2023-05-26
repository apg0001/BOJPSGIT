#include <bits/stdc++.h>
#define endl "\n"

int n, resultMAX = -1e9, resultMIN = 1e9;
std::vector<int> num, op(4);

void dfs(int t, int index, std::vector<int> oper)
{
    if (index == n)
    {
        resultMAX = std::max(resultMAX, t);
        resultMIN = std::min(resultMIN, t);
        return;
    }

    if (oper[0])
    {
        oper[0]--;
        dfs(t + num[index], index + 1, oper);
        oper[0]++;
    }
    if (oper[1])
    {
        oper[1]--;
        dfs(t - num[index], index + 1, oper);
        oper[1]++;
    }
    if (oper[2])
    {
        oper[2]--;
        dfs(t * num[index], index + 1, oper);
        oper[2]++;
    }
    if (oper[3])
    {
        oper[3]--;
        dfs(t / num[index], index + 1, oper);
        oper[3]++;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n;
    num.resize(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }
    for (int i = 0; i < 4; i++)
    {
        std::cin >> op[i];
    }

    dfs(num[0], 1, op);

    std::cout << resultMAX << "\n"
              << resultMIN << endl;
    return 0;
}
