#include <bits/stdc++.h>
using namespace std;

// U = 통나무 한 칸 위, D = 통나무 아래로 한 칸
// L = 통나무 왼쪽 한 칸, R = 통나무 오른쪽 한 칸
// T = 통나무 중심점 기준 90도 회전
// 0은 수평, 1은 수직

char arr[50][50];
bool visited[50][50][2];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int ans{};
int n;
struct Pos {
  int x, y, dir, cnt;
};

bool is_this_place_possible(int x, int y, int dir) {
  if (dir == 0) {
    if (y - 1 < 0 || y + 1 >= n)
      return false;
    if (arr[x][y - 1] == '1' || arr[x][y + 1] == '1' || arr[x][y] == '1')
      return false;
  } else {
    if (x - 1 < 0 || x + 1 >= n)
      return false;
    if (arr[x - 1][y] == '1' || arr[x + 1][y] == '1' || arr[x][y] == '1')
      return false;
  }
  return true;
}

bool can_i_turn(int x, int y, int dir) {
  for(int i{-1};i<=1;++i){
    for(int j{-1};j<=1;++j){
      int nx = x + i; int ny = y + j;
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) return false;
      if(arr[nx][ny] == '1') return false;
    }
  }
  return true;
}
  

int main() {
  scanf("%d", &n);
  memset(visited, false, sizeof(visited));
  
  vector<pair<int, int>> start, end;

  for (int i{}; i < n; ++i) {
    for (int j{}; j < n; ++j) {
      scanf(" %c", &arr[i][j]);
      if(arr[i][j] == 'B') {
        start.push_back({i, j});
      }
      if(arr[i][j] == 'E') {
        end.push_back({i, j});
      }
    }
  }

  // 시작 방향(가로, 세로) 찾기
  int start_dir{};
  if(start[0].first == start[1].first) {
    start_dir = 0;
  } else {
    start_dir = 1;
  }
  int end_dir{};
  if(end[0].first == end[1].first) {
    end_dir = 0;
  } else {
    end_dir = 1;
  }

  queue<Pos> q;
  int start_x{start[1].first}, start_y{start[1].second};
  int end_x{end[1].first}, end_y{end[1].second};

  q.push({start_x, start_y, start_dir, 0});
  visited[start_x][start_y][start_dir] = true;
  // bfs 시작
  while(!q.empty()) {
    int cx = q.front().x;
    int cy = q.front().y;
    int cdir = q.front().dir;
    int ccnt = q.front().cnt;
    q.pop();

    if(cx == end_x && cy == end_y && cdir == end_dir) {
      printf("%d\n", ccnt);
      return 0;
    }

    for(int i{};i<4;++i) {
      int nx = cx + dx[i];
      int ny = cy + dy[i];

      if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny][cdir]==true) continue;
      if(!is_this_place_possible(nx, ny, cdir)) continue;

      visited[nx][ny][cdir] = true;
      q.push({nx, ny, cdir, ccnt+1});
    }

    int ndir = 1 - cdir;
    if(can_i_turn(cx, cy, cdir) && is_this_place_possible(cx, cy, ndir) 
    && visited[cx][cy][ndir]==false) {
      visited[cx][cy][ndir] = true;
      q.push({cx, cy, ndir, ccnt+1});
    }


  }
  
  printf("0\n");
  return 0;
  
}