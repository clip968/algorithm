#include<bits/stdc++.h>
using namespace std;
int dist[1001];
int temp[1001];
int main(){
    int t; scanf("%d", &t);
    while(t--){ 
        int result{};
        int m; scanf("%d", &m);
        int n;
        int k; 
        priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;

        vector<vector<pair<int, int>>> v(m+1);
        for(int i{1};i<=m;i++){
            scanf("%d", &n);
            scanf("%d", &k);
            for(int j{};j<k;j++){
                int to, weight;
                scanf("%d%d", &to, &weight);
                v[n].push_back({to, weight});
            }
        }
        // for(int i{1};i<=m;i++){
        //      for(auto& x : v[i]){
        //         printf("%d %d\n", x.first, x.second);
        //      }
        // }
        // printf("----------------------------\n");
       vector<pair<int, int>> result1;
        fill(temp, temp+m+1, -1);
        fill(dist, dist+m+1, INT_MAX);
        dist[1] = 0;
        //첫번째가 길이, 두번째가 노드
        pq.push({0, 1});
        while(!pq.empty()){
            int current_weight = pq.top().first;
            int current_node = pq.top().second;
            pq.pop();

            for(auto& x : v[current_node]){
                int next_node = x.first;
                int next_weight = x.second;

                if(next_weight + dist[current_node] < dist[next_node]){
                    dist[next_node] = next_weight + dist[current_node];
                    temp[next_node] = current_node;
                    pq.push({dist[next_node], next_node});
                }
            }
            
        }
       for(int i{2};i<=m;i++){
        if(temp[i] != -1)
        for(auto& x : v[temp[i]]){
            if(x.first == i){
                result+=x.second;
                break;
            }
        }
       }
        printf("%d\n", result);
    }
}