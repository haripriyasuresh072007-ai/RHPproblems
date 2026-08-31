#include<iostream>
#include<vector>
#include<String>
using namespace std;
void solve(){
	string a,b; cin>>a>>b;
	int r=a.length(),c=b.length();
	vector<int> pa(r+1,0);
	vector<int> pb(c+1,0);
	for(int i=1;i<=r;i++){
		pa[i]=(pa[i-1]+a[i-1]-'0')%10;
	}	
	for(int j=1;j<=c;j++){
		pb[j] = (pb[j - 1] + b[j - 1] - '0') % 10;

	}
	
	vector<vector<int>> dp(r+1, vector<int>(c+1,0));
	for(int row=1;row<=r;row++){
		for(int col=1;col<=c;col++){
			if(pa[row]==pa[col]){
				dp[row][col]=1+dp[row-1][col-1];
			}
			else{
				dp[row][col]=max(dp[row-1][col],dp[row][col-1]);
				
			}
			
			
		} 
		cout<<dp[r][c]<<endl;
	}
	if(pa[r]!=pb[c]){
		cout<<"-1"<<endl; 
		return;
	}
}
int main(){
	ios::sync_with_stdio(false);
	int tc=1;
	while(tc--){solve();}
}
//pa->prefix array a, pb->prefix array b