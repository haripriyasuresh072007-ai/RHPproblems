#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>> mat(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>> dp(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        dp[i][0]=mat[i][0];
    }
    for(int j=1;j<c;j++){
        for(int i=0;i<r;i++){
            int best=INT_MIN;
            for(int pr=0;pr<r;pr++){
                if(pr==r) continue;
                if(dp[pr][j-1]>best){
                    best=dp[pr][j-1];
                }
            }
            dp[i][j]=mat[i][j]+best;
        }
    }
    int result=INT_MIN;
    for(int i=0;i<r;i++){
        result=max(result,dp[i][c-1]);
    }
    cout<<result<<endl;
}
