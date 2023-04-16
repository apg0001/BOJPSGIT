#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
	int n;
	int count[10]={0,};
	int max, sixnine, set;
	
	std::cin>>n;
	
	while(n>0){
		count[n%10]++;
		n/=10;
	}
	
	sixnine=(count[6]+count[9]+1)/2;
	max=count[0];
	
	for(int i=0;i<10;i++){
		if(i==6||i==9){
			continue;
		}
		else{
			max=count[i]>max?count[i]:max;
		}
	}
	
	set=max>sixnine?max:sixnine;
	
	std::cout<<set;
	
	return 0;
}