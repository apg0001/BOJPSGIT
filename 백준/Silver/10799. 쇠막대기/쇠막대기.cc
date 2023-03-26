#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<char> v;
    char c;
    while (cin >> c)
    {
        v.push_back(c);
    }

    int result = 0;
    int flag = 1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == '(')
            flag++;
        if (v[i] == ')')
        {
            flag--;
            if (v[i - 1] == '(')
                result += flag;
            else
                result++;
        }
    }

    cout << result << endl;

    return 0;
}
