#include<bits/stdc++.h>
using namespace std;
int n, m, answer=INT_MIN/2;
char arr[50][50]; bool visited[50][50];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
struct Point{
    int x; int y; int cnt;
};

void bfs(int x, int y){
    queue<Point> q;
    q.push({x, y, 0});
    visited[x][y] = true;
    while(!q.empty()){
        Point curr = q.front();
        q.pop();
        int cx = curr.x;
        int cy = curr.y;
        int ccnt = curr.cnt;
        answer = max(answer, ccnt);

        
        for(int i{};i<4;++i){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(visited[nx][ny] == false && nx>=0 && ny>=0 && nx < n && ny < m && arr[nx][ny] == 'L'){
                q.push({nx, ny, ccnt+1});
                visited[nx][ny] = true;
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i{};i<n;++i){
        for(int j{};j<m;++j){
            scanf(" %c", &arr[i][j]);
        }
    }

    for(int i{};i<n;++i){
        for(int j{};j<m;++j){
            if(arr[i][j] == 'L'){
                memset(visited, false, sizeof(visited));
                bfs(i, j);
            }
        }
    }

    printf("%d", answer);


    // for(int i{};i<n;++i){
    //     for(int j{};j<m;++j){
    //         printf("%c", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    


}