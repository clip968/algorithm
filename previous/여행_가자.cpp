#include<bits/stdc++.h>
using namespace std;
int parent[205];
bool flag = false;
int find_parent(int x){
    if(parent[x] != x) {
        parent[x] = find_parent(parent[x]);
    }

    return parent[x];
}

void union_parent(int x, int y){
    int parent_x = find_parent(x);
    int parent_y = find_parent(y);

    if(parent_x != parent_y) {
        if(parent_x > parent_y) {
            parent[parent_y] = parent_x;
        }
        else {
            parent[parent_x] = parent_y;
        }
    }
}

int main(){
    int n; scanf("%d", &n);
    int m; scanf("%d", &m);
    vector<vector<int>> v(n, vector<int>(n));   
    set<int> travel;
    for(int i=0;i<=n;i++){
        parent[i] = i;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp; scanf("%d", &temp);
            v[i][j] = temp;
            if(v[i][j] == 1) {
                union_parent(i, j);
            }
        }
    }
    for(int i=0;i<m;i++){
        int temp; scanf("%d", &temp);
        travel.insert(temp-1);
    }

    set<int> p;
    for(auto k : travel){
        p.insert(find_parent(k));
    }

    if(p.size() == 1) {
        printf("YES");
    }
    else {
        printf("NO");
    }



    // for(auto k : v) {
    //     for(int i : k) {
    //         printf("%d ", i);
    //     }
    //     printf("\n");
    // }

}