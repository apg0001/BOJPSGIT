#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> note1;
    int t, n, m;
    
    cin>>t;
    
    for(int i=0;i<t;i++){
        note1.clear();
        
        cin>>n;
        
        for(int j=0;j<n;j++){
            int key;
            cin>>key;
            note1.push_back(key);
        }
        
        sort(note1.begin(), note1.end());
        
        cin>>m;
        
        for(int j=0;j<m;j++){
            int key;
            cin>>key;
            if(binary_search(note1.begin(), note1.end(), key)){
                cout<<1<<"\n";
            }
            else{
                cout<<0<<"\n";
            }
        }
    }
    
    return 0;
}