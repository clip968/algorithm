#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

vector<Point> v;

int main() {
    int n; scanf("%d", &n);
    int min_x=1e9, min_y=1e9, max_x=-1e9, max_y=-1e9;
    Point temp;
    while(n--){
        scanf("%d %d", &temp.x, &temp.y);
        min_x = min(min_x, temp.x);
        max_x = max(max_x, temp.x);
        min_y = min(min_y, temp.y);
        max_y = max(max_y, temp.y);
    }

    printf("%d", (max_x-min_x) * (max_y-min_y));

    // for(auto k : v) {
    //     printf("%d %d\n", k.x, k.y);
    // }
}