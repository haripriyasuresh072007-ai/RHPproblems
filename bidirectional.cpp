#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;
int main() {
int R;
cin>>R;
map<int,vector<pair<int, int>>> g;
 set<int>vis;
    while (R--) {
int src,dest,dist;
        cin>>src>>dest>>dist;
g[src].push_back(make_pair(dest, dist));
g[dest].push_back(make_pair(src, dist));
    }
    int st,end;
 cin>>st>>end;
priority_queue<pair<int, int>,vector<pair<int, int> >,greater<pair<int, int>>> pq;
 pq.push(make_pair(0, st));
    while (!pq.empty()) {
 pair<int,int>current = pq.top();
    pq.pop();
        int currdist = current.first;
int city = current.second;
if (vis.find(city)!=vis.end()) {
            continue;
        }
vis.insert(city);
if (city==end) {
            cout << currdist;
            return 0;
        }
vector<pair<int,int>> neighbours = g[city];
        for (int i=0;i<neighbours.size();i++) {
int oc=neighbours[i].first;
int ocd=neighbours[i].second;
 if (vis.find(oc)==vis.end()) {
                pq.push(make_pair(currdist + ocd, oc));
            }
        }
    }
    cout << "city " << end << " cannot be reached from " << st;

    return 0;
}