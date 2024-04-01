#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int cnt = 1;

    queue<int> q;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        q.push(input);
    }

    while (true)
    {
        if (q.front() == cnt)
        {
            q.pop();
            cnt++;
        }
        else if (!s.empty() && s.top() == cnt)
        {
            s.pop();
            cnt++;
        }
        else
        {
            if(q.empty() && s.empty()){
                break;
            }
            if (q.empty() && s.top() != cnt)
            {
                break;
            }
            s.push(q.front());
            q.pop();
        }
    }
    if (s.empty())
    {
        cout << "Nice" << endl;
    }
    else
    {
        cout << "Sad" << endl;
    }
}
