#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,d;
	cin>>a>>b>>c>>d;

	int prime[40001];
	for(int i=0;i<=4000;i++) prime[i]=1;
	prime[0]=prime[1]=0;
	for(int i=2;i<=4000;i++){
		if(prime[i]){
			for(int j=2*i;j<=4000;j+=i) prime[j]=0;
		}
	}

	for(int i=a;i<=b;i++){
		bool ok=1;
		for(int j=c;j<=d;j++){
			if(prime[i+j]==1) ok=0;
		}
		if(ok) {
			cout<<"Himanshu"<<endl;
			return 0;
		}
	}
	cout<<"Ishaan"<<endl;
	return 0;
}