#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    pair<int, int> div;
    int N, r, c, size;
    cin >> N >> r >> c;
    size = static_cast<int>(pow(2, N));
    div = make_pair((size + 1) / 2, (size + 1) / 2);
    int d1, d2, d3, d4; // 각 사분면의 좌측 상단 값
    d1 = 0;
    d2 = d1 + static_cast<int>(pow((pow(2, N - 1)), 2));
    d3 = d2 + static_cast<int>(pow((pow(2, N - 1)), 2));
    d4 = d3 + static_cast<int>(pow((pow(2, N - 1)), 2));

    for (int i = N - 1; i > 0; i--)
    {
        int step = static_cast<int>(pow(2, i - 1));
        if (r < div.first)
        {
            if (c < div.second)
            {
                d1 = d1;
                div = make_pair(div.first - step, div.second - step);
            }
            else
            {
                d1 = d2;
                div = make_pair(div.first - step, div.second + step);
            }
        }
        else
        {
            if (c < div.second)
            {
                d1 = d3;
                div = make_pair(div.first + step, div.second - step);
            }
            else
            {
                d1 = d4;
                div = make_pair(div.first + step, div.second + step);
            }
        }
        d2 = d1 + static_cast<int>(pow((pow(2, i - 1)), 2));
        d3 = d2 + static_cast<int>(pow((pow(2, i - 1)), 2));
        d4 = d3 + static_cast<int>(pow((pow(2, i - 1)), 2));
    }

    if (r == div.first)
    {
        if (c == div.second)
            cout << d4 << endl;
        else
            cout << d3 << endl;
    }
    else
    {
        if (c == div.second)
            cout << d2 << endl;
        else
            cout << d1 << endl;
    }

    return 0;
}
