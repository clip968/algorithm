#include<bits/stdc++.h>
using namespace std;
int parent[1001];

int find_parent(int x){
    if(parent[x] == x) return x;
    else{
        return find_parent(parent[x]);
    }
}

void union_parent(int x, int y){
    x = find_parent(x);
    y = find_parent(y);
    if(x < y) {
        parent[y] = x;
    }
    else{
        parent[x] = y;
    }
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        vector<pair<int, pair<int, int>>> v;
        int n; scanf("%d", &n);
        for(int i{1};i<=n;i++){
            int m; scanf("%d", &m);
            int l; scanf("%d", &l);
            for(int j{};j<l;j++){
                int to, weight;
                scanf("%d%d", &to, &weight);
                v.push_back({weight, {i, to}});
            }
        }
        for(int i{};i<=n;i++){
            parent[i] = i;
        }
        
        sort(v.begin(), v.end());
        int result=0;
        for(auto k : v){
            if(find_parent(k.second.first) == find_parent(k.second.second)){
                continue;
            }
            union_parent(k.second.first, k.second.second);
            result += k.first;
        }

        printf("%d\n", result);

    }
}