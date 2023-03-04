#include <bits/stdc++.h>
#define endl "\n";

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int k;
        cin >> k;

        multiset<int> ms;

        while (k--)
        {
            char c;
            int n;
            cin >> c >> n;

            if (c == 'I')
            {
                ms.insert(n);
            }
            else
            {
                if (!ms.empty())
                {
                    if (n == -1)
                        ms.erase(ms.begin());
                    else
                    {
                        auto last = --ms.end();
                        ms.erase(last);
                    }
                }
            }
        }

        if (!ms.empty())
        {
            auto first = ms.begin();
            auto last = --ms.end();
            cout << *last << " " << *first << endl;
        }
        else
        {
            cout << "EMPTY" << endl;
        }
    }

    return 0;
}
