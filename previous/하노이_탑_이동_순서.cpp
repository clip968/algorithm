#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
int cnt;
void hanoi(int n, int from, int mid, int end) {
    if(n == 1) {
        cnt++;
        v.push_back({from, end});
        return;
    }

    hanoi(n-1, from, end, mid);
    cnt++;
    v.push_back({from, end});
    hanoi(n-1, mid, from, end);
}

int main() {
    int n; scanf("%d", &n);

    hanoi(n, 1, 2, 3);
    
    printf("%d\n", cnt);
    for(auto k : v) {
        printf("%d %d", k.first, k.second);
        printf("\n");
    }
}