#include<iostream>
#include<algorithm>
#include<iomanip>
#define ll long long int
using namespace std;

struct bus{
    ll lt, rt;
    double time;

    friend bool operator<(bus a, bus b){
        if(a.lt != b.lt)
            return a.lt < b.lt;

        return a.time < b.time;
    }
} buses[200000];

void solve(){
    ll B, P, L, bspeed, pspeed, pos;

    cin >> B >> P >> L >> bspeed >> pspeed;

    for(int i = 0; i < B; i++){
        cin >> buses[i].lt >> buses[i].rt;

        buses[i].time = (double)(buses[i].rt - buses[i].lt) / (double)bspeed
                      + (double)(L - buses[i].rt) / (double)pspeed;
    }

    sort(buses, buses + B);

    for(int i = 0; i < B - 1; i++){
        buses[i + 1].time = min(buses[i + 1].time, buses[i].time);
    }

    double ans;

    for(int ctr = 1; ctr <= P; ctr++){
        cin >> pos;

        ans = (double)(L - pos) / (double)pspeed;

        int bl = 0, br = B;
        bool found = false;

        while(bl < br){
            int mid = (bl + br) / 2;

            if(buses[mid].lt <= pos){
                found = true;

                if(bl == mid)
                    break;

                bl = mid;
            }
            else{
                br = mid;
            }
        }

        if(found){
            ans = min(ans, buses[bl].time);
        }

        cout << ans << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(11);

    int tc = 1;
    while(tc--)
        solve();

    return 0;
}