#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    int q;
    cin >> s >> q;
    vector<vector<int>> v(s.length(), vector<int>('z' - 'a' + 1, 0));

    v[0][s[0] - 'a']++;
    for (int i = 1; i < s.length(); i++)
    {
        for (int j = 0; j < 'z' - 'a' + 1; j++)
        {
            if (v[i - 1][j])
            {
                v[i][j] = v[i - 1][j];
            }
        }
        v[i][s[i] - 'a']++;
    }

    while (q--)
    {
        char a;
        int l, r;
        cin >> a >> l >> r;

        int result=v[r][a - 'a'] - v[l][a - 'a'];
        
        if(s[l]==a)result++;
        
        cout<<result<<endl;
    }

    return 0;
}
