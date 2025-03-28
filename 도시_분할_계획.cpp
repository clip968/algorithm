#include<bits/stdc++.h>
using namespace std;
int parent[100001];

int find_parent(int x){
    if(parent[x] != x) parent[x] = find_parent(parent[x]);
    return parent[x];
}

void union_parent(int x, int y){
    int parent_x = find_parent(x);
    int parent_y = find_parent(y);

    if(parent_x == parent_y) return;

    if(parent_x < parent_y) {
        parent[parent_y] = parent_x;
    }
    else{
        parent[parent_x] = parent_y;
    }
}

int main(){
    int n, m; scanf("%d %d", &n, &m);
    vector<pair<int, int>> v[n+1];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    // 가중치, {start, end}
    for(int i{1};i<=n;++i){
        parent[i] = i;
    }
    for(int i{1};i<=m;++i){
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        // v[from].push_back({weight, to});
        // v[to].push_back({weight, from});
        pq.push({weight, {from, to}});
        // pq.push({weight, {to, from}});
    }
    int result{};
    int max_weight{};
    while(!pq.empty()){
        int curr_weight = pq.top().first;
        int curr_from = pq.top().second.first;
        int curr_to = pq.top().second.second;
        pq.pop();
        
        if(find_parent(curr_from) != find_parent(curr_to)){
            union_parent(curr_from, curr_to);
            result += curr_weight;
            max_weight = curr_weight;
        }
    }

    printf("%d", result - max_weight);

    return 0;
}