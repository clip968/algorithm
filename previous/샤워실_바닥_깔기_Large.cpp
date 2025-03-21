#include<bits/stdc++.h>
using namespace std;
int board[129][129];
int counter{};

bool check(int x, int y, int size){
    for(int i = y;i<y + size;i++){
        for(int j=x;j<x+size;j++){
            if(board[i][j] != 0) return false;
        }
    }
    return true;
}

void trimino(int size, int x, int y) {
    
    size /= 2;
    counter+=1;
    bool p1 = check(x+size, y, size);
    bool p2 = check(x, y, size);
    bool p3 = check(x, y+size, size);
    bool p4 = check(x+size, y+size, size);

    if(p1) board[y+size-1][x+size] = counter;
    if(p2) board[y+size-1][x+size-1] = counter;
    if(p3) board[y+size][x+size-1] = counter;
    if(p4) board[y+size][x+size] = counter;
    if (size == 1) return;
    trimino(size, x, y);
    trimino(size, x + size, y);
    trimino(size, x, y+size);
    trimino(size, x+size, y+size);


}

int main(){
    counter = 0;
        int size, x, y;
        scanf("%d%d%d", &size, &x, &y);
        size = pow(2, size);
        for(int i=1;i<=size;i++){
            for(int j=1;j<=size;j++){
                board[i][j] = 0;
            }
        }
        // printf("%d", size);
        board[size-y+1][x] = -1;

        trimino(size, 1, 1);

        for(int i=1;i<=size;i++){
            for(int j=1;j<=size;j++){
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

    }
