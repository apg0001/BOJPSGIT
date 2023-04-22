#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> v;
    string s;
    cin >> s;

    for (int i = 1; i < s.length() - 1; i++)
    {
        for (int j = i + 1; j < s.length(); j++)
        {
            string temp = s;
            reverse(temp.begin(), temp.begin() + i);
            reverse(temp.begin() + i, temp.begin() + j);
            reverse(temp.begin() + j, temp.end());
            v.push_back(temp);

            //            cout << "i = " << i << " j = " << j << endl;
            //            cout << temp << endl;
        }
    }

    sort(v.begin(), v.end());
    cout << v.front() << endl;

    return 0;
}
