#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int n, result = 0;
    cin >> n;

    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<bool> isprime(n + 1, true);
    vector<int> prime;

    for (int i = 2; i <= n; i++)
    {
        if (!isprime[i])
            continue;
        for (int j = 2 * i; j <= n; j += i)
        {
            isprime[j] = false;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
        }
    }

    int start = 0, end = 1, sum = prime[0];

    while (end <= prime.size())
    {
        if (sum <= n)
        {
            if (sum == n)
            {
                result++;
            }
            sum += prime[end++];
        }
        else
        {
            sum -= prime[start++];
        }
    }

    cout << result << endl;
    return 0;
}
