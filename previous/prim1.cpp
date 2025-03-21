#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[1001];
vector<vector<pair<int, int>>> graph(1001, vector<pair<int, int>>());
bool visited[1001];

int prim(int start) {
    priority_queue<pair<int, int>, 
                  vector<pair<int, int>>, 
                  greater<pair<int, int>>> pq;
    
    pq.push({0, start}); 
    int result = 0;
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        if(visited[curr]) continue;
        
        visited[curr] = true;
        result += cost;
        
        for(auto next : graph[curr]) {
            if(!visited[next.second]) { 
                pq.push(next);
            }
        }
    }
    return result;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(visited, false, sizeof(visited));
        for(int i = 0; i <= 1000; i++) {
            graph[i].clear();
        }
        
        int m;
        scanf("%d", &m);
        
        for(int i = 0; i < m; i++) {
            int n, k;
            scanf("%d%d", &n, &k);
            for(int j = 0; j < k; j++) {
                int to, weight;
                scanf("%d%d", &to, &weight);
                graph[n].push_back({weight, to});
                graph[to].push_back({weight, n}); 
            }
        }
        
        printf("%d\n", prim(1));
    }
    return 0;
}