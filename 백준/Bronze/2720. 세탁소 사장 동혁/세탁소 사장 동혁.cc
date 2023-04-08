#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int c;
        cin >> c;

        cout << c / 25 << " ";
        c = c % 25;
        cout << c / 10 << " ";
        c = c % 10;
        cout << c / 5 << " ";
        c = c % 5;
        cout << c << endl;
    }

    return 0;
}
