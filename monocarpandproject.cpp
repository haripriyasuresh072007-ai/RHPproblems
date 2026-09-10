#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
#define INF 2e9
using namespace std;
void solve () {
ll x,y,k; cin >> x >> y >> k;
ll ans=0,ctr=0;
while (ctr<k){
ll rem=(y+ctr) % (x+ctr);
if(rem == y-x) break;
ans+=rem; 
ctr++;
}
cout << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc=1;
	cin >> tc;
	while(tc--) solve();
}