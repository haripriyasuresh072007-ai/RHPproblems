#include<iostream>
#include<vector>
using namespace std;
#define ll long long int

	int hcf(int a,int b){
		return b==0?a:hcf(b,a%b);
	}
	
int main(){
	int n;cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	  cout << hcf(arr[0], arr[n- 1]) << endl;
}