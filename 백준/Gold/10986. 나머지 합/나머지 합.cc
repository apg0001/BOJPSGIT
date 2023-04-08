#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, mod, sum = 0;
    ll result = 0;
    cin >> n >> mod;
    map<int, ll> m;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum = (sum + a) % mod;

        m[sum]++;
    }

    for (int i = 0; i < mod; i++)
    {
        result += (m[i] * m[i] - m[i]) / 2;
    }

    cout << result + m[0] << endl;

    return 0;
}
