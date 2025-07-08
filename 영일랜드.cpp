#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> v;
int answer{-1};
vector<bool> visited;

void dfs(int now, int cnt, int sum){
    if(now == 0 && cnt == n+1){
        answer = max(sum, answer);
        return;
    }

    for(int i{};i<=n;++i){
        if(v[now][i] == 0) continue;
        if(!visited[i]){
            visited[i] = true;
            dfs(i, cnt+1, sum + v[now][i]);
            visited[i] = false;
        }
    }

}

int main(){
    scanf("%d", &n);
    scanf("%d", &m);

    v.assign(n+1, vector<int>(n+1, 0));
    visited.assign(n+1, false);

    for(int i{};i<m;++i){
        int start, end, dist;
        scanf("%d %d %d", &start, &end, &dist);
        if(start == end) continue;
        v[start][end] = max(v[start][end], dist);
    }

    dfs(0, 0, 0);

    printf("%d", answer);


}