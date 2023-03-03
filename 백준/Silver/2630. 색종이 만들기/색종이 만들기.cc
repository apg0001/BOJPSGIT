#include <bits/stdc++.h>
#define endl "\n";

using namespace std;

vector<vector<int>> v;
int result[2] = {0, 0};

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
         << result[1] << endl;
}

int check_color(int y, int x, int N)
{
    int w = 0, b = 0;
    for (int i = y; i < y + N; i++)
    {
        for (int j = x; j < x + N; j++)
        {
            if (v[i][j])
                b++;
            else
                w++;
        }
    }

    if (b == 0)
        return 0;
    else if (w == 0)
        return 1;
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
        int yy[] = {0, 0, 1, 1};
        int xx[] = {0, 1, 0, 1};

        for (int i = 0; i < 4; i++)
        {
            int ny = y + yy[i] * N / 2;
            int nx = x + xx[i] * N / 2;

            divide(ny, nx, N / 2);
        }
    }
}
