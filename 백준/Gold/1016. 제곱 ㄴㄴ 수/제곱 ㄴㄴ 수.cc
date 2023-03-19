#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

int result[1000001] = {
    0,
};

int main()
{
    ll min, max, cnt = 0;
    cin >> min >> max;

    for (ll i = 2; i * i <= max; i++)
    {
        ll n = min / (i * i);

        if (min % (i * i))
            n++;

        while (n * i * i <= max)
        {
            result[n * i * i - min] = 1;
            n++;
        }
    }

    for (int i = 0; i <= max - min; i++)
    {
        if (result[i] == 0)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
