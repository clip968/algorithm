#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
int n, ans{};
bool visited[51][51];
int dx[] = {-1, 0, 1, 0}; // 동1 서3 남2 북0
int dy[] = {0, 1, 0, -1}; // 북0 동1 남2 서3

void bfs(int start_x, int start_y, int curr_dir){
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    int dir{curr_dir};
    ans++;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int idx{};
        bool flag=false;
        for(int i{};i<4;++i){
            if(flag == true){
                break;
            }
            if(dir != 0){
                dir = dir - 1;
            }
            else{
                dir = 3;
            }
            int nx = x + dx[dir];
            int ny = y + dy[dir];
    
            if(!visited[nx][ny] && nx >= 0 && ny >= 0 && nx < n && ny < n && v[nx][ny] == 0){
                visited[nx][ny] = true;
                q.push({nx, ny});
                flag = true;
                ans++;
            }
        }
        
        int tmp{};
        if(dir == 0){
            tmp = 2;
        }
        else if(dir == 1){
            tmp = 3;
        }
        else{
            tmp = dir - 2;
        }
        // printf("x=%d, y=%d, tmp=%d, dx[tmp]=%d, dy[tmp]=%d, dir=%d\n", x, y, tmp, dx[tmp], dy[tmp], dir);
        // printf("v[%d][%d]=%d, flag=%d, dir=%d\n", x+dx[tmp], y+dy[tmp], v[x+dx[tmp]][y+dy[tmp]], flag, dir);
        // if(v[x+dx[tmp]][y+dy[tmp]]==1 && flag == false){
        //     printf("%d\n", ans);
        //     return; 
        // }
        
    }

}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int dir;
        scanf("%d %d", &n, &dir);
        int start_x, start_y;
        scanf("%d %d", &start_x, &start_y);
        // int arr[n][n];
        v = vector<vector<int>>(n, vector<int>(n));
        for(int i{};i<n;++i){
            for(int j{};j<n;++j){
                scanf("%d", &v[i][j]);
            }
        }
        ans=0;
        memset(visited, false, sizeof(visited));
        bfs(start_x, start_y, dir);
        printf("%d\n", ans);
        // printf("=================\n");
    }
}