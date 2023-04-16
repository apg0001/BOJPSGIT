#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

int t, n, m;
ll result = 0;
vector<int> a, b;
map<int, int> cnt;

void subset_a()
{
    for (int i = 0; i < n; i++)
    {
        int sum = a[i];
        cnt[sum]++;
        for (int j = i + 1; j < n; j++)
        {
            sum += a[j];
            cnt[sum]++;
        }
    }
}

void subset_b()
{
    for (int i = 0; i < m; i++)
    {
        int sum = b[i];
        result += cnt[t - sum];
        for (int j = i + 1; j < m; j++)
        {
            sum += b[j];
            result += cnt[t - sum];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> m;
    b.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    subset_a();
    subset_b();

    cout << result << endl;
    return 0;
}
