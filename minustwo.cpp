#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve() {
	int n;cin>>n;
	int odd=0,eoq=0,eeq=0;
	for(int i=0;i<n;i++){
		int curr;cin>>curr;
		if(curr&1)odd++;
		else{
			int q = curr/2;
			if(q&1)eoq++;
			else eeq++;
		}
	}
	cout<<max(odd,max(eoq,eeq))<<endl;
  }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}