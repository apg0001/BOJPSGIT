#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;
    vector<int> v(n), result(n);
    stack<int> s;

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    for(int i=n-1;i>=0;i--){
        while(!s.empty()){
            if(s.top()>v[i]){
                result[i]=s.top();
                break;
            }
            else{
                s.pop();
            }
        }
        if(s.empty()){
            result[i]=-1;
        }
        s.push(v[i]);
    }

    for(auto r:result){
        cout<<r<<" ";
    }

    return 0;
}
