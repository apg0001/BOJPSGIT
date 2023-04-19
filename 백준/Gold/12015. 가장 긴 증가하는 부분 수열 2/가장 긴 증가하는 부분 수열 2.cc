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
    vector<int> arr(n, 0);
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    v.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > v.back())
        {
            v.push_back(arr[i]);
        }
        else
        {
            auto p = lower_bound(v.begin(), v.end(), arr[i]);
            *p = arr[i];
        }
//        for(int j=0;j<v.size();j++){
//            cout<<v[j]<<" ";
//        }
//        cout<<endl;
    }

    cout << v.size() << endl;
    return 0;
}
