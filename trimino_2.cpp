#include<bits/stdc++.h>
using namespace std;
int board[256][256];
int counter{};

bool check(int x, int y, int size){
    for(int i{x};i<x+size;i++){
        for(int j{y};j<y+size;j++){
            if(board[j][i] != -1){
                return false;
            }
        }
    }
    return true;
}

void trimino(int x, int y, int size){
    if(size == 1) return;
    counter++;
    size /= 2;

    bool p1 = check(x+size, y, size);
    bool p2 = check(x, y, size);
    bool p3 = check(x, y+size, size);
    bool p4 = check(x+size, y+size, size);

    if(p1) board[y+size-1][x+size] = counter;
    if(p2) board[y+size-1][x+size-1] = counter;
    if(p3) board[y+size][x+size-1] = counter;
    if(p4) board[y+size][x+size] = counter;

    trimino(x+size, y, size);
    trimino(x+size, y+size, size);
    trimino(x, y+size, size);
    trimino(x, y, size);
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        counter = 0;
        int n{};
        scanf("%d", &n);

        for(int i{};i<n;i++){
            for(int j{};j<n;j++){
                board[i][j] = -1;
            }
        }
        int a, b;
        scanf("%d%d", &a, &b);
        board[a][b] = 0;

        trimino(0, 0, n);

        for(int i{};i<n;i++){
            for(int j{};j<n;j++){
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

    }
}