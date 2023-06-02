#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        string name;
        int age, weight;

        cin >> name >> age >> weight;

        if (name == "#" && age == 0 && weight == 0)
        {
            break;
        }

        if (age > 17 || weight >= 80)
        {
            cout << name << " Senior" << endl;
        }
        else
        {
            cout << name << " Junior" << endl;
        }
    }
    return 0;
}