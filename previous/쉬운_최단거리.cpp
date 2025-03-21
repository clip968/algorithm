#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int result[1001][1001];
bool visited[1001][1001];

struct Point{
    int x, y;
};

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

void clear(int n, int m) {
    for(int i{};i<n;i++){
        for(int j{};j<m;j++){
            visited[i][j] = false;
            result[i][j] = 0;
        }
    }
}

void bfs(Point start_node, int n, int m){
    
    queue<Point> q;
    q.push(start_node);
    visited[start_node.x][start_node.y] = true;
    result[start_node.x][start_node.y] = 0;

    while(!q.empty()) {
        Point curr_node = q.front();
        q.pop();
        
        for(int i{};i<4;i++){
            int nx = curr_node.x + dx[i];
            int ny = curr_node.y + dy[i];
            if(nx >= 0 && ny >= 0 && nx <= n && ny <= m && visited[nx][ny] == false && arr[nx][ny] == 1) {
                visited[nx][ny] = true;
                result[nx][ny] = result[curr_node.x][curr_node.y] + 1;
                q.push({nx, ny});
            }
        }
    }


}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int temp_i, temp_j;
    for(int i{};i<n;i++){
        for(int j{};j<m;j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 2){
                temp_i = i;
                temp_j = j;
            }
        }
    }

    Point start_node = {temp_i, temp_j};
    clear(n, m);
    bfs(start_node, n, m);

    for(int i{};i<n;i++){
        for(int j{};j<m;j++){
            if (arr[i][j] == 1 && visited[i][j] == false){
                result[i][j] = -1;
            }
        }
    }
    

    for(int i{};i<n;i++){
        for(int j{};j<m;j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}