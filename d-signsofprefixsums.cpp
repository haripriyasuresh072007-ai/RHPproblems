#include<iostream>
#include<vector>
using namespace std;
void solve(){
	int n; string s; cin>>n>>s;
	if(s[0]=='0' || s.contains("00")){
		cout<<"-1"<<endl; return;
	}
	int ans=-1;
	if(s.contains("+-")|| s.contains("-+")){
		ans=3;
	} else{
		ans=2;
	}
	else{
		for(int i=0;i<n;i+=2){
			if(s[i]=='0'){
				ans=2;
				break;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}