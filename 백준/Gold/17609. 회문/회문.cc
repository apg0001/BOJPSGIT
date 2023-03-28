#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int isPalindrome(string s)
{
    int result = 0;
    int x = 0, y = s.length() - 1;
    while (x <= y)
    {
        if (s[x] == s[y])
        {
            x++;
            y--;
        }
        else
        {
            result = 2;
            break;
        }
    }

    if (result == 2 && s[x] == s[y - 1] && x < y)
    {
        result = 1;

        int tempx = x;
        int tempy = y - 1;

        while (tempx <= tempy)
        {
            if (s[tempx] == s[tempy])
            {
                tempx++;
                tempy--;
            }
            else
            {
                result = 2;
                break;
            }
        }
    }

    if (result == 2 && s[x + 1] == s[y] && x < y)
    {
        result = 1;

        int tempx = x + 1;
        int tempy = y;

        while (tempx <= tempy)
        {
            if (s[tempx] == s[tempy])
            {
                tempx++;
                tempy--;
            }
            else
            {
                result = 2;
                break;
            }
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << isPalindrome(s) << endl;
    }

    return 0;
}
