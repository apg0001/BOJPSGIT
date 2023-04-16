#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> count(26);
    string input;
    
    cin>>input;
    
    int l=input.length();
    
    for(int i=0;i<l;i++){
        if(input[i]>='a'){
            count[input[i]-'a']++;
        }
        else{
            count[input[i]-'A']++;
        }
    }
    
    int c=0, m;
    m=*max_element(count.begin(), count.end());
    int max_index;
    for(auto iter=count.begin(); iter!=count.end(); iter++){
        if(*iter==m){
            max_index=iter-count.begin();
            c++;
        }
    }
    
    if(c>1){
        cout<<"?";
    }
    else{
        cout<<(char)(max_index+'A');
    }
    
    return 0;
}