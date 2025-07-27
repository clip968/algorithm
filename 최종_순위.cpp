#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; scanf("%d", &t);

    while(t--){
        int n; scanf("%d", &n);
        vector<vector<bool>> v(n+1, vector<bool>(n+1, false));
        vector<int> graph(n+1);
        for(int i{1};i<=n;++i){
            scanf("%d", &graph[i]);
        }

        int m; scanf("%d", &m);
        for(int i{1};i<=n;++i){
            for(int j{i+1};j<=n;++j){
                v[graph[i]][graph[j]] = true;
            }
        }

        vector<int> degree(n+1, 0);
        for(int i{};i<m;++i){
            int a, b;
            scanf("%d %d", &a, &b);
            swap(v[a][b], v[b][a]);
        }

        for(int i{1};i<=n;++i){
            for(int j{1};j<=n;++j){
                if(v[i][j] == true){
                    degree[j]++;
                }
            }
        }

        queue<int> q;
        for(int i{1};i<=n;++i){
            if(degree[i] == 0) q.push(i);
        }

        vector<int> result;
        bool impossible{false};
        bool ambi{false};

        for(int i{};i<n;++i) {
            if(q.empty()) {
                impossible=true;
                break;
            }
            if(q.size()>1) {
                ambi = true;
                break;
            }

            int cur{q.front()};
            q.pop();
            result.push_back(cur);

            for(int i{1};i<=n;++i){
                if(v[cur][i]==true){
                    degree[i]--;

                    if(degree[i] == 0){
                        q.push(i);
                    }
                }

            }
        }
        if(impossible==true) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        else if(ambi==true){
            printf("?\n");
            continue;
        }
        else{
            for(auto& k : result){
                printf("%d ", k);
            }
            printf("\n");
            continue;
        }
    }
}