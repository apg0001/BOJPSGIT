#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.second < p2.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, idx = 0;
    cin >> n;
    vector<pair<int, int>> arr;
    vector<pair<int, int>> v;
    vector<int> dp(n, 1);
    stack<int> s;
    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        m[a] = b;
    }

    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        arr.push_back(make_pair(iter->first, iter->second));
    }

    //    for(int i=0;i<n;i++){
    //        cout<<arr[i].first<<" ";
    //    }
    //    cout<<endl;
    //    for(int i=0;i<n;i++){
    //        cout<<arr[i].second<<" ";
    //    }
    //    cout<<endl;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            v.push_back(arr[i]);
            continue;
        }

        if (arr[i].second > v.back().second)
        {
            v.push_back(arr[i]);
            dp[i] = v.size();
            idx = i;
        }
        else
        {
            auto p = lower_bound(v.begin(), v.end(), make_pair(0, arr[i].second), cmp);
            *p = arr[i];
            dp[i] = p - v.begin() + 1;
        }

        if (dp[i] >= dp[idx])
        {
            idx = i;
        }

        //        cout<<"#: "<<i<<endl;
        //
        //        for(int i=0;i<n;i++){
        //            cout<<v[i].first<<" ";
        //        }
        //        cout<<endl;
        //        for(int i=0;i<n;i++){
        //            cout<<v[i].second<<" ";
        //        }
        //        cout<<endl;
        //        for(int i=0;i<n;i++){
        //            cout<<dp[i]<<" ";
        //        }
        //        cout<<endl;
    }

    int cur = idx;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == idx)
            continue;
        if (i > idx)
        {
            s.push(arr[i].first);
            continue;
        }
        if (arr[i].second < arr[cur].second && dp[i] + 1 == dp[cur])
        {
            cur = i;
            continue;
        }
        else
        {
            s.push(arr[i].first);
        }
    }

    cout << n - v.size() << endl;

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
