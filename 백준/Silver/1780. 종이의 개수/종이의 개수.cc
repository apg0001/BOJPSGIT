#include <bits/stdc++.h>
#define endl "\n";

using namespace std;

vector<vector<int>> v;
int result[3] = {0, 0, 0};

int check_color(int y, int x, int N);
void divide(int y, int x, int N);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; i++)
    {
        v[i].resize(N);
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
        }
    }

    divide(0, 0, N);

    cout << result[0] << "\n"
         << result[1] << "\n"
         << result[2] << endl;
}

int check_color(int y, int x, int N)
{
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = y; i < y + N; i++)
    {
        for (int j = x; j < x + N; j++)
        {
            if (v[i][j] == -1)
                c1++;
            else if (v[i][j] == 0)
                c2++;
            else
                c3++;
        }
    }

    if (c2 == 0 && c3 == 0)
        return 0;
    else if (c1 == 0 && c3 == 0)
        return 1;
    else if (c1 == 0 && c2 == 0)
        return 2;
    else
        return -1;
}

void divide(int y, int x, int N)
{
    int state = check_color(y, x, N);
    if (state != -1)
        result[state]++;
    else
    {
        int yy[] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
        int xx[] = {0, 1, 2, 0, 1, 2, 0, 1, 2};

        for (int i = 0; i < 9; i++)
        {
            int ny = y + yy[i] * N / 3;
            int nx = x + xx[i] * N / 3;

            divide(ny, nx, N / 3);
        }
    }
}
