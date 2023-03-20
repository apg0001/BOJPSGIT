#include <bits/stdc++.h>
#define endl "\n"
#define MOD 1000
#define ll long long

using namespace std;

int n;

vector<vector<int>> base;

vector<vector<int>> mul_mat(vector<vector<int>> m1, vector<vector<int>> m2)
{
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                result[i][j] += (m1[i][k] * m2[k][j]) % MOD;
            }
            result[i][j] = result[i][j] % MOD;
        }
    }
    return result;
}

vector<vector<int>> solve(ll n)
{
    if (n == 1)
    {
        return base;
    }
    vector<vector<int>> temp = solve(n / 2);
    if (n % 2 == 1)
    {
        return mul_mat(mul_mat(temp, temp), solve(1));
    }
    else
    {
        return mul_mat(temp, temp);
    }
}

int main()
{
    ll b;
    cin >> n >> b;

    base.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> base[i][j];
        }
    }

    vector<vector<int>> result = solve(b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] %= 1000;
        }
    }

    for (auto r1 : result)
    {
        for (auto r2 : r1)
        {
            cout << r2 << " ";
        }
        cout << endl;
    }
}
