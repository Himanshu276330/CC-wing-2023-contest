#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve(){
	int n,m;
	cin>>n>>m;

	vector<int> arr(n),brr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++) cin>>brr[i];

	int ans=0;
	vector<int> temp,tt;
	for(int i=0;i<n;i++){
		if(arr[i]>=brr[i]){
			temp.push_back(arr[i]-brr[i]);
			arr[i]=brr[i];
			ans++;
		}else{
			tt.push_back(brr[i]-arr[i]);
		}
	}

	sort(temp.begin(),temp.end());
	sort(tt.begin(),tt.end());

	int rem=0;
	for(int i=temp.size()-1;i>=0 && m>0; i--,m--){
		rem+=temp[i];
	}

	for(auto val:tt){
		if(val<=rem){
			rem-=val;
			ans++;
		}
	}
	cout<<ans<<endl;
}

int32_t main() {
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}