#include<bits/stdc++.h>
using namespace std;
int dist[101], cut_node[101];
int length;
int debug, debug_root;
vector<vector<int>> v;  

int dfs(int current_node, int parent, bool chk_root){
    dist[current_node] = length++;
    int child{};
    int result = dist[current_node];
    for(auto k : v[current_node]){
        if (k == parent) continue;
        if(!dist[k]){
            child++;
            int temp = dfs(k, current_node, false);
            if(chk_root==false && temp >= dist[current_node]){
                cut_node[current_node] = true;
                debug++;}
            
                
            result = min(result, temp);
        }
        else result = min(result, dist[k]);
    }

    if(child >= 2 && chk_root == true) {
        cut_node[current_node] = true;
        debug += child-1;
    }
    return result;
}

int main()  {
    int t; scanf("%d", &t);
    while(t--){
        debug = 1;
        vector<int> r;
        int answer{}, answer2{};
        length = 1;
        v.clear();
        int n; scanf("%d", &n);
        v.resize(n+1);
        fill(dist, dist+n+1, 0);
        fill(cut_node, cut_node+n+1, 0);

        for(int i{};i<n;i++){
            int node, num;
            scanf("%d%d", &node, &num);
            for(int j{};j<num;j++){
                int temp; scanf("%d", &temp);
                v[node].push_back(temp);
            }
        }
        for(int i{1};i<=n;i++){
            if(!dist[i]){
                debug_root = 0;
                dfs(i, 0, true);
        }
    }
        for(int i{1};i<=n;i++){
            if(cut_node[i] == true) {
                r.push_back(i);
                answer++;
            }
        }
        if(answer == 0){
            printf("1\n");
        }
        else{
            printf("%d\n", debug);
        }
        
        printf("%d ", answer);
        for(int i{}; i<answer;i++){
            printf("%d ", r[i]);
        }
        // printf("%d\n", debug);
        printf("\n");
        

    }
}