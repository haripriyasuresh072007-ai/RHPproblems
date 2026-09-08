#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve () {
int N,K; cin >> N >> K;
string s; cin >> s;
int F=N/K;
vector<bool> own(F,false);
for(unsigned int i=0;i<s.size() ; i++) {
if(s[i] == '0'){
int farmidx=i/K;
own [farmidx]=true;
}
}
int count=0;
for(int f=0;f<F;f++) {
if(!own[f]) count++;
}
cout << count << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;}