#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

ll r = 31;
ll M = 1234567891;

int main()
{
    int L;
    ll hash = 0;
    ll R = 1;
    cin >> L;

    for (int i = 0; i < L; i++)
    {
        char c;
        cin >> c;
        int temp = c - 'a' + 1;

        hash = (hash + temp * R) % M;
        R = (R * r) % M;
    }

    cout << hash;
}
