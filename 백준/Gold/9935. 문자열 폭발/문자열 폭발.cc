#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, ex_s, temp = "";
    cin >> s >> ex_s;
    int size = ex_s.length();

    for (int i = 0; i < s.length(); i++)
    {
        temp.push_back(s[i]);
        if (temp.size() >= size)
        {
            bool flag = true;
            for (int j = 0; j < size; j++)
            {
                if (temp[temp.length() - size + j] != ex_s[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                for (int i = 0; i < size; i++)
                {
                    temp.pop_back();
                }
            }
        }
    }
    if (!temp.empty())
    {
        for (auto t : temp)
        {
            cout << t;
        }
        cout << endl;
    }
    else
    {
        cout << "FRULA" << endl;
    }
    return 0;
}
