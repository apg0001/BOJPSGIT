#include <bits/stdc++.h>
using namespace std;

//int queen[10];
vector<int> queen;
int cnt = 0;

/*void print(int n)
{
    cout<<cnt<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (queen[i] == j)
                cout << "x ";
            else
                cout << "o ";
        }
        cout << endl;
    }
    cout<<endl;
}*/

bool check(int selected, int c)
{
    for (int row = 0; row < selected; row++)
    {
        if (c == queen[row] || abs(row - selected) == abs(queen[row] - c))
        {
            return false;
        }
    }
    return true;
}

void search(int selected, int n)
{
    int i;

    i = 0;
    if (selected == n)
    {
        /*for (auto pos : queen)
        {
            cout << pos << " ";
        }
        cout << endl;
        print(n);*/
        cnt++;
        return;
    }
    else
    {
        while (i++ < n)
        {
            if (check(selected, i))
            {
                queen[selected] = i;
                search(selected + 1, n);
            }
        }
    }
}

int main()
{
    int n; cin>>n;
    queen.resize(n, -1);
    search(0, n);
    cout << cnt;

    return 0;
}