#include <bits/stdc++.h>
using namespace std;
bool chk;

#define MAXSIZE 9
#define MARK 1
#define UNMARK 0

int board[MAXSIZE][MAXSIZE];
int path[MAXSIZE][MAXSIZE];

typedef struct Point {
    int x, y;
} point;

point directions[8] = {{1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

int knightTour(int m, int n, point pos, int counter) {
    point next;
    if (counter == m * n) {
        return 1;
    }

    for (int i = 0; i < 8; i++) {
        next.x = pos.x + directions[i].x;
        next.y = pos.y + directions[i].y;
        if (
            next.x > 0 && next.x <= n &&
            next.y > 0 && next.y <= m &&
            board[next.y][next.x] != MARK) {
                board[next.y][next.x] = MARK;
                path[next.y][next.x] = counter + 1;
                if (knightTour(m, n, next, counter + 1)) {
                    return 1;
                }
                
                board[next.y][next.x] = UNMARK;
        }
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        point start;
        scanf("%d%d%d%d", &a, &b, &start.y, &start.x);

        // Initialize the board and path arrays
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                board[i][j] = UNMARK;
                path[i][j] = 0;
            }
        }
        chk=false;
        int result = knightTour(a, b, start, 1);

        if (result) {
            for (int i = 1; i <= a; i++) {
                for (int j = 1; j <= b; j++) {
                    printf("%d ", path[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("0\n");
        }
    }

    return 0;
}