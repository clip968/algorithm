#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v[10001]; //{cost, end}
int dist[10001];

int main(){
    int n, total_length;
    scanf("%d %d", &n, &total_length);
    
    for(int i{};i<=total_length;++i){
        v[i].push_back({1, i+1}); // 기본적으로 다음 노드의 거리는 1
        dist[i] = 1e9;
    }

    for(int i{};i<n;++i){
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        if(end - start < cost || end > total_length) continue; // 애초에 안되는 것들은 걸러서
        v[start].push_back({cost, end});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // {cost, end}
    dist[0] = 0;
    
    while(!pq.empty()){
        // 처음에 {0, 0}
        auto k = pq.top();
        pq.pop();

        if(k.first > dist[k.second]) continue;
        
        for(auto& k2 : v[k.second]){
            pair<int, int> next = {k.first + k2.first, k2.second};

            if(dist[next.second] > next.first) {
                dist[next.second] = next.first;
                pq.push({next.first, next.second});
            }
        }
    }

    printf("%d", dist[total_length]);
    

    // for(auto k : v){
    //     printf("%d %d %d\n", k.start, k.end, k.cost);
    // }

}