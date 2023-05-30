#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt = 0;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        string s = to_string(i);
        if (s.find("50") != std::string::npos)
        {
            cnt += 2;
        }
        else
        {
            cnt++;
        }
    }

    if (to_string(n).find("50") != std::string::npos)
    {
        cnt--;
    }

    cout << cnt << endl;
    return 0;
}