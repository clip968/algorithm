#include<bits/stdc++.h>
using namespace std;

#define MaxSize 9
#define Mark 1
#define Unmark 0

typedef struct Point {int x, y;} point;
point direction[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
int board[MaxSize][MaxSize], path[MaxSize][MaxSize];

int knightTour(int m, int n, point pos, int counter) {
    point next;

    if(counter == m * n){
        return 1;
    }

    for(int i=0;i<8;i++){
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;

        if (next.x > 0 && next.x <= n &&
            next.y > 0 && next.y <= m &&
            board[next.y][next.x] != Mark){
                board[next.y][next.x] = Mark;
                path[next.y][next.x] = counter + 1;
                if(knightTour(m, n, next, counter+1)){
                    return 1;
                }
                board[next.y][next.x] = Unmark;
            }
    }

    return 0;
}

int main(){
    int m, n, t;
    point start;

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> m >> n >> start.y >> start.x;

        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                board[i][j] = Unmark;
            }
        }

        board[start.y][start.x] = Mark;
        path[start.y][start.x] = 1;
        int result = knightTour(m, n, start, 1);

        if(result){
            cout << result << "\n";
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    if(j == n){
                        cout << path[i][j];
                    }
                    else{
                        cout << path[i][j] << " ";
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