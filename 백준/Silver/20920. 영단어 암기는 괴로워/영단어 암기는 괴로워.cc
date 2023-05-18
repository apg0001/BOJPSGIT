#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

map<string, int> cnt;
vector<string> v;

bool cmp(string s1, string s2)
{
    if (cnt[s1] == cnt[s2])
    {
        if (s1.length() == s2.length())
        {
            return s1 < s2;
        }
        return s1.length() > s2.length();
    }
    return cnt[s1] > cnt[s2];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;

        if (input.length() < m)
            continue;

        cnt[input]++;
        if (cnt[input] == 1)
        {
            v.push_back(input);
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (auto &word : v)
    {
        cout << word << endl;
    }

    return 0;
}