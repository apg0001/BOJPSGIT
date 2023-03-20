#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<vector<char>> triangle;

void draw_triangle(int y, int x, int n)
{
    if (n == 3)
    {
        triangle[y][x] = '*';
        triangle[y + 1][x - 1] = '*';
        triangle[y + 1][x + 1] = '*';
        for (int i = 0; i < 5; i++)
        {
            triangle[y + 2][x - 2 + i] = '*';
        }
        return;
    }

    draw_triangle(y, x, n / 2);
    draw_triangle(y + n / 2, x - n / 2, n / 2);
    draw_triangle(y + n / 2, x + n / 2, n / 2);
}

int main()
{
    int n;
    cin >> n;
    triangle.resize(n, vector<char>(2 * n, ' '));

    draw_triangle(0, n - 1, n);

    for (auto v1 : triangle)
    {
        for (auto v2 : v1)
        {
            cout << v2;
        }
        cout << endl;
    }

    return 0;
}
