#include<bits/stdc++.h>
using namespace std;
struct Point {
    int x, y;
};

int main() {
    Point a, b, c, d;

    scanf("%d %d", &a.x, &a.y);
    scanf("%d %d", &b.x, &b.y);
    scanf("%d %d", &c.x, &c.y);

    d.x = a.x ^ b.x ^ c.x;
    d.y = a.y ^ b.y ^ c.y;

    printf("%d %d", d.x, d.y);


}