#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, result=0; cin>>n;
    map<string, int> m;
    
    while(n--){
        string s;cin>>s;
        if(s=="ENTER"){
            result+=m.size();
            m.clear();
        }
        else{
            m[s]++;
        }
    }
    result+=m.size();
    
    cout<<result<<endl;
    
    return 0;
}