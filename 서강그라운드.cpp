#include<bits/stdc++.h>
using namespace std;
vector<int> items;
int ans{};
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;
    items.push_back(0);
    for(int i{};i<n;++i){
        int tmp;
        cin >> tmp;
        items.push_back(tmp);
    }

    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    for(int i{1}; i<=n;++i) {
        dist[i][i]=0;
    }

    for(int i{};i<r;++i) {
        int from, to, cost;
        cin >> from >> to >> cost;

        dist[from][to] = min(dist[from][to], cost);
        dist[to][from] = min(dist[to][from], cost);
    }

    for (int k{1};k<=n;++k) {
        for(int i{1};i<=n;++i) {
            for(int j{1};j<=n;++j) {
                if(dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    // dijk(edges, 1, r);

    // for(int i{1};i<dist.size();++i) {
    //     cout << dist[i] << " ";
    // }
    // cout << "\n";
    // for(int i{1};i<dist.size();++i) {
    //     cout << items[i] << " ";
    // }

    for(int i{1};i<=n;++i){
        int tmp{};
        for(int j{1};j<=n;++j) {
            if(dist[i][j] <= m) {
                tmp += items[j];
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << "\n";

}