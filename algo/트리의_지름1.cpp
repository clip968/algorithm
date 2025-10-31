#include<bits/stdc++.h>
using namespace std;
int result;
int max_dist=0;
int end_point = 1;
vector<pair<int, int>> v[100001];

void max_length_dfs(int node, int dist, vector<bool>& visited){
    visited[node] = true;
    if(dist > max_dist) {
        max_dist = dist;
        end_point = node;
    }

    for(auto k : v[node]) {
        if(!visited[k.first]) {
            max_length_dfs(k.first, dist + k.second, visited);
        }
    }
}
int main(){
    int n; scanf("%d", &n);
    for(int i{};i<n;i++){
        int node, next_node, length;
        scanf("%d%d%d", &node, &next_node, &length);
        v[node].push_back({next_node, length});
        v[next_node].push_back({node, length});
    }

    vector<bool> visited(n+1, false);
    // for(auto k : v){
    //     for(auto l : k){
    //         printf("%d %d\n", l.first, l.second);
    //     }
    // 

    max_length_dfs(1,0, visited);

    max_dist = 0;
    fill(visited.begin(), visited.end(), false);
    max_length_dfs(end_point, 0, visited);

    printf("%d", max_dist);
}

