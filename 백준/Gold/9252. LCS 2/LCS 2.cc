#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<vector<int>> dp;
string s1, s2;

string result(int i, int j)
{
    if (i == 0 || j == 0)
    {
        return "";
    }

    if (s1[i - 1] == s2[j - 1])
    {
        return result(i - 1, j - 1) + s1[i - 1];
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
    {
        return result(i - 1, j);
    }
    else
    {
        return result(i, j - 1);
    }
}

string LCS()
{
    dp.resize(s1.length() + 1, vector<int>(s2.length() + 1));
    for (int i = 0; i <= s1.length(); i++)
    {
        for (int j = 0; j <= s2.length(); j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int length = dp[s1.length()][s2.length()];
    string lcs = result(s1.length(), s2.length());

    return lcs;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s1 >> s2;

    string lcs = LCS();

    cout << lcs.length() << endl;
    if (lcs.length())
    {
        for (int i = 0; i < lcs.length(); i++)
        {
            cout << lcs[i];
        }
        cout << endl;
    }

    return 0;
}
