#include<bits/stdc++.h>
using namespace std;
vector<int> v[2001];
vector<int> color(2001);
bool flag{false};
bool dfs(int curr_node, int curr_color){
    
    color[curr_node] = curr_color;

    for(auto k : v[curr_node]){
        if(color[k] == 0) {
            int next_color = (curr_color == 1) ? 2 : 1;
            if(!dfs(k, next_color)){
                return false;
            }
        }
        else if(color[k] == curr_color){
            return false;
        }
    }
    return true;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        flag = true;
        int n, m;
        scanf("%d %d", &n, &m);
        
        for(int i{};i<=n;++i){
            v[i].clear();
            color[i] = 0;
        }

        for(int i{};i<m;++i){
            int a, b;
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }

        for(int i{1};i<=n;++i){
            if(color[i] == 0){
                if(dfs(i, 1) == false) {
                    flag = false;
                    break;
                }
            }
        }
        printf("%d\n", flag ? 1 : 0);
        
    }
}