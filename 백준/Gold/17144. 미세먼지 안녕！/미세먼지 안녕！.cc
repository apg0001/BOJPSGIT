#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<vector<int>> v;
int r, c, total = 0;
int air1_r, air1_c, air2_r, air2_c;
int yy[] = {1, 0, -1, 0};
int xx[] = {0, 1, 0, -1};

void diffusion()
{
    auto temp = v;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (v[i][j] > 0)
            {
                int dust_per_block = floor(v[i][j] / 5);
                for (int k = 0; k < 4; k++)
                {
                    int ny = i + yy[k];
                    int nx = j + xx[k];

                    if (ny < 0 || ny >= r || nx < 0 || nx >= c || v[ny][nx] == -1)
                        continue;

                    temp[ny][nx] += dust_per_block;
                    temp[i][j] -= dust_per_block;
                }
            }
        }
    }
    v = temp;
    vector<vector<int>>().swap(temp);
}

void air_cleaner1()
{
    total -= v[air1_r - 1][air1_c];
    for (int i = air1_r - 1; i > 0; i--)
    {
        v[i][0] = v[i - 1][0];
    }
    for (int i = 0; i <= c - 2; i++)
    {
        v[0][i] = v[0][i + 1];
    }
    for (int i = 0; i <= air1_r - 1; i++)
    {
        v[i][c - 1] = v[i + 1][c - 1];
    }
    for (int i = c - 1; i >= 2; i--)
    {
        v[air1_r][i] = v[air1_r][i - 1];
    }
    v[air1_r][air1_c + 1] = 0;
}

void air_cleaner2()
{
    total -= v[air2_r + 1][air2_c];
    for (int i = air2_r + 1; i <= r - 2; i++)
    {
        v[i][0] = v[i + 1][0];
    }
    for (int i = 0; i <= c - 2; i++)
    {
        v[r - 1][i] = v[r - 1][i + 1];
    }
    for (int i = r - 1; i >= air2_r + 1; i--)
    {
        v[i][c - 1] = v[i - 1][c - 1];
    }
    for (int i = c - 1; i >= 2; i--)
    {
        v[air2_r][i] = v[air2_r][i - 1];
    }
    v[air2_r][air2_c + 1] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> r >> c >> t;

    v.resize(r, vector<int>(c));

    int flag = false;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> v[i][j];
            if (!flag && v[i][j] == -1)
            {
                air1_r = i;
                air1_c = j;
                flag = true;
            }
            if (flag && v[i][j] == -1)
            {
                air2_r = i;
                air2_c = j;
            }
            if (v[i][j]>0)
                total += v[i][j];
        }
    }

    for (int i = 1; i <= t; i++)
    {
        diffusion();
        air_cleaner1();
        air_cleaner2();
        
    }

    cout<<total<<endl;
    
    return 0;
}
