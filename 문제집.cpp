#include<bits/stdc++.h>
using namespace std;

vector<int> degree;
vector<vector<int>> graph;
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> result;

void f(int n){
    for(int i{1};i<=n;++i){
        if(degree[i] == 0) pq.push(i);
    }

    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        result.push_back(cur);

        for(int i{};i<graph[cur].size();++i){
            int next{graph[cur][i]};
            degree[next]--;

            if(degree[next]==0){
                pq.push(next);
            }
        }
    }

    if(result.size() == n) {
        for(auto& k : result){
            printf("%d ", k);
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    degree = vector<int>(n+1);
    graph = vector<vector<int>>(n+1);

    for(int i{};i<m;++i){
        int from, to;
        scanf("%d %d", &from, &to);

        graph[from].push_back(to);
        degree[to]++;
    }

    f(n);
    return 0;
}