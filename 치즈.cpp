#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
int ans{}, ans2{};
struct Pos{
    int x;
    int y;
};
bool visited[101][101];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int bfs(int n, int m){
    queue<Pos> q;
    q.push({0, 0});
    visited[0][0]=true;
    int cnt{};
    ans++;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for(int i{};i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == false){
                if(v[nx][ny] == 0){
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
                else{
                    v[nx][ny] = 0;
                    visited[nx][ny]=true;
                    cnt++;
                }
            }
        }
    }
    if(cnt == 0){
        printf("%d\n%d", ans-1, ans2);
        return 1;
    }
    else{
        ans2 = cnt;
        return 0;
    }
    

    
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    v.assign(n, vector<int>(m));
    for(int i{};i<n;++i){
        for(int j{};j<m;++j){
            scanf("%d", &v[i][j]);
        }
    }

    while(true){
        int cnt = bfs(n, m);
        if(cnt == 1){
            break;
        }
        memset(visited, false, sizeof(visited));
    }

}