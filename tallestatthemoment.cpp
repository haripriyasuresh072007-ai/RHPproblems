#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n; cin>>n;
	vector<pair<int,int>> arr(n);
	for(int i=0;i<n;i++){
		int h,l; cin>>h>>l;
		arr[i]=make_pair(h,l);
	}
	sort(arr.begin(),arr.end(),greater<>());
	int prevtime=0;
	vector<int> htarr,ltarr;
	for(auto[ht,lt]:arr){
		if(lt>prevtime){
			prevtime=lt;
			ltarr.push_back(lt);
			htarr.push_back(ht);
		}
	}
	int q; cin>>q;
	while(q--){
		int t; cin>>t;
		auto it=upper_bound(ltarr.begin(),ltarr.end(),t);
		int idx=it-ltarr.begin();
		cout<<htarr[idx]<<endl;
	}
	return 0;
}