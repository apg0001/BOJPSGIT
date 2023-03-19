#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

ll MOD = 1000000007;

vector<vector<ll>> mul_mat(vector<vector<ll>> m1, vector<vector<ll>> m2)
{
    vector<vector<ll>> mat(2, vector<ll>(2));
    mat[0][0] = (m1[0][0] * m2[0][0] % MOD + m1[0][1] * m2[1][0] % MOD) % MOD;
    mat[0][1] = (m1[0][0] * m2[0][1] % MOD + m1[0][1] * m2[1][1] % MOD) % MOD;
    mat[1][0] = (m1[1][0] * m2[0][0] % MOD + m1[1][1] * m2[1][0] % MOD) % MOD;
    mat[1][1] = (m1[1][0] * m2[0][1] % MOD + m1[1][1] * m2[1][1] % MOD) % MOD;

    return mat;
}

vector<vector<ll>> fibo(ll n)
{
    if (n == 1)
    {
        return {{1, 1}, {1, 0}};
    }
    vector<vector<ll>> temp = fibo(n / 2);
    if (n % 2 == 1)
    {
        return mul_mat(mul_mat(temp, temp), fibo(1));
    }
    else
    {
        return mul_mat(temp, temp);
    }
}

int main()
{
    ll n;
    cin >> n;

    vector<vector<ll>> result = fibo(n);

    cout << result[0][1] << endl;

    return 0;
}
