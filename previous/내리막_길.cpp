#include<bits/stdc++.h>
using namespace std;
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
vector<vector<int>> v;
vector<vector<int>> dp;

int dfs(int x, int y){
    if(x == n-1 && y == m-1){
        return 1;
    }

    if(dp[x][y] != -1) {
        return dp[x][y];
    }
    dp[x][y] = 0;
    for(int i=0;i<4;++i){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < n && ny < m && (v[nx][ny] < v[x][y])) {
            dp[x][y] += dfs(nx, ny);
        }
    }

    return dp[x][y];
}

int main(){
    scanf("%d%d", &n,&m);
    v.assign(n, vector<int>(m, 0));
    dp.assign(n, vector<int>(m, -1));
    int i, j;
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            scanf("%d", &v[i][j]);
        }
    }

    int ans = dfs(0, 0);

    printf("%d", ans);

    // for(auto k : v) {
    //     for(int s : k) {
    //         printf("%d ", s);
    //     }
    //     printf("\n");
    // }
}