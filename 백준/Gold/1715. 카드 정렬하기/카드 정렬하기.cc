#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, result = 0;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<>> pq;

    for (int i = 0; i < n; i++)
    {
        ll input;
        cin >> input;
        pq.push(input);
    }

    while (pq.size() > 1)
    {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();

        result += (a + b);
        pq.push(a + b);
    }

    cout << result;
    return 0;
}
