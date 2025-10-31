#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v[100001];


int main(){
    int n; scanf("%d", &n);

    while(n--){
        int node; scanf("%d", &node);
        int next_node, weight, dummy;
        scanf("%d%d", &next_node, &weight);
        v[node].push_back({next_node, weight});
        
    }
}