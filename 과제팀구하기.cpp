#include<bits/stdc++.h>
using namespace std;
int parent[101];

int find_parent(int x){
    if (x == parent[x]) return x;
    else return find_parent(parent[x]); 
}

void union_parent(int a, int b){
    a = find_parent(a);
    b = find_parent(b);

    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main(){
    int t;scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        int arr[n+1];
        int result = 0;
        for(int i=0;i<101;i++) parent[i] = i;
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
            union_parent(i+1, arr[i]);
        }

        for(int i=1;i<=n;i++){
            if(i == find_parent(i)){
                result++;
            }
        }

        printf("%d\n", result);
        
    }
}