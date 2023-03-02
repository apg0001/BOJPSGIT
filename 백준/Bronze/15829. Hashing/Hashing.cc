#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int r = 31;
int M = 1234567891;

vector<int> int_to_vector(int n)
{
    vector<int> v;
    while (n > 0)
    {
        v.push_back(n % 10);
        n = n / 10;
    }
    return v;
}

vector<int> square_r(int n, int t)
{
    for (int i = 0; i < t; i++)
    {
        n *= r;
        n = n % M;
    }

    return int_to_vector(n);
}

vector<int> sum_big(vector<int> v1, vector<int> v2)
{
    if (v1.size() < v2.size())
    {
        vector<int> temp = v1;
        v1 = v2;
        v2 = temp;
    }

    for (int i = 0; i < v2.size(); i++)
    {
        v1[i] += v2[i];
    }

    for (int i = 0; i < v1.size() - 1; i++)
    {
        v1[i + 1] += v1[i] / 10;
        v1[i] = v1[i] % 10;
    }

    if (v1[v1.size() - 1] >= 10)
    {
        v1.push_back(v1[v1.size() - 1] / 10);
        v1[v1.size() - 2] = v1[v1.size() - 2] % 10;
    }

    return v1;
}

int main()
{
    vector<int> result = {0};
    int L;
    cin >> L;

    for (int i = 0; i < L; i++)
    {
        char input;
        cin >> input;
        result = sum_big(result, square_r(input - 'a' + 1, i));
    }

    reverse(result.begin(), result.end());

    for (auto e : result)
    {
        cout << e;
    }

    return 0;
}
