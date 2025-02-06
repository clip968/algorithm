#include<bits/stdc++.h>
using namespace std;

#define MaxSize 9
#define Mark 1
#define Unmark 0

typedef struct Point {int x, y;} point;
point direction[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
int board[MaxSize][MaxSize], path[MaxSize][MaxSize];

bool chk_knight(int y, int x, int m, int n){
    return x > 0 && x <= n && y > 0 && y <= m && board[y][x] != Mark;
}

int warnsdorff(int y, int x, int m, int n){
    int count = 0;
    for(int i=0;i<8;i++){
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
};

int knightTour(int m, int n, point start) {
    stack<Move> s;
    int counter{1};
    s.push({start.y, start.x});

    while(!s.empty()){
       Move current = s.top();

        if(counter == m * n)
            return 1;

        point Best_move = {-1, -1};
        int min_val = 9;
        for(int i=0;i<8;i++){
            int nx = current.x + direction[i].x;
            int ny = current.y + direction[i].y;
            if(chk_knight(ny, nx, m, n)){
                int next_moves = warnsdorff(ny, nx, m, n);
                if(min_val > next_moves){
                    min_val = next_moves;
                    Best_move = {nx, ny};
                }
            }
        }

        if(Best_move.x != -1){
            counter++;
            board[Best_move.y][Best_move.x] = Mark;
            path[Best_move.y][Best_move.x] = counter;
            s.push({Best_move.y, Best_move.x});
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
        start.y--; start.x--;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                board[i][j] = Unmark;
                path[i][j] = 0;
            }
        }
        board[start.y][start.x] = Mark;
        path[start.y][start.x] = 1;
        
        int result = knightTour(m, n, start);

        if(result){
            printf("%d\n", result);
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    if(j == n){
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

    
}