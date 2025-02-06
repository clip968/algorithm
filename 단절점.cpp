#include<bits/stdc++.h>
using namespace std;
int dist[10001], cut_node[10001];
vector<vector<int>> v;
int curr_length;

int dfs(int current, bool chk_root){
    curr_length += 1;
    dist[current] = curr_length;
    int result = dist[current];
    int child{};
    for(auto k : v[current]){
        if(!dist[k]){
            child++;
            int r = dfs(k, false);
            if(chk_root==false && dist[current] <= r){
                cut_node[current] = true;
            }
            result = min(result, r);
        }
        result = min(result, dist[k]);
    }
    if(chk_root==true && child > 1){
        cut_node[current] = true;
    }

    return result;
}

int main(){
    int a, b, real_result{};
    curr_length = 0;
    scanf("%d%d", &a, &b);
    v.clear();
    v.resize(a+1);
    for(int i{};i<b;i++){
        int from, to;
        scanf("%d%d", &from, &to);
        v[from].push_back(to);
        v[to].push_back(from);
    }

    for(int i{1};i<=a;i++){
        if(!dist[i]){
            dfs(i, true);
        }
    }
    for(int i{1};i<=a;i++){
        if(cut_node[i] == true){
            real_result++;
        }
    }
    printf("%d\n", real_result);
    for(int i{1};i<=a;i++){
        if(cut_node[i]==true){
            printf("%d ", i);
        }
    }
}