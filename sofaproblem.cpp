#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int m,n;
vector<vector<char>> grid;
bool isFree(int r,int c){
	return r>=0 && r<m && c>=0 && c<n && grid[r][c]!='H';
}
struct State{
	int r1,c1,r2,c2;
};
State normalize(int r1,int c1,int r2,int c2){
	if(make_pair(r1,c1)>make_pair(r2,c2)){
		swap(r1,r2);
		swap(c1,c2);
	}
	return {r1,c1,r2,c2};
}
int main(){
	cin>>m>>n;
	grid.assign(m,vector<char>(n));
	vector<pair<int,int>> startCells,endCells;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>grid[i][j];
			if(grid[i][j]=='s') startCells.push_back({i,j});
			if(grid[i][j]=='S') endCells.push_back({i,j});
		}
	}
	State start=normalize(startCells[0].first,startCells[0].second,startCells[1].first,startCells[1].second);
	State target=normalize(endCells[0].first,endCells[0].second,endCells[1].first,endCells[1].second);
	vector<vector<vector<vector<bool>>>> visited(m,vector<vector<vector<bool>>>(n,vector<vector<bool>>(m,vector<bool>(n,false))));
	queue<pair<State,int>> q;
	q.push({start,0});
	visited[start.r1][start.c1][start.r2][start.c2]=true;
	int dr[4]={-1,1,0,0};
	int dc[4]={0,0,-1,1};
	while(!q.empty()){
		State curr=q.front().first;
		int steps=q.front().second;
		q.pop();
		if(curr.r1==target.r1 && curr.c1==target.c1 && curr.r2==target.r2 && curr.c2==target.c2){
			cout<<steps<<endl;
			return 0;
		}
		vector<State> nextCell;
		for(int d=0;d<4;d++){
			int nr1=curr.r1+dr[d],nc1=curr.c1+dc[d],nr2=curr.r2+dr[d],nc2=curr.c2+dc[d];
			if(isFree(nr1,nc1) && isFree(nr2,nc2)){
				nextCell.push_back(normalize(nr1,nc1,nr2,nc2));
			}
		}
		int cells[2][4] = {
            {curr.r1, curr.c1, curr.r2, curr.c2},  
            {curr.r2, curr.c2, curr.r1, curr.c1}   
        };
        for (int k = 0; k < 2; k++) {
            int pr = cells[k][0], pc = cells[k][1];  
            int orr = cells[k][2], oc = cells[k][3]; 
            int diffR = orr - pr, diffC = oc - pc;

            // two perpendicular directions
            int perp[2][2] = {{diffC, diffR}, {-diffC, -diffR}};
            for (int p = 0; p < 2; p++) {
                int newR = pr + perp[p][0], newC = pc + perp[p][1];   
                int cornerR = orr + perp[p][0], cornerC = oc + perp[p][1];
                if (isFree(newR, newC) && isFree(cornerR, cornerC)) {
                    nextCell.push_back(normalize(pr, pc, newR, newC));
                }
            }
        }

        // Add unvisited states to the queue
        for (State &s : nextCell) {
            if (!visited[s.r1][s.c1][s.r2][s.c2]) {
                visited[s.r1][s.c1][s.r2][s.c2] = true;
                q.push({s, steps + 1});
            }
        }
    }

    cout << -1 << endl;  // destination can't be reached
    return 0;
}