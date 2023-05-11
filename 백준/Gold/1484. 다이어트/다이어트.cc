#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int g, present, origin;
    cin >> g;
    bool flag = false;
    present = 1;
    origin = 1;
    while (true)
    {
        if (pow(present, 2) - pow(origin, 2) == g)
        {
            flag = true;
            cout << present << endl;
        }

        if (present - origin == 1 && pow(present, 2) - pow(origin, 2) > g)
            break;
        if (pow(present, 2) - pow(origin, 2) > g)
            origin++;
        else if (pow(present, 2) - pow(origin, 2) <= g)
            present++;
    }

    if (!flag)
    {
        cout << -1 << endl;
    }

    return 0;
}
