#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<int> solve()
{
    int n;
    cin >> n;
    vector<int> temp(n * 2);
    vector<int> result;

    for (int i = 0; i < 2 * n; i++)
    {
        cin >> temp[i];
    }

    for(int i=0;i<n;i++){
        int top=temp.back();
        result.push_back(top/4*3);
        temp.pop_back();
        temp.erase(lower_bound(temp.begin(), temp.end(), top/4*3));
    }

    sort(result.begin(), result.end());
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i=1;i<=t;i++)
    {
        vector<int> result = solve();
        cout<<"Case #"<<i<<":";
        for(auto r:result){
            cout<<" "<<r;
        }
        cout<<endl;
    }

    return 0;
}
