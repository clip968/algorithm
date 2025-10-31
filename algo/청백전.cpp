#include<bits/stdc++.h>
using namespace std;
int parent[2001];
int find_parent(int x) {
    if(parent[x] == x) return x;
    return find_parent(parent[x]);
}

void union_parent(int x, int y){
    int dx = find_parent(x);
    int dy = find_parent(y);
    if(dx > dy){
        parent[dx] = y;
    }
    else{
        parent[dy] = x;
    }
}

int main(){
    int t; scanf("%d", &t);

    while(t--){ 
        int n, m; scanf("%d %d", &n, &m);
        for(int i{};i<=n;++i){
            parent[i] = i;
        }

        vector<int> v;
        for(int i{};i<m;++i){
            int a, b;
            scanf("%d %d", &a, &b);
            // v[a].push_back(b);
            if(find_parent(a) != find_parent(b)){
                union_parent(a, b);
            }
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i{1};i<=n;++i){
            if(pq.empty() == true){
                pq.push(i);
                continue;
            }
            else if(find_parent(pq.top()) == find_parent(i)){
                continue;
            }
            else{
                pq.push(i);
            }
        }
        for(int i{1};i<=n;++i){
            printf("%d\n", parent[i]);
        }
        printf("==========\n");
        // if(pq.size() == (n/2)){
        //     printf("%d\n", pq.size());
        //     printf("1\n");
        // }
        // else{
        //     printf("%d\n", pq.size());
        //     printf("0\n");
        // }
    }
}