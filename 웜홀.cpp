#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

struct Edges{
    int from;
    int to;
    int cost;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int v, e, hole;
        cin >> v >> e >> hole;
        vector<Edges> tmp;

        for(int i{1};i<=v;++i) {
            int from, to, cost;
            cin >> from >> to >> cost;
            tmp.push_back({from, to, cost});
            tmp.push_back({to, from, cost});
        }

        for(int i{};i<hole;++i) {
            int from, to, cost;
            cin >> from >> to >> cost;
            tmp.push_back({from, to, -cost});
        }

        vector<long long> dist(v+1, INF);

        // for(auto k : tmp){
        //     cout << k.from << " " << k.to << " " << k.cost << "\n";
        // }

        int start{1};
        dist[start] = 0;

        for(int i{};i<v-1;++i){
            for(int j{};j<e;++j){
                int from{tmp[j].from};
                int to{tmp[j].to};
                int cost{tmp[j].cost};

                if(dist[from] != INF && dist[to] > dist[from] + cost){
                    dist[to] = dist[from] + cost;
                }
            }
        }

        

    }
}