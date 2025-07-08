#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> visited;
set<int> gay;
bool flag;
void dfs(int node, bool is_gay){
    if(visited[node] == true){
        return;
    }
    visited[node] = true;

    if(gay.count(node)){
        is_gay = true;
    }

    bool is_leaf=true;
    for(auto& k : v[node]){
        if(!visited[k]){
            is_leaf = false;
            dfs(k, is_gay);
        }
    }

    if(!is_gay && is_leaf){
        flag = false;
    }

    visited[node] = false;

    
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    v.resize(n+1);
    visited.resize(n+1);
    flag = true;
    fill(visited.begin(), visited.end(), false);

    for(int i{};i<m;++i){
        int s, e;
        scanf("%d %d", &s, &e);

        v[s].push_back(e);
    }

    int gay_num;
    scanf("%d", &gay_num);

    for(int i{};i<gay_num;++i){
        int tmp; scanf("%d", &tmp);
        gay.insert(tmp);
    }

    dfs(1, false);

    if(flag == false){
        printf("yes\n");
    }
    else{
        printf("Yes\n");
    }
}