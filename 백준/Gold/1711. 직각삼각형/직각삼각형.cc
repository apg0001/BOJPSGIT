#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

ll result = 0;

void cross(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3)
{
    pair<ll, ll> v1 = {p2.first - p1.first, p2.second - p1.second};
    pair<ll, ll> v2 = {p3.first - p1.first, p3.second - p1.second};

    if (v1.first * v2.first + v1.second * v2.second == 0)
    {
        result++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<ll, ll>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                cross(v[i], v[j], v[k]);
                cross(v[j], v[i], v[k]);
                cross(v[k], v[i], v[j]);
            }
        }
    }

    cout << result << endl;

    return 0;
}
