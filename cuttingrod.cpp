//AtCoder Problem D.Cutting Woods
//Using Binary Search method (c++ is best for binary search)
#include<iostream>
#include<set>
using namespace std;
int main()
{
	int l,q; cin>>l>>q;
	set<int> s;
	s.insert(0); s.insert(l);
	while(q--){
		int qt,x; cin>>qt>>x;
		if(qt==1) s.insert(x);
		else{
			auto it=s.lower_bound(x);
			cout<<*it-*(prev(it))<<endl;
			}
	}
}