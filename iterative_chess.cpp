#include<bits/stdc++.h>
using namespace std;

#define MaxSize 9
#define Mark 1
#define Unmark 0

typedef struct Point {int x, y;} point;
point direction[8] = {{1, -2}, {2, -1}, {2, 1},  {1, 2},
                      {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
int board[MaxSize][MaxSize], path[MaxSize][MaxSize];

bool chk_knight(int y, int x, int m, int n){
    return x >= 0 && x < n && y >= 0 && y < m && board[y][x] != Mark;
}

int warnsdorff(int y, int x, int m, int n){
    int count = 0;
    for(int i = 0; i < 8; i++){
        int nx = x + direction[i].x;
        int ny = y + direction[i].y;
        if(chk_knight(ny, nx, m, n)){
            count += 1;
        }
    }
    return count;
} 

struct Move{
    int y, x;
    vector<int> moves; 
    int move_idx;      
};

int knightTour(int m, int n, point start) {
    stack<Move> s;
    int counter = 1;

   
    vector<pair<int, int>> moving;
    for(int i = 0; i < 8; i++){
        int nx = start.x + direction[i].x;
        int ny = start.y + direction[i].y;
        if(chk_knight(ny, nx, m, n)){
            int temp = warnsdorff(ny, nx, m, n);
            moving.push_back({temp, i});
        }
    }
    sort(moving.begin(), moving.end());
    vector<int> moves;
    int len = moving.size();
    for(auto& p : moving){
        moves.push_back(p.second);
    }

    s.push({start.y, start.x, moves, 0});
    board[start.y][start.x] = Mark;
    path[start.y][start.x] = counter;

    while(!s.empty()){
        Move& current = s.top();

        if(counter == m * n)
            return 1;

        if(current.move_idx < current.moves.size()){
            int dir_idx = current.moves[current.move_idx];
            current.move_idx++;

            int nx = current.x + direction[dir_idx].x;
            int ny = current.y + direction[dir_idx].y;

            if(chk_knight(ny, nx, m, n)){
                counter++;
                board[ny][nx] = Mark;
                path[ny][nx] = counter;

                
                vector<pair<int, int>> next_moving;
                for(int i = 0; i < 8; i++){
                    int nnx = nx + direction[i].x;
                    int nny = ny + direction[i].y;
                    if(chk_knight(nny, nnx, m, n)){
                        int temp = warnsdorff(nny, nnx, m, n);
                        next_moving.push_back({temp, i});
                    }
                }
                sort(next_moving.begin(), next_moving.end());
                vector<int> next_moves;
                int len = next_moving.size();
                for(int i = 0; i < min(2, len); i++){
                    next_moves.push_back(next_moving[i].second);
                }

                s.push({ny, nx, next_moves, 0});
            }
        }
        else{
           
            board[current.y][current.x] = Unmark;
            path[current.y][current.x] = 0;
            counter--;
            s.pop();
        }
    }
    return 0;
}

int main(){
    int m, n, t;
    point start;

    cin >> t;
    while(t--){
        scanf("%d%d%d%d", &m, &n, &start.y, &start.x);
        start.y--; 
        start.x--;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = Unmark;
                path[i][j] = 0;
            }
        }

        int result = knightTour(m, n, start);

        if(result){
            printf("%d\n", result);
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(j == n - 1){
                        printf("%d", path[i][j]);
                    }
                    else{
                        printf("%d ", path[i][j]);
                    }
                }
                cout << "\n";
            }
        }
        else{
            cout << 0 << "\n";
        }
    }
    return 0;
}
