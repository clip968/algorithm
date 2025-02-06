#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> graph[1001];
bool visited[1001];

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        memset(visited, false, n+1);
        for(int i{};i<=n;i++){
            graph[i].clear();
        }

        for(int i{1};i<=n;i++){
            int node, m;
            scanf("%d%d", &node, &m);
            for(int j{};j<m;j++){
                int weight, to;
                scanf("%d%d", &to, &weight);
                graph[node].push_back({weight, to});
                graph[to].push_back({weight, node});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 1});
        int result{};
        while(!pq.empty()){
            int temp_weight = pq.top().first;
            int temp_node = pq.top().second;
            pq.pop();

            if(visited[temp_node] == true) continue;

            visited[temp_node] = true;
            result += temp_weight;

            for(auto k : graph[temp_node]){
                if(visited[k.second] == false){
                    pq.push(k);
                }
            }
        }

        printf("%d\n", result);


    }
}