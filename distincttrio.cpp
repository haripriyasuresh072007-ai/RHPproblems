//AtCoder - distinctrio (binary search) 
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
int main(){
	int n; cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end());
	ll sum=0;
	for(int i=1;i<n-1;i++){
		auto hbit=upper_bound(arr.begin(),arr.end(),arr[i]);
		int noel=arr.end()-hbit;
		auto lbit=lower_bound(arr.begin(),arr.end(),arr[i]);
		int noeh=lbit-arr.begin();
		sum+=(1ll*noel*noeh);
	}
	cout<<sum<<endl;
}