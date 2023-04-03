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

    int input[3], temp1[3], temp2[3], dp1[3], dp2[3];

    for (int i = 0; i < 3; i++)
    {
        cin >> temp1[i];
        temp2[i] = temp1[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> input[j];
        }

        dp1[0] = max(temp1[0], temp1[1]) + input[0];
        dp1[1] = *max_element(temp1, temp1 + 3) + input[1];
        dp1[2] = max(temp1[1], temp1[2]) + input[2];

        dp2[0] = min(temp2[0], temp2[1]) + input[0];
        dp2[1] = *min_element(temp2, temp2 + 3) + input[1];
        dp2[2] = min(temp2[1], temp2[2]) + input[2];

        for (int j = 0; j < 3; j++)
        {
            temp1[j] = dp1[j];
            temp2[j] = dp2[j];
        }
    }

    cout << *max_element(temp1, temp1 + 3) << " " << *min_element(temp2, temp2 + 3) << endl;

    return 0;
}
