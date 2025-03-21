#include<bits/stdc++.h>
using namespace std;
int parent[1001];

void reset_parent(){
    for(int i{};i<=1000;i++){
        parent[i] = i;
    }
}

int union_find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = union_find(parent[x]);
}

void union_parent(int x, int y) {
    x = union_find(x);
    y = union_find(y);

    if(x < y) parent[y] = x;
    else parent[x] = y;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){ 
        int result{};
        int m; scanf("%d", &m);
        int n;
        int k; 
        vector<pair<int, pair<int, int>>> v;
        for(int i{};i<m;i++){
            scanf("%d", &n);
            scanf("%d", &k);
            for(int j{};j<k;j++){
                int to, weight;
                scanf("%d%d", &to, &weight);
                v.push_back({weight, {n, to}});
            }
        }
        reset_parent();
        sort(v.begin(), v.end());

        for(auto x : v){
            if(union_find(x.second.first) == union_find(x.second.second)){
                continue;
            }
            union_parent(x.second.first, x.second.second);
            result+=x.first;
        }

        printf("%d\n", result);
        

    }
}