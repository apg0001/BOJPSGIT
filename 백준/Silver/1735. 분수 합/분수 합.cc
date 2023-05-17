#include <bits/stdc++.h>
#define endl "\n"

int gcd(int a, int b)
{
    int r = a % b;
    if (r == 0)
    {
        return b;
    }
    return gcd(b, r);
}

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int m = b * y;
    int s = a * y + b * x;

    int g=gcd(m, s);
    
    m /= g;
    s /= g;
    cout << s << " " << m << endl;
    return 0;
}
