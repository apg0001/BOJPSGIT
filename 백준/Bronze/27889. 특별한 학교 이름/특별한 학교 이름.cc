#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    if (s == "NLCS")
        cout << "North London Collegiate School" << endl;
    else if (s == "BHA")
        cout << "Branksome Hall Asia" << endl;
    else if (s == "KIS")
        cout << "Korea International School" << endl;
    else if (s == "SJA")
        cout << "St. Johnsbury Academy" << endl;

    return 0;
}