#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    
    stack<int> stk;

    int n;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        switch (k)
        {
        case 1:
            int x;
            cin >> x;
            stk.push(x);
            break;
        case 2:
            if (!stk.empty())
            {
                cout << stk.top() << endl;
                stk.pop();
            }
            else
                cout << -1 << endl;
            break;
        case 3:
            cout << stk.size() << endl;
            break;
        case 4:
            if (stk.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
            break;
        case 5:
            if (!stk.empty())
                cout << stk.top() << endl;
            else
                cout << -1 << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}