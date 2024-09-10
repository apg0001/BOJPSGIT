#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    int n;                  // 과일 수
    int type_cnt = 0;       // 두 포인터 사이 과일 종류 수
    int head = 0, tail = 2; // 투 포인터
    int result = -1;        // 결과
    cin >> n;
    vector<int> cnt(10, 0); // 과일 종류별 수
    vector<int> tang;       // 탕후루 배열

    for (int i = 0; i < n; i++) // 탕후루 입력
    {
        int fruit;
        cin >> fruit;
        tang.push_back(fruit);
    }

    if (n <= 2) // 탕후루 수가 2개보다 적다면 항상 2종류 이하임
    {
        cout << n << endl;
        return 0;
    }

    for (int i = head; i <= tail; i++)
    {
        cnt[tang[i]]++;
        if (cnt[tang[i]] == 1)
            type_cnt++;
    }

    if (type_cnt <= 2)
        result = tail - head + 1;

    // cout << "head: " << head << " tail: " << tail << " cnt: " << type_cnt << " result: " << result << endl;
    // for (int i = 1; i <= 10; i++)
    // {
    //     cout << i << " : " << cnt[i] << " / ";
    // }
    // cout << endl;
    // for (int i = head; i <= tail; i++)
    // {
    //     cout << tang[i] << " ";
    // }
    // cout << endl;

    while (true) // 과일 종류가 2개 이하가 되면 종료
    {
        if (type_cnt > 2)
        {
            if (head == tail)
                continue;
            cnt[tang[head]]--;
            if (cnt[tang[head++]] == 0)
                type_cnt--;
        }
        else
        {
            if (tail >= n - 1)
                break;
            cnt[tang[++tail]]++;
            if (cnt[tang[tail]] == 1)
                type_cnt++;
        }
        if (type_cnt <=2 && result < tail - head + 1)
            result = tail - head + 1;
        // cout << "head: " << head << " tail: " << tail << " cnt: " << type_cnt << " result: " << result << endl;
        // for (int i = 1; i <= 10; i++)
        // {
        //     cout << i << " : " << cnt[i] << " / ";
        // }
        // cout << endl;
        // for (int i = head; i <= tail; i++)
        // {
        //     cout << tang[i] << " ";
        // }
        // cout << endl;
    }

    cout << result << endl;

    return 0;
}