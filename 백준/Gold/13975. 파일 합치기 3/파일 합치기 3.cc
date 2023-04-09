#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll k, result = 0;
        cin >> k;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        while (k--)
        {
            ll input;
            cin >> input;
            pq.push(input);
        }

        while (pq.size() > 1)
        {
            ll p1 = pq.top();
            pq.pop();
            ll p2 = pq.top();
            pq.pop();

            result += (p1 + p2);
            pq.push(p1 + p2);
        }

        cout << result << endl;
    }
    return 0;
}
