#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

ll d;
ll SIZE;
ll yy[] = {0, 0, 1, 1};
ll xx[] = {1, 0, 0, 1};
ll yyy[] = {-1, -1, 1, 1};
ll xxx[] = {1, -1, -1, 1};

pair<ll, ll> decode(ll y, ll x, string code, ll degree)
{
    if (degree == d)
    {
        return {y, x};
    }
    ll div_size = pow(2, degree + 1);
    ll n = code[degree] - '0';
    ll ny = y + yy[n - 1] * (SIZE / div_size);
    ll nx = x + xx[n - 1] * (SIZE / div_size);
    return decode(ny, nx, code, degree + 1);
}

string encode(ll y, ll x, ll sy, ll sx, string code, ll degree)
{
    if (y < 0 || y >= SIZE || x < 0 || x >= SIZE)
        return "-1";
    if (degree == d)
    {
        return code;
    }
    int sqr;

    if (y < sy && x >= sx)
        sqr = 1;
    else if (y < sy && x < sx)
        sqr = 2;
    else if (y >= sy && x < sx)
        sqr = 3;
    else
        sqr = 4;

    ll mul_size = pow(2, d - degree - 2);
    sy += mul_size * yyy[sqr - 1];
    sx += mul_size * xxx[sqr - 1];

    code[degree] = sqr + '0';
    return encode(y, x, sy, sx, code, degree + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string code;
    ll my, mx;

    cin >> d >> code;
    cin >> mx >> my;

    SIZE = pow(2, d);

    pair<ll, ll> cur_pos = decode(0, 0, code, 0);

    //cout << cur_pos.first << " " << cur_pos.second << endl;

    string temp = "";
    for (int i = 0; i < d; i++)
    {
        temp += '0';
    }

    ll sy = SIZE / 2;
    ll sx = SIZE / 2;
    string result = encode(cur_pos.first - my, cur_pos.second + mx, sy, sx, temp, 0);

    cout << result << endl;

    return 0;
}
