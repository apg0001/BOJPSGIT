#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    char c[2 * n + 2];
    for (int i = 0; i < 2 * n + 1; i++)
    {
        if (i % 2 == 0)
            c[i] = 'I';
        else
            c[i] = 'O';
    }
    c[2 * n + 1] = '\0';

    int index = 0;
    int result = 0;

    while (true)
    {
        index=s.find(c, index);
        if (index != string::npos){
            result++;
            index+=2;
        }
        else
            break;
    }

    cout << result << endl;
    return 0;
}
