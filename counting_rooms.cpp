//Same model as Leetcode 200.Number of islands
//taken from cses.fi
#include<iostream>
#include<vector>
using namespace std;
const int diff[5]={0,-1,0,1,0};//here itself we are getting left(0,-1),top(-1,0),bottom(0,1),right(1,0)
void dfs(int R,int C,int row,int col,vector<string>& g){//Passing g by reference (&) avoids copying the large grid on every recursive call.
	g[row][col]='#';
	for(int i=0;i<4;i++){
		int ar=row+diff[i];
		int ac=col+diff[i+1];
		if(ar>=0 && ar<R && ac>=0 && g[ar][ac]=='.'){
			dfs(R,C,ar,ac,g);
		}
	}
	
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<string> g(n);
	for(int r=0;r<n;r++) cin>>g[r];
	int nof_rooms=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if (g[i][j]=='.'){
				nof_rooms++;
				dfs(n,m,i,j,g);
			}
		}
	}
	cout<<nof_rooms<<endl;
	return 0;
}
	
}es 30–32: Prints the total room count to standard output and returns 0 to signal successful program execution.
