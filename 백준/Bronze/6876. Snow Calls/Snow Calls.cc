#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int main()
{
    string input;
    int tc;
    cin >> tc;

    while (tc--)
    {
        cin >> input;
        vector<char> v;

        for (int i = 0; i < input.length(); i++)
        {
            if ('0' <= input[i] && input[i] <= '9')
            {
                v.push_back(input[i]);
            }
            else
            {
                if ('A' <= input[i] && input[i] <= 'C')
                {
                    v.push_back('2');
                }
                else if ('D' <= input[i] && input[i] <= 'F')
                {
                    v.push_back('3');
                }
                else if ('G' <= input[i] && input[i] <= 'I')
                {
                    v.push_back('4');
                }
                else if ('J' <= input[i] && input[i] <= 'L')
                {
                    v.push_back('5');
                }
                else if ('M' <= input[i] && input[i] <= 'O')
                {
                    v.push_back('6');
                }
                else if ('P' <= input[i] && input[i] <= 'S')
                {
                    v.push_back('7');
                }
                else if ('T' <= input[i] && input[i] <= 'V')
                {
                    v.push_back('8');
                }
                else if ('W' <= input[i] && input[i] <= 'Z')
                {
                    v.push_back('9');
                }
                else
                {
                    continue;
                }
            }
        }

        for (int i = 0; i < 10; i++)
        {
            if (i == 3 || i == 6)
            {
                cout << "-";
            }
            cout << v[i];
        }
        cout << endl;
    }

    return 0;
}