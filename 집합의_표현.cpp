#include<bits/stdc++.h>
using namespace std;
int parent[1000005];

int find_parent(int x){
    if (x == parent[x]) return x;
    else return find_parent(parent[x]);
}

void union_parent(int x, int y){
    x = find_parent(x);
    y = find_parent(y);

    if(x > y) parent[y] = x;
    else parent[x] = y;
}

void reset_parent(int m){
    for(int i{};i<=m;i++){
        parent[i] = i;
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    
    reset_parent(n);

    for(int i{};i<m;i++){
        int k, a, b;
        scanf("%d%d%d", &k, &a, &b);
        if(k == 0) {
            union_parent(a, b);
        }
        else if(k == 1){
            if (find_parent(a) == find_parent(b)){
                printf("YES\n");
            }
            else printf("NO\n");
        }
    }
}