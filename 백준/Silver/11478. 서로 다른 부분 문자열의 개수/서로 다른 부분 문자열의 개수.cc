#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    string s;
    cin >> s;
    map<string, int> m;

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 1; j <= s.length() - i; j++)
        {
            m[s.substr(i, j)]++;
        }
    }

    cout << m.size() << endl;

    return 0;
}
