#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    string input[3];
    int result;
    for (int i = 0; i < 3; i++)
    {
        cin >> input[i];
    }

    for (int i = 0; i < 3; i++)
    {
        if ('1' <= input[i][0] && input[i][0] <= '9')
        {
            result = stoi(input[i]) + 3 - i;
            break;
        }
    }

    if(result%3==0&&result%5==0){
        cout<<"FizzBuzz"<<endl;
    }
    else if(result%3==0){
        cout<<"Fizz"<<endl;
    }
    else if(result%5==0){
        cout<<"Buzz"<<endl;
    }
    else{
        cout<<result;
    }

    return 0;
}