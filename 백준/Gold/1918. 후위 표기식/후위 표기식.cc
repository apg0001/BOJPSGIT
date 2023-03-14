#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int priority(char c)
{
    if (c == '*' || c == '/')
        return 1;
    if (c == '+' || c == '-')
        return 0;
    return -1;
}

int main()
{
    string s;
    stack<char> stk;

    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z')
        {
            cout << s[i];
        }
        else
        {
            if (s[i] == '(')
                stk.push(s[i]);
            else if (s[i] == ')')
            {
                while (stk.top() != '(')
                {
                    cout << stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else
            {
                while (!stk.empty() && priority(stk.top()) >= priority(s[i]))
                {
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(s[i]);
            }
        }
    }
    while (!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }

    return 0;
}
