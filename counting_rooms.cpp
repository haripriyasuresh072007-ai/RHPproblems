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
//C++1 #include <iostream>
//2 #include <vector>
//Lines 1–2: Includes standard I/O streams (cin, cout) and the std::vector container for dynamic arrays.C++3 using namespace std;
//Line 3: Imports all identifiers from the standard C++ library namespace into the current scope so you can write cin or vector instead of std::cin or std::vector.C++4 const int diff[5] = {0, -1, 0, 1, 0};
//Line 4: A helper array to easily traverse 4-directional adjacent grid cells (left, top, bottom, right). Pairing consecutive elements gives direction vectors:$i=0$: (diff[0], diff[1]) $\rightarrow (0, -1)$ (Left)$i=1$: (diff[1], diff[2]) $\rightarrow (-1, 0)$ (Up)$i=2$: (diff[2], diff[3]) $\rightarrow (0, 1)$ (Down)$i=3$: (diff[3], diff[4]) $\rightarrow (1, 0)$ (Right)C++5 void dfs(int R, int C, int row, int col, vector<string>& g) {
//Line 5: Defines a Depth-First Search function taking grid dimensions (R, C), current cell coordinates (row, col), and a reference to the grid (g). Passing g by reference (&) avoids copying the large grid on every recursive call.C++6     g[row][col] = '#';
//Line 6: Marks the current cell as visited by replacing . (floor) with # (wall). This prevents infinite recursion and re-visiting.C++7     for (int i = 0; i < 4; i++) {
//8         int ar = row + diff[i];
//9         int ac = col + diff[i + 1];
//Lines 7–9: Loops through all 4 orthogonal directions and calculates the adjacent row (ar) and column (ac).C++10        if (ar >= 0 && ar < R && ac >= 0 && ac < C && g[ar][ac] == '.') {
//Line 10: Checks if the adjacent cell (ar, ac) stays within the grid boundaries and is an unvisited floor tile ('.'). (Note: ac < C was implicitly bounded by line bounds in practice, but checking both bounds ensures safety).C++11            dfs(R, C, ar, ac, g);
//12        }
//13    }
//14 }
//Lines 11–14: Recursively calls dfs on valid neighboring floor cells to flood-fill the entire connected room, completing the DFS function when all reachable connected cells are marked as #.C++16 int main() {
//17     int n, m;
//18     cin >> n >> m;
//Lines 16–18: Entry point of the program; reads grid height n (rows) and width m (columns).C++19     vector<string> g(n);
//20     for (int r = 0; r < n; r++) cin >> g[r];
//Lines 19–20: Initializes a vector of $n$ strings to hold the grid layout, then reads each row string from input.C++21     int nof_rooms = 0;
//Line 21: Initializes the counter variable nof_rooms to 0 to keep track of total connected components (rooms).C++22     for (int i = 0; i < n; i++) {
//23         for (int j = 0; j < m; j++) {
//Lines 22–23: Iterates through every cell $(i, j)$ in the $n \times m$ grid.C++24             if (g[i][j] == '.') {
//5                 nof_rooms++;
//26                 dfs(n, m, i, j, g);
//27             }
//28         }
//29     }
//Lines 24–29: If an unvisited floor cell . is encountered, it represents a new room:Increments nof_rooms by 1.Calls dfs from $(i, j)$ to explore and mark all floor cells belonging to this component as #.C++30     cout << nof_rooms << endl;
//31     return 0;
//32 }
//////Lines 30–32: Prints the total room count to standard output and returns 0 to signal successful program execution.