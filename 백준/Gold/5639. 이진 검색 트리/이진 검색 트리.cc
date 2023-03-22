#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<int> preorder;

void pre_to_post(int b, int e)
{
    if (b >= e)
        return;
    if (b == e - 1)
    {
        cout << preorder[b] << endl;
        return;
    }

    int i;
    for (i = b + 1; i < e; i++)
    {
        if (preorder[i] > preorder[b])
            break;
    }

    pre_to_post(b + 1, i);
    pre_to_post(i, e);

    cout << preorder[b] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;

    while (cin >> num)
    {
        preorder.push_back(num);
    }

    pre_to_post(0, preorder.size());

    return 0;
}
