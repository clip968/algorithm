#include<bits/stdc++.h>
using namespace std;
int visited[100001];
vector<int> v[100001];
void dfs(int n) {
    for(int i{};i<v[n].size();i++){
        int next_node = v[n][i];
        if(visited[next_node] == 0){
            visited[next_node] = n; 
            dfs(next_node);
        }
    }
}
int bfs(){
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i{};i<v[node].size();i++){
            int next_node = v[node][i];
            if(visited[next_node] == 0){
                q.push(next_node);
                visited[next_node] = node;
            }
        }
    }
    return 0;
}

int main() {
    int n; scanf("%d", &n);
    int a, b;
    
    

    memset(visited, 0, sizeof(int) * (n+1));

    for(int i{};i<n;i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs();

    for(int i{2};i<=n;i++){
        printf("%d\n", visited[i]);
    }
}


